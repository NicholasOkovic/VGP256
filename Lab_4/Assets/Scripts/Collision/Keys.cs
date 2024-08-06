using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Keys : MonoBehaviour
{

    Circle_Object circle;
    //use the TypeOfKey to determine the type of door it unlocks
    [SerializeField] int TypeOfKey;

    //calls when on collision enter
    public void KeyGather()
    {
        Text_Manager.instance.AddKey(TypeOfKey);
        circle = gameObject.GetComponent<Circle_Object>();
        circle.RemoveObjectColliderFromManager();
        Destroy(gameObject);
    }

}
