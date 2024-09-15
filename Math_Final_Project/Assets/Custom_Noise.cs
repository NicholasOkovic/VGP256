using System.Collections;
using System.Collections.Generic;
using Unity.Mathematics;
using UnityEngine;
using UnityEngine.UIElements;


public class Custom_Noise : MonoBehaviour
{
    public float GaussianNoise(float l, float w)    //Box Muller formula 
    {
        System.Random rand = new System.Random();
        
        double x1 = 1 - rand.NextDouble();
        double x2 = 1 - rand.NextDouble();

        float y1 = Mathf.Sqrt(-2.0f * Mathf.Log((float)x1)) * Mathf.Cos(2.0f * Mathf.PI * (float)x2);
        return (y1 * w + l) / 100; //added deviding by 100 to be more in line with perlin
    }
}
