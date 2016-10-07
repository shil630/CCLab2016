import processing.serial.*;
import cc.arduino.*;
import org.firmata.*;

Arduino arduino;


int[] values = { Arduino.LOW, Arduino.LOW, Arduino.LOW, Arduino.LOW,
 Arduino.LOW, Arduino.LOW, Arduino.LOW, Arduino.LOW, Arduino.LOW,
 Arduino.LOW, Arduino.LOW, Arduino.LOW, Arduino.LOW, Arduino.LOW };


void setup(){
  arduino = new Arduino(this, Arduino.list()[1], 57600);
  
  for (int i = 0; i <= 13; i++) {
    arduino.pinMode(i, Arduino.OUTPUT);
  }
    
  size(380,160);
 
}

void draw(){
  
  //for (int i = 0; i<3; i++) {
    
  //  noFill();
  //  ellipse(310 - 120*i, 80, 100, 100);
  
  //}
  
  fill(255,0,0);
  ellipse(70, 80, 100,100);
  
  fill(0,255,0);
  ellipse(190, 80, 100,100);
  
  fill(0,0,255);
  ellipse(310, 80, 100,100);
  
}

void mousePressed() {
    int pin = 0;
    
    if ( mouseX > 20 && mouseX < 120) {
      pin = 11;
    
    } else if (mouseX > 140 && mouseX < 240) {
      
      pin = 10;
    
    } else if (mouseX > 260 && mouseX < 360) {
      pin = 9;
    
    }
    
    if (values[pin] == Arduino.LOW) {
    arduino.digitalWrite(pin, Arduino.HIGH);
    values[pin] = Arduino.HIGH;
  } else {
    arduino.digitalWrite(pin, Arduino.LOW);
    values[pin] = Arduino.LOW;
  }
  

}