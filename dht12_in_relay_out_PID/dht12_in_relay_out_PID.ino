#include <dht.h>
#define dataPin 8 // Defines pin number to which the sensor is connected
dht DHT; // Creats a DHT object
int relay = 7;
void setup() 
{
	Serial.begin(9600);
  pinMode(relay, OUTPUT);
}
void loop() 
{
	//Uncomment whatever type you're using!
	int readData = DHT.read22(dataPin); // DHT22/AM2302
	//int readData = DHT.read11(dataPin); // DHT11

	float tC = DHT.temperature; // Gets the values of the temperature
  float tF = ((tC * 9.0) / 5.0 + 32.0);
	float h = DHT.humidity; // Gets the values of the humidity

	// Printing the results on the serial monitor
	//Serial.print((char)176);//shows degrees character
	Serial.print(tF);//print the temperature in Fahrenheit
	Serial.print(" ");
	//Serial.print((char)176);//shows degrees character
	Serial.println("F ");
	Serial.print("Humidity = ");
	Serial.print(h);
	Serial.println(" % ");
	Serial.println("");

	delay(3000); // Delays 2 secods
  if (tF > 83) {
    digitalWrite(relay, LOW);
  }
  else {
    digitalWrite(relay, HIGH);
  }
}