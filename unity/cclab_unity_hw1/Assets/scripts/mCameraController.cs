using UnityEngine;
using System.Collections;

public class mCameraController : MonoBehaviour {
	
	public GameObject player;
	private Vector3 offset;

	// Use this for initialization
	void Start () {
		offset = transform.position - player.transform.position;
	
	}

	// folloe Cameras, Procedural Animations, etc.
	// LateUpdate, runs after all items have been processed

	void LateUpdate () {
		transform.position = player.transform.position + offset;
	}
}
