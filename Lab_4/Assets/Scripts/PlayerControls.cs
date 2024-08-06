using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerControls : MonoBehaviour
{
    //for the sprites
    public Animator animator;
    private SpriteRenderer sprite;

    //inputs for movements
    [SerializeField] private float _speed = 5.0f;
    float horizontalInput;
    float verticalInput;
    Vector3 direction;


    void Start()
    {
        sprite = GetComponent<SpriteRenderer>();
    }


    void Update()
    {
        horizontalInput = Input.GetAxis("Horizontal");
        verticalInput = Input.GetAxis("Vertical");

        animator.SetFloat("Speed", Mathf.Abs(horizontalInput) + Mathf.Abs(verticalInput));

        direction = new Vector3(horizontalInput, verticalInput);

        //flip the sprite depending on which direction youre moving
        if (direction.x < 0)
        {
            sprite.flipX = true;
        }
        else if (direction.x > 0)
        {
            sprite.flipX = false;
        }
        transform.Translate(direction * Time.deltaTime * _speed);

        //toss out your keys
        if (Input.GetKeyDown(KeyCode.T))
        {
            Text_Manager.instance.TossKey();
        }

    }

    //blocks the player from passing through walls
    public void ReverseTranslation(Object wall)
    {
        if (horizontalInput > 0 && transform.position.x < wall.Position.x) 
        {
            transform.Translate((-direction.x * Time.deltaTime * _speed), 0, 0);
        }
        else if (horizontalInput < 0 && transform.position.x > wall.Position.x)
        {
            transform.Translate((-direction.x * Time.deltaTime * _speed), 0, 0);
        }

        if (verticalInput > 0 && transform.position.y < wall.Position.y)
        {
            transform.Translate(0, (-direction.y * Time.deltaTime * _speed), 0);
        }
        else if (verticalInput < 0 && transform.position.y > wall.Position.y)
        {
            transform.Translate(0, (-direction.y * Time.deltaTime * _speed), 0);
        }

    }


}
