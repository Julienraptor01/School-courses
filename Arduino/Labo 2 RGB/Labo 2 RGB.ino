#define RED_PIN 10
#define GREEN_PIN 11
#define BLUE_PIN 9

typedef struct {
	int red;
	int green;
	int blue;
} Color;

Color red = { 255, 0, 0 }, green = { 0, 255, 0 }, blue = { 0, 0, 255 }, magenta = { 255, 0, 255 }, yellow = { 255, 255, 0 }, cyan = { 0, 255, 255 }, white = { 255, 255, 255 }, black = { 0, 0, 0 };
float dilution = 0;
int waitTime = 2000;

void setup() {
	// put your setup code here, to run once:
	pinMode(RED_PIN, OUTPUT);
	pinMode(GREEN_PIN, OUTPUT);
	pinMode(BLUE_PIN, OUTPUT);
	dilution = 0.5;
}
void loop() {
	// put your main code here, to run repeatedly:
	setColor(red, dilution, waitTime);
	setColor(green, dilution, waitTime);
	setColor(blue, dilution, waitTime);
	setColor(white, dilution, waitTime);
	setColor(magenta, dilution, waitTime);
	setColor(yellow, dilution, waitTime);
	setColor(cyan, dilution, waitTime);
}

void setPureColor(Color color) {
	analogWrite(RED_PIN, color.red);
	analogWrite(GREEN_PIN, color.green);
	analogWrite(BLUE_PIN, color.blue);
}

void setColor(Color color, int dilution, int waitTime) {
	while (waitTime > 0) {
		setPureColor(color);
		delay(dilution);
		setPureColor(black);
		delay(1-dilution);
		waitTime--;
	}
}