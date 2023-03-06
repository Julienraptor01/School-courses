//ping pin setup
#define PING_PIN 7

//servo pin setup
#define SERVO_PIN 9

//temperature
#define TEMPERATURE 20

//speed of sound
#define SPEED_OF_SOUND 331.3 + 0.606 * TEMPERATURE

void setup() {
	//set the pin to output
	pinMode(SERVO_PIN, OUTPUT);

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
	double distance = microsecondsToCentimeters(pulseIn(PING_PIN, HIGH));
	Serial.print(distance);
	Serial.println(" cm");

	//move the servo to the right position if the distance is higher than 20 cm with a marge of 2 cm
	if (distance > 21) {
		pulseServo(1000);
	} else if (distance > 19 && distance < 21) {
		pulseServo(1500);
	} else if (distance < 19) {
		pulseServo(2000);
	}

	//wait a bit
	delay(100);
}

double microsecondsToCentimeters(long microseconds) {
	return double(microseconds) * double(SPEED_OF_SOUND) / 20000.0;
	//return double(microseconds) / 29 / 2;
}

void pulseServo(int pulseLength) {
	digitalWrite(SERVO_PIN, HIGH);
	delayMicroseconds(pulseLength);
	digitalWrite(SERVO_PIN, LOW);
}