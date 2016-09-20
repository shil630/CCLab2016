var line ='';

function loadLocation(currentLine){
  
  $.each(currentLine,function(value){
    var location = currentLine[value].name
    console.log(location);
     
  $("#currentLocation").append(
    '<li>' +location+'</li>')

  });
  
}

function getLocation(){
      $.ajax({
        url: "https://data.cityofnewyork.us/resource/he7q-3hwy.json?line="+line,
        type: "GET",
        data: {
        "$limit" : 5000,
        "$$app_token" : "kNFGccpI4dK5ZvbWykA3B7sAu"
        },

        success:function(data){
         console.log(data);
         loadLocation(data);
         }
         });

}

function setLine() {
  line = $('#currentLine').val();
  if(line == null || line =='' ){
    alert('You need to choose a line');
  }
  getLocation();
}

function init(){
	console.log("Hello");
  $('#submit').click(function(e){
    e.preventDefault();
    setLine();
  });




};


$(document).ready(function(){
	console.log("document ready");
	init();
});