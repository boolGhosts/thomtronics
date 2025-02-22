// Glow Robot Vera Mae 2/22/25

// Eyes HC-SR04 https://tinyurl.com/58dsyhx4

const int trigPin = 9;  
const int echoPin = 10; 
float duration, distance, distanceInch;  

// Keyboard tinkercad example for 8ohm speaker

int pos = 0;

void setup()
{
// Eyes Setup
	pinMode(trigPin, OUTPUT);  
	pinMode(echoPin, INPUT);  
	Serial.begin(9600);  
  pinMode(LED_BUILTIN, OUTPUT);
// Keyboard Setup
  pinMode(A0, INPUT);
  pinMode(8, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
}

void loop()
{
  // Eyes Loop
  digitalWrite(trigPin, LOW);  
	delayMicroseconds(2);  
	digitalWrite(trigPin, HIGH);  
	delayMicroseconds(10);  
	digitalWrite(trigPin, LOW); 
  duration = pulseIn(echoPin, HIGH);  
  distance = (duration*.0343)/2;
  distanceInch = distance*0.393701;
  Serial.print("Distance: ");  
	Serial.println(distanceInch);
  if (distanceInch < 1.2) {
      digitalWrite(13, HIGH);
      delay(500);
      digitalWrite(13, LOW);
      delay(250);
      tone(8, 600, 100);
} else {
      digitalWrite(13, LOW);
}  

  // Keyboard Loop
  // if button press on A0 is detected
  if (digitalRead(A0) == HIGH) {
    tone(8, 440, 100); // play tone 57 (A4 = 440 Hz)
  }
  // if button press on A1 is detected
  if (digitalRead(A1) == HIGH) {
    tone(8, 494, 100); // play tone 59 (B4 = 494 Hz)
  }
  // if button press on A0 is detected
  if (digitalRead(A2) == HIGH) {
    tone(8, 523, 100); // play tone 60 (C5 = 523 Hz)
  }
  delay(10); // Delay a little bit to improve simulation performance
}