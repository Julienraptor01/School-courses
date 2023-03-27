//servo pin setup
#define RIGHT_SERVO_PIN 10
#define LEFT_SERVO_PIN 11

#define RIGHT_SERVO_CODER 2
#define LEFT_SERVO_CODER 3

#define DISTANCE_BETWEEN_WHEELS 11.4

int leftBackward = 1300, leftStationary = 1500, leftForward = 1700;
int rightBackward = 1700, rightStationary = 1500, rightForward = 1300;
int maxPulseLength = (rightBackward >= leftForward) ? rightForward : leftBackward;
volatile int rightCounter, leftCounter;

void setup()
{
	//set the servo pins to output
	pinMode(RIGHT_SERVO_PIN, OUTPUT);
	pinMode(LEFT_SERVO_PIN, OUTPUT);

	//serial setup
	Serial.begin(115200);

	//setup interrupt
	attachInterrupt(digitalPinToInterrupt(RIGHT_SERVO_CODER), rightCounterIncrease, CHANGE);
	attachInterrupt(digitalPinToInterrupt(LEFT_SERVO_CODER), leftCounterIncrease, CHANGE);
}
  
void loop()
{
	rotateLeftOnLeft(90);
	delay(1000000);
}

void rotateLeftOnLeft(int angle)
{
	move(angle * DISTANCE_BETWEEN_WHEELS * 2 * M_PI / 360, rightForward, leftStationary);
}

void moveForward(int distance)
{
	move(distance, rightForward, leftForward);
}

void move(int distance, int left, int right)
{
	rightCounter = 0, leftCounter = 0;
	int step = distance * 10 / 3.25;
	while(rightCounter < step && leftCounter < step)
	{
		pulseServo(RIGHT_SERVO_PIN, right);
		pulseServo(LEFT_SERVO_PIN, left);
	}
}

void pulseServo(int servoPin, int pulseLength)
{
	digitalWrite(servoPin, HIGH);
	delayMicroseconds(pulseLength);
	digitalWrite(servoPin, LOW);
	delayMicroseconds((maxPulseLength + 50) - pulseLength);
}

void rightCounterIncrease()
{
	rightCounter++;
}

void leftCounterIncrease()
{
	leftCounter++;
}
