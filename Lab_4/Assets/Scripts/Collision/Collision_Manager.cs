using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class Collision_Manager : MonoBehaviour
{
    //used for managing all the collision in the game

    public static Collision_Manager instance;

    public List<Object> objects;
    public Object[] aObjects;

    private int iterA;
    private int iterB;

    bool Collision = false;

    private Collision_Checker checker;
    private Collision_Definer definer;

    void Start()
    {
        if (instance == null)
        {
            instance = this;
            DontDestroyOnLoad(this.gameObject);
        }
        else
        {
            Destroy(gameObject);
        }
        objects = new List<Object>();
        checker = new Collision_Checker();
        definer = new Collision_Definer();


        //collect the colliders and store them in a list to better keep track
        CollectColliders();
    }

    

    void Update()
    {

        for (iterA = 0; iterA < objects.Count; iterA++)
        {
            for (iterB = iterA + 1; iterB < objects.Count; iterB++)
            { 
                if (Collision = checker.IsColliding(objects[iterA], objects[iterB]))
                {
                    if (objects[iterA].CompareTag("Player") || objects[iterB].CompareTag("Player"))
                    {
                        //find what collision is happeing to the player
                        definer.CollisionDefine(objects[iterA], objects[iterB]);
                    }
                }
            }
        }
    }

    public void AddCollider(Object obj)
    {
        objects.Add(obj);
    }
    public void RemoveCollider(Object obj)
    {
        objects.Remove(obj);
    }

    //one of the troubles I faces(that I will probably talk about) is that
    //when setting up the colliders for the game, my list refused to go over 4 items.
    //So I had to find all the objects after initializing them, so I could store them into
    //A list, I prefere lists to arrays, so I swap the contents of the array for my list
    void CollectColliders()
    {
        aObjects = FindObjectsOfType<Object>();

        for (int i = 0; i < aObjects.Length; i++)
        {
            objects.Add(aObjects[i]);
        }


    }


}



