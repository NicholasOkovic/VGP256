using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Circle_Object : Object
{
    private float Radius;
    public float radius { get; private set; }


    void Start()
    {
        //get the circles radius and position
        Position = transform.position;
        SpriteRenderer sprite = GetComponent<SpriteRenderer>();

        Scale = transform.localScale;
        radius = sprite.sprite.bounds.max.x;
        Radius = radius;
    }


    void Update()
    {
        Position = transform.position;
    }

    public override void DrawShape()
    {
        Gizmos.color = Color.blue;
        Gizmos.DrawSphere(Position, Radius * Scale.x);
    }
    //Used for adding and removing objects from the collision list
    public override void AddObjectColliderToManager()
    {
        Collision_Manager.instance.AddCollider(this);
    }
    public override void RemoveObjectColliderFromManager()
    {
        Collision_Manager.instance.RemoveCollider(this);
    }

    private void OnDrawGizmosSelected()
    {
       DrawShape();
    }
}
