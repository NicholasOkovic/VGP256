using System.Collections;
using System.Collections.Generic;
using Unity.Mathematics;
using UnityEngine;
using UnityEngine.UIElements;

public class MeshGenerator : MonoBehaviour
{
    enum NoiseTypes
    {
        Perlin,
        Gaussian
    };

    [SerializeField]
    NoiseTypes noiseType = new NoiseTypes();

    [SerializeField]
    private int _width = 20;

    [SerializeField]
    private int _length = 20;

    [SerializeField]
    [Range(0f, 0.99f)]
    private float _spikeFrequency;

    [SerializeField]
    [Range(0f, 10f)]
    private float _noiseHeightMultiplier;

    Mesh _mesh;

    Vector3[] _vertices;
    int[] _triangles;

    Color[] _colors;
    [SerializeField]
    private Gradient _gradient;

    float minTerrainHeight;
    float maxTerrainHeight;

    Custom_Noise tNoise;

    void Start()
    {
        tNoise = new Custom_Noise();

        _mesh = new Mesh();
        GetComponent<MeshFilter>().mesh = _mesh;
    }

    private void Update()
    {
        UpdateMesh();
        if (Input.GetKeyDown(KeyCode.L))
        {
            StartCoroutine(CreateShape());
        }
    }

    IEnumerator CreateShape()
    {
        _vertices = new Vector3[(_width + 1) * (_length + 1)];
        _triangles = new int[_width * _length * 6];
        _colors = new Color[_vertices.Length];

        switch (noiseType)
        {
            case NoiseTypes.Perlin:
                PerlinCreateShapes();
                break;
            case NoiseTypes.Gaussian:
                GaussianCreateShapes();
                break;
            default:
                break;
        }
        yield return new WaitForSeconds(1f); //for dramatic effect

        int vert = 0;
        int tris = 0;

        //creates triangles between verts
        for (int l = 0; l < _length; l++)
        {
            for (int w = 0; w < _width; w++)
            {
                _triangles[tris + 0] = vert + 0;
                _triangles[tris + 1] = vert + _width + 1;
                _triangles[tris + 2] = vert + 1;
                _triangles[tris + 3] = vert + 1;
                _triangles[tris + 4] = vert + _width + 1;
                _triangles[tris + 5] = vert + _width + 2;

                vert++;
                tris += 6;
                //creates one quad
            }
            vert++;     //added to fix bug with triangles being made with next line
            yield return new WaitForSeconds(0.01f);
        }

        // COOOL COLORS!!!!

        int c = 0;

        for (int l = 0; l <= _length; l++)
        {
            for (int w = 0; w <= _width; w++)
            {
                float height = Mathf.InverseLerp(minTerrainHeight, maxTerrainHeight, _vertices[c].y);
                _colors[c] = _gradient.Evaluate(height);
                c++;
            }
        }
    }

    void PerlinCreateShapes()
    {
        int i = 0;
        for (int l = 0; l <= _length; l++)
        {
            for (int w = 0; w <= _width; w++)
            {
                float h = Mathf.PerlinNoise(l * _spikeFrequency, w * _spikeFrequency) * _noiseHeightMultiplier; 

                _vertices[i] = new Vector3(w, h, l);

                if (h > maxTerrainHeight) //searches for the min and max height
                {
                    maxTerrainHeight = h;
                }
                if (h < minTerrainHeight)
                {
                    minTerrainHeight = h;
                }
                i++;
            }
        }
    }
    void GaussianCreateShapes()
    {
        int i = 0;
        for (int l = 0; l <= _length; l++)
        {
            for (int w = 0; w <= _width; w++)
            {
                float h = tNoise.GaussianNoise(l * _spikeFrequency, w * _spikeFrequency) * _noiseHeightMultiplier;

                _vertices[i] = new Vector3(w, h, l);

                if (h > maxTerrainHeight) //searches for the min and max height
                {
                    maxTerrainHeight = h;
                }
                if (h < minTerrainHeight)
                {
                    minTerrainHeight = h;
                }
                i++;
            }
        }
    }

    void UpdateMesh()
    {
        _mesh.Clear();

        _mesh.vertices = _vertices;
        _mesh.triangles = _triangles;
        _mesh.colors = _colors;

        _mesh.RecalculateNormals();
        //just makes the lighting of the meshes look better
    }

    private void OnDrawGizmos() //debugging verts
    {
        if (_vertices != null)
        {
            for (int i = 0; i < _vertices.Length; i++)
            {
                Gizmos.DrawSphere(_vertices[i], 0.1f);
            }
        }
    }


}
