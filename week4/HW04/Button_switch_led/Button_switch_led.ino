int ledPin = 9;

int buttonPin = 5;
int debounceDelay = 10;
bool ledState = true;


void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  
  int oldButtonState = 0;
  int newButtonState = 0;

  oldButtonState = digitalRead(buttonPin);
  delay(10);
  newButtonState = digitalRead(buttonPin);
 

  if(oldButtonState != newButtonState) {
    if(newButtonState == LOW) {
      Serial.println(newButtonState);
      ledState = !ledState;
      }
    }


   if(ledState) {
    digitalWrite(ledPin, HIGH);
    }else {
      digitalWrite(ledPin, LOW);
      }
    
}
