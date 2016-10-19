#include <CapacitiveSensor.h>

CapacitiveSensor sensor = CapacitiveSensor(4, 2);

int ledPins[] = {13, 12, 11, 10, 9, 8, 7, 6};
int pinCount = 8;
int timer = 20;
int ledVal = 0;
int toneVal = 600;

int buzPin = 5;

bool a = false;
bool b = false;
int count = 0;

void setup() {
  Serial.begin(9600);
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    pinMode(ledPins[thisPin], OUTPUT);
  }
  pinMode(buzPin, OUTPUT);
}

void loop() {
  long sensorVal = sensor.capacitiveSensor(30);
  Serial.println(sensorVal);
  delay(15);
  long sensorVal2 = sensor.capacitiveSensor(30);
  delay(40);
  long sensorVal3 = sensor.capacitiveSensor(30);

  if (sensorVal - sensorVal2 > 400 && abs(sensorVal2 - sensorVal3 < 100)) a = true;

  if (sensorVal > 400 || a == true) {

    if (sensorVal > 400) b = false;

    for (int thisPin = 0; thisPin < pinCount; thisPin++) {
      // turn the pin on:
      digitalWrite(ledPins[thisPin], HIGH);
      if (count != 6) tone(buzPin, toneVal);
      delay(timer);
      // turn the pin off:
      digitalWrite(ledPins[thisPin], LOW);
      noTone(buzPin);

      //      ledVal = digitalRead(ledPins[thisPin]);
      //      if (ledVal == HIGH) {
      //        tone(buzPin, 200);
      //      }

      sensorVal2 = sensor.capacitiveSensor(30);
      delay(15);
      sensorVal3 = sensor.capacitiveSensor(30);


      if (a == true) {
        count++;
        timer += count * 80;
        toneVal -= 50;
        Serial.println(count);
        if (count == 6) {
          timer = 3000;
        }
        if (count == 7) {
          a = false;
          count = 0;
          timer = 20;
          b = true;
          toneVal = 600;
          break;
        }
      }
      if (abs(sensorVal3 - sensorVal2 < 100)) {
        if (sensorVal2 < 100 && b == false) {
          a = true;
        }
      }
    }


  }

}
