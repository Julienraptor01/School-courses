//servo pin setup
#define RIGHT_SERVO_PIN 11
#define LEFT_SERVO_PIN 10

int leftBackward = 1300, leftStationary = 1500, leftForward = 1700;
int rightBackward = 1700, rightStationary = 1500, rightForward = 1300;
int maxPulseLength = (rightBackward >= leftForward) ? rightForward : leftBackward;

void setup() {
	//set the servo pins to output
	pinMode(RIGHT_SERVO_PIN, OUTPUT);
	pinMode(LEFT_SERVO_PIN, OUTPUT);

	//serial setup
	Serial.begin(115200);
}

void loop() {
	move(leftForward, rightForward);
	delay(10);
}

void pulseServo(int servoPin, int pulseLength) {
	digitalWrite(servoPin, HIGH);
	delayMicroseconds(pulseLength);
	digitalWrite(servoPin, LOW);
	delayMicroseconds((maxPulseLength + 50) - pulseLength);
}

void move(int left, int right) {
	pulseServo(RIGHT_SERVO_PIN, right);
	pulseServo(LEFT_SERVO_PIN, left);
}