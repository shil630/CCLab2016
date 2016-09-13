// variables
var replies = ["yes", "no", "How should I know?", "Feed me then I'll tell you","Maaaaybe."];
var sound = ["yes", "no", "how", "feedme", "maybe"];
var eyes = ["eyes", "eyes2", "eyes3", "eyes4","eyes5", "eyes6","eyes7"];
var randomNum = 0;
var randomEyes = 0;
var audioElement;

// play sounds function
function playSounds(r) {
	audioElement.setAttribute('src', 'assets/sound/'+ sound[r]+'.mp3');
	audioElement.play();

}

// generate random number
function randomNumGenerator(arrayName) {
	return Math.floor(Math.random() * arrayName.length); //say math.ramdom = 0.1 * arraylength(0.5);
	// Math.random generates a random value between (0,1);
	// replies.length = 4;
	// Math.floor returns a number representing the largest integer less than or equal to the specified number
}

// answer question function
function answerQuestion(){
	randomNum = randomNumGenerator(replies);
	console.log("Random Reply Num" + randomNum);

	// venilla js: document.getElementById('speech').textContent = replies[randomNum];
	$("#speech").text(replies[randomNum]);

    //call play sound function
	playSounds(randomNum);

	randomEyes = randomNumGenerator(eyes);
	$("#eyes").css('background', 'url("assets/img/'+ eyes[randomEyes] + '.png") no-repeat');
	$("#eyes").css('background-size', "100% auto");
}

//init function
function init(){
	console.log("Hello World");

	// create element with vanilla js
	audioElement = document.createElement('audio'); // create <audio></audio>
	audioElement.setAttribute('autoplay','autoplay');// generate <audio autoplay></audio>


	// var submit = document.getElementById('submit');
	//submit.addEventlistner("click", function(){
    // answerQuestion();
	//});


	$("#submit").click(function(){
		answerQuestion();
	});

}

// load init function on load
$(document).ready(function(){
	init();

});