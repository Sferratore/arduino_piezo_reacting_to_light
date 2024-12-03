int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;
const int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  while(millis() < 5000){
    sensorValue = analogRead(A0);
    if(sensorValue > sensorHigh){
      sensorHigh = sensorValue;
    }
    if(sensorValue < sensorLow){
      sensorLow = sensorValue;
    }
  }
  digitalWrite(ledPin,LOW);
}

void loop() {  //BIT: 250 tone, 100 delay, 3200 pitch SCRATCH: 250 tone, 0 delay, 900 pitch
  sensorValue = analogRead(A0);
  int pitch = map(sensorValue,sensorLow,sensorHigh, 50, 900);
  tone(8,pitch,250);
  delay(0);
}
