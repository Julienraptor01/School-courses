//ping pin setup
#define PING_PIN 7

//sensor servo pin setup
#define SENSOR_SERVO_PIN 12

//temperature
#define TEMPERATURE 20

//speed of sound
#define SPEED_OF_SOUND 331.3 + 0.606 * TEMPERATURE

//wheel servo pin setup
#define RIGHT_WHEEL_SERVO_PIN 10
#define LEFT_WHEEL_SERVO_PIN 11

//wheel servo coder pin setup
#define RIGHT_WHEEL_SERVO_CODER 2
#define LEFT_WHEEL_SERVO_CODER 3

//distance between the wheels
#define DISTANCE_BETWEEN_WHEELS 11.4

//offsets to make the servo go straight
#define RIGHT_WHEEL_SERVO_OFFSET 10
#define LEFT_WHEEL_SERVO_OFFSET 0
#define SENSOR_OFFSET 0

int sensorServoLeft = 2400 + SENSOR_OFFSET, sensorServoMiddle = 1500 + SENSOR_OFFSET, sensorServoRight = 600 + SENSOR_OFFSET;
int maxSensorPulseLength = (sensorServoLeft >= sensorServoRight) ? sensorServoLeft : sensorServoRight;
int wheelLeftBackward = 1300 + LEFT_WHEEL_SERVO_OFFSET , wheelLeftStationary = 1500 + LEFT_WHEEL_SERVO_OFFSET , wheelLeftForward = 1700 + LEFT_WHEEL_SERVO_OFFSET ;
int wheelRightBackward = 1700 + RIGHT_WHEEL_SERVO_OFFSET , wheelRightStationary = 1500 + RIGHT_WHEEL_SERVO_OFFSET , wheelRightForward = 1300 + RIGHT_WHEEL_SERVO_OFFSET ;
int maxWheelPulseLength = (wheelRightBackward >= wheelLeftForward) ? wheelRightForward : wheelLeftBackward;
volatile int wheelRightCounter, wheelLeftCounter;

void setup()
{
	//set the servo pins to output
	pinMode(RIGHT_WHEEL_SERVO_PIN, OUTPUT);
	pinMode(LEFT_WHEEL_SERVO_PIN, OUTPUT);
	pinMode(SENSOR_SERVO_PIN, OUTPUT);

	//serial setup
	Serial.begin(115200);

	//setup interrupt
	attachInterrupt(digitalPinToInterrupt(RIGHT_WHEEL_SERVO_CODER), wheelRightCounterIncrease, CHANGE);
	attachInterrupt(digitalPinToInterrupt(LEFT_WHEEL_SERVO_CODER), wheelLeftCounterIncrease, CHANGE);
}
  
void loop()
{
	/*
	rotateLeftOnLeft(90);
	delay(1000);
	rotateRightOnRight(90);
	delay(1000);
	rotateLeftOnMiddle(90);
	delay(1000);
	rotateRightOnMiddle(90);
	delay(1000000);
	*/
	move(1, 1450, 1550, false);
	delay(1000000);
}

void rotateLeftOnLeft(int angle)
{
	move(angle * DISTANCE_BETWEEN_WHEELS * 2 * M_PI / 360, wheelRightForward, wheelLeftStationary, true);
}

void rotateLeftOnMiddle(int angle)
{
	move((angle / 2) * DISTANCE_BETWEEN_WHEELS * 2 * M_PI / 360, wheelRightForward, wheelLeftBackward, true);
}

void rotateRightOnMiddle(int angle)
{
	move((angle / 2) * DISTANCE_BETWEEN_WHEELS * 2 * M_PI / 360, wheelRightBackward, wheelLeftForward, true);
}

void rotateRightOnRight(int angle)
{
	move(angle * DISTANCE_BETWEEN_WHEELS * 2 * M_PI / 360, wheelRightStationary, wheelLeftForward, true);
}

void moveForward(int distance)
{
	move(distance, wheelRightForward, wheelLeftForward, true);
}

void move(int value, int wheelLeft, int wheelRight, bool isDistance)
{
	wheelRightCounter = 0, wheelLeftCounter = 0;
	int step = isDistance ? value * 10 / 3.25 : value;
	while(wheelRightCounter < step && wheelLeftCounter < step)
	{
		pulseWheelServo(RIGHT_WHEEL_SERVO_PIN, wheelRight);
		pulseWheelServo(LEFT_WHEEL_SERVO_PIN, wheelLeft);
	}
}

void pulseWheelServo(int servoPin, int pulseLength)
{
	digitalWrite(servoPin, HIGH);
	delayMicroseconds(pulseLength);
	digitalWrite(servoPin, LOW);
	delayMicroseconds((maxWheelPulseLength + 50) - pulseLength);
}

void pulseSensorServo(int pulseLength)
{
	digitalWrite(SENSOR_SERVO_PIN, HIGH);
	delayMicroseconds(pulseLength);
	digitalWrite(SENSOR_SERVO_PIN, LOW);
	delayMicroseconds((maxWheelPulseLength + 50) - pulseLength);
}

void wheelRightCounterIncrease()
{
	wheelRightCounter++;
}

void wheelLeftCounterIncrease()
{
	wheelLeftCounter++;
}

double microsecondsToCentimeters(long microseconds) {
	return double(microseconds) * double(SPEED_OF_SOUND) / 20000.0;
	//return double(microseconds) / 29 / 2;
}

void sendPingPulse()
{
	pinMode(PING_PIN, OUTPUT);
	digitalWrite(PING_PIN, LOW);
	delayMicroseconds(2);
	digitalWrite(PING_PIN, HIGH);
	delayMicroseconds(5);
	digitalWrite(PING_PIN, LOW);
}

double readPingPulse()
{
	pinMode(PING_PIN, INPUT);
	return microsecondsToCentimeters(pulseIn(PING_PIN, HIGH));
}