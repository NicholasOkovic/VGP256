using System;
using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;

public class Doors : MonoBehaviour
{
    PlayerControls playerControls;

    //binary key
    [SerializeField] private int BKey;
    [SerializeField] private TextMeshProUGUI BKey_txt;
    //text on the door

    void Start()
    {
        BKey_txt.text = Convert.ToString(BKey, 2).PadLeft(3, '0');
    }

    public void DoorCheck(Object player, Object wall)
    {
        playerControls = player.GetComponent<PlayerControls>();
        if (Text_Manager.instance.PlayerBKey != BKey)
        {
            playerControls.ReverseTranslation(wall);
        }
    }
}
