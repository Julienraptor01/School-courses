//micro pin setup
#define ANALOG_MICRO_PIN A0
#define DIGITAL_MICRO_PIN 2

void setup() {
	pinMode(ANALOG_MICRO_PIN, INPUT);
	pinMode(DIGITAL_MICRO_PIN, INPUT);

	//serial setup
	Serial.begin(115200);
}

void loop() {
	Serial.print("Analog: ");
	Serial.println(analogRead(ANALOG_MICRO_PIN));
	Serial.print("Digital: ");
	Serial.println(digitalRead(DIGITAL_MICRO_PIN));
	delay(100);
}