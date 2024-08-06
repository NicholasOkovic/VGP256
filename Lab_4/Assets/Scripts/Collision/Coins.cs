using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Coins : MonoBehaviour
{
    Circle_Object circle;

    //calls when on collision enter
    public void CoinGather()
    {
        Text_Manager.instance.AddCoin();
        circle = gameObject.GetComponent<Circle_Object>();
        circle.RemoveObjectColliderFromManager();
        Destroy(gameObject);
    }

}
