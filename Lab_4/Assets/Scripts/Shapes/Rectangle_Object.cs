using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class Rectangle_Object : Object
{

    public float WidthMax     {  get; private set; }
    public float WidthMin      { get; private set; }
    public float HeightMax    { get; private set; }
    public float HeightMin     { get; private set; }




    void Start()
    {
       
        Position = transform.position;
        Scale = transform.localScale;

        SpriteRenderer sprite = GetComponent<SpriteRenderer>();

        //bounds of the object, multiplying 1.75 made the collision more seamless
        WidthMax = sprite.sprite.bounds.max.x * Scale.x * 1.75f;
        WidthMin = sprite.sprite.bounds.min.x * Scale.x;
        HeightMax = sprite.sprite.bounds.max.y * Scale.y * 1.75f;
        HeightMin = sprite.sprite.bounds.min.y * Scale.y * 1.75f;

    }


    void Update()
    {
        Position = transform.position;
    }

    public override void DrawShape()
    {
        //However increasing those bounds mess with the Gizmos I had set up for debugging
        Gizmos.color = Color.green;
        Gizmos.DrawLine(Position + (new Vector2(WidthMax, HeightMax) ), Position + (new Vector2(WidthMax, HeightMin)));
        Gizmos.DrawLine(Position + (new Vector2(WidthMax, HeightMin) ), Position + (new Vector2(WidthMin, HeightMin)));
        Gizmos.DrawLine(Position + (new Vector2(WidthMin, HeightMax) ), Position + (new Vector2(WidthMax, HeightMax)));
        Gizmos.DrawLine(Position + (new Vector2(WidthMin, HeightMin) ), Position + (new Vector2(WidthMin, HeightMax)));
    }

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
