using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Obstacles : MonoBehaviour
{

    PlayerControls playerControls;

    //used to stop the player from running through walls
    public void HitWall(Object player, Object wall)
    {
        playerControls = player.GetComponent<PlayerControls>();

        playerControls.ReverseTranslation(wall);
    }

}
