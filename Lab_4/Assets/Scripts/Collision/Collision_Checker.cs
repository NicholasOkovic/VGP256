using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class Collision_Checker : MonoBehaviour
{
    //find out what is colliding with what
    public bool IsColliding(Object ob1, Object ob2)
    {
        // circle to circle
        if (ob1 is Circle_Object && ob2 is Circle_Object)
        {
            return IsColliding((Circle_Object)ob1, (Circle_Object)ob2);
        }
        // circle to AABB
        else if (ob1 is Circle_Object && ob2 is Rectangle_Object)
        {
            return IsColliding((Circle_Object)ob1, (Rectangle_Object)ob2);
        }
        //AABB to circle
        else if (ob1 is Rectangle_Object && ob2 is Circle_Object)
        {
            return IsColliding((Rectangle_Object)ob1, (Circle_Object)ob2);
        }
        return false;
    }

    //Circle & Circle
    public bool IsColliding(Circle_Object ob1, Circle_Object ob2)
    {
        //checks if they're colliding
        if((((ob1.Position.x - ob2.Position.x) * (ob1.Position.x - ob2.Position.x)) + ((ob1.Position.y - ob2.Position.y) * (ob1.Position.y - ob2.Position.y))) <= (ob2.radius + ob1.radius))
        {
            Debug.Log("true");
            return true;
        }

        return false;
    }

    public bool IsColliding(Circle_Object ob1, Rectangle_Object ob2)
    {
        Vector2 circleDistance = new Vector2(Mathf.Abs(ob1.Position.x - ob2.Position.x), Mathf.Abs(ob1.Position.y - ob2.Position.y));

        if (circleDistance.x > (ob2.WidthMax/2 + ob1.radius) || circleDistance.y > (ob2.HeightMax / 2 + ob1.radius))
        {
            return false;
        }
        if (circleDistance.x <= (ob2.WidthMax/2) || circleDistance.y <= (ob2.HeightMax/2))
        {
            return true;
        }

        float cornerDistance = (Mathf.Pow((circleDistance.x - ob2.WidthMax / 2), 2) + Mathf.Pow((circleDistance.y - ob2.HeightMax / 2),2));

        return cornerDistance <= Mathf.Pow(ob1.radius, 2);
    }
    
    public bool IsColliding(Rectangle_Object ob1, Circle_Object ob2)
    {
        Vector2 circleDistance = new Vector2(Mathf.Abs(ob2.Position.x - ob1.Position.x), Mathf.Abs(ob2.Position.y - ob1.Position.y));

        if (circleDistance.x > (ob1.WidthMax / 2 + ob2.radius) || circleDistance.y > (ob1.HeightMax / 2 + ob2.radius))
        {
            return false;
        }
        if (circleDistance.x <= (ob1.WidthMax / 2) || circleDistance.y <= (ob1.HeightMax / 2))
        {
            return true;
        }

        float cornerDistance = Mathf.Pow(circleDistance.x - ob1.WidthMax / 2, 2) + Mathf.Pow(circleDistance.y - ob1.HeightMax / 2, 2);

        return cornerDistance <= Mathf.Pow(ob2.radius, 2);
    }

}
