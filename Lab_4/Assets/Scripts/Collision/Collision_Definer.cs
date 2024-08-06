using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Collision_Definer : MonoBehaviour
{
    Coins coin;
    Keys key;
    Obstacles obstacle;
    Doors door;

    //define what collision happened to the player, based on the tag. AND switch statements because they are cool
    public void CollisionDefine(Object ob1, Object ob2)
    {
        switch (ob1.tag)
        {
            case ("Coin"):
                coin = ob1.GetComponent<Coins>();
                coin.CoinGather();
                return;
            case ("Obstacle"):
                obstacle = ob1.GetComponent<Obstacles>();
                obstacle.HitWall(ob2, ob1);
                return;
            case ("Door"):
                door = ob1.GetComponent<Doors>();
                door.DoorCheck(ob2, ob1);
                return;
            case ("Key"):
                key = ob1.GetComponent<Keys>();
                key.KeyGather();
                return;
            default:
                break;
        }

        switch (ob2.tag)
        {
            case ("Coin"):
                coin = ob2.GetComponent<Coins>();
                coin.CoinGather();
                return;
            case ("Obstacle"):
                obstacle = ob2.GetComponent<Obstacles>();
                obstacle.HitWall(ob1, ob2);
                return;
            case ("Door"):
                door = ob2.GetComponent<Doors>();
                door.DoorCheck(ob1, ob2);
                return;
            case ("Key"):
                key = ob2.GetComponent<Keys>();
                key.KeyGather();
                return;
            default:
                break;
        }


    }

}
