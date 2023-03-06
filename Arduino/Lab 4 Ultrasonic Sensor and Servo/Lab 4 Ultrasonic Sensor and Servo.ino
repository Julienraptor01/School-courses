//ping pin setup
#define PING_PIN 7

//temperature
#define TEMPERATURE 20

//speed of sound
#define SPEED_OF_SOUND 331.3 + 0.606 * TEMPERATURE

void setup() {

	//serial setup
	Serial.begin(115200);
}

void loop() {
	//send a pulse
	pinMode(PING_PIN, OUTPUT);
	digitalWrite(PING_PIN, LOW);
	delayMicroseconds(2);
	digitalWrite(PING_PIN, HIGH);
	delayMicroseconds(5); 
	digitalWrite(PING_PIN, LOW);

	//read the pulse
	pinMode(PING_PIN, INPUT);
	long duration = pulseIn(PING_PIN, HIGH);
	double distance = microsecondsToCentimeters(duration);
	Serial.print(distance);
	Serial.println(" cm");

	//wait a bit
	delay(2000);
}

double microsecondsToCentimeters(long microseconds) {
	return double(microseconds) * double(SPEED_OF_SOUND) / 20000.0;
	//return double(microseconds) / 29 / 2;
}