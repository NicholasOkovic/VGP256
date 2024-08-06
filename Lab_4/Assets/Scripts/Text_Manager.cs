using System;
using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;

public class Text_Manager : MonoBehaviour
{
    //managing the UI, keys and coins

    [SerializeField] private TextMeshProUGUI coins_txt;
    [SerializeField] private TextMeshProUGUI bKey_txt;

    private int coins = 0;
    public int PlayerBKey = 0;

    public static Text_Manager instance;


    void Start()
    {
        if (instance == null)
        {
            instance = this;
            DontDestroyOnLoad(this.gameObject);
        }
        coins_txt.text = "Coins: " + coins.ToString();
        bKey_txt.text = Convert.ToString(PlayerBKey, 2).PadLeft(3, '0');
    }
    //incrementing coins and then updating the text(so I dont have to update text every frame)
    public void AddCoin()
    {
        coins++;
        coins_txt.text = "Coins: " + coins.ToString();
    }
    //adding key to the players inventory
    public void AddKey(int key)
    {
        PlayerBKey |= key;
        bKey_txt.text = Convert.ToString(PlayerBKey, 2).PadLeft(3, '0');
    }
    //toss the keys so you are able to progress to the next room
    public void TossKey()
    {
        PlayerBKey &= 0;
        bKey_txt.text = Convert.ToString(PlayerBKey, 2).PadLeft(3, '0');
    }


}
