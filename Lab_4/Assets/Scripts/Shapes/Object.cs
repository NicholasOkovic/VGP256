using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public abstract class Object : MonoBehaviour
{
    //abstract class for objects with collision
    public Vector2 Position { get; protected set; }
    public Vector2 Scale { get; protected set; }




    abstract public void DrawShape();
    abstract public void AddObjectColliderToManager();
    abstract public void RemoveObjectColliderFromManager();
}
