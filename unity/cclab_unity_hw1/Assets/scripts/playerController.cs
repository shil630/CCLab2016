using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class playerController : MonoBehaviour {

	public float speed;
	public Text scoreText;
	public Text winText;

	private Rigidbody rb;
	private int score;

	// Use this for initialization
	void Start () {
		rb = GetComponent<Rigidbody> ();
		score = 0;
		setScoreText ();
		winText.text = "";
	
	}

	void FixedUpdate () {
		float moveHorizontal = Input.GetAxis ("Horizontal");
		float moveVertical = Input.GetAxis ("Vertical");

		Vector3 movement = new Vector3 (moveHorizontal, 0.0f, moveVertical);

		rb.AddForce (movement * speed);

	}

	void OnTriggerEnter(Collider other) {
		if (other.gameObject.CompareTag("Pick Up")) {
			other.gameObject.SetActive (false);	
			score += 10;
			setScoreText ();
		}
	}

	void setScoreText () {
		scoreText.text = "score:" + score.ToString ();

		if(score >= 200) {
			winText.text = "You Win!";
		}

	}
}
