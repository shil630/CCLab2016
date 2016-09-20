// hold variables
var city = '';
var state = '';
var APIkey = '8b0f7398a2f1f8e1';




// insert all the data into the divs
function loadWeather(data) {
	console.log(data);

	if (data.response.error) {
		alert(data.response.error.description); //to access the object inside of it, you use .
		return;
	}

	var thisCity = data.current_observation.display_location.city;
	var temperature = data.current_observation.temp_c;
	var weather = data.current_observation.weather;
	var icon = data.current_observation.icon_url;

	// console.log(weather);
    $("#temperature").html(temperature);
    $("#weather").html(weather);
    $("#weatherIcon").html('<img src = " '+icon +'">');

    if (thisCity == "New York") {
    	$("#currentCity").val("Fantastic City!");
    }else{
    	$("#currentCity").val("This city sucks");
    }
    

}

// get city 
// get weather data
function getWeather() {
	var myUrl = "http://api.wunderground.com/api/" + APIkey + "/conditions/q/" + state + "/" + city + ".json";

	$.ajax({
		url: myUrl,
		dataType: "jsonp",

		success: function(response) {
			console.log(response);
			loadWeather(response);
		},

		error: function(response){
			alert('Try again.');
		},
	});


}


// pass city/stete data when submit is clicked
function setLocation(){
	city = $('#currentCity').val(); // get value from currentCity input
	state = $('#currentState').val(); // get value from currentState input

	if(city == null || city == ''){
		alert('You need to choose a city');
	}

	console.log("Getting weather for:" + city + "," + state);
    getWeather();

}

//init
function init(){
	console.log("hello");

	$('#submit').click(function(e){
        e.preventDefault();
        setLocation();
	});
}

// run on load
$(document).ready(function(){
	init();
});