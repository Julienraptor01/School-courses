//color pin setup
#define RED_PIN 10
#define GREEN_PIN 11
#define BLUE_PIN 9

//create color type
typedef struct {
	int red;
	int green;
	int blue;
} color;

//default colors (RGB)
const color red = { 255, 0, 0 }, green = { 0, 255, 0 }, blue = { 0, 0, 255 }, magenta = { 255, 0, 255 }, yellow = { 255, 255, 0 }, cyan = { 0, 255, 255 }, white = { 255, 255, 255 }, black = { 0, 0, 0 };
//init vars
//the colorIntensity is in %
int colorIntensity = 100, duration = 2000;

void setup() {
	//pin setup
	pinMode(RED_PIN, OUTPUT);
	pinMode(GREEN_PIN, OUTPUT);
	pinMode(BLUE_PIN, OUTPUT);
}
void loop() {
	//main part which cycle through all colors
	setColor(red, colorIntensity, duration);
	setColor(green, colorIntensity, duration);
	setColor(blue, colorIntensity, duration);
	setColor(white, colorIntensity, duration);
	setColor(magenta, colorIntensity, duration);
	setColor(yellow, colorIntensity, duration);
	setColor(cyan, colorIntensity, duration);
}

//function to set the non-diluted color
void setPureColor(color color) {
	analogWrite(RED_PIN, color.red);
	analogWrite(GREEN_PIN, color.green);
	analogWrite(BLUE_PIN, color.blue);
}

//function which dilute the color by toggling the color on and off over very short time
void setColor(color color, int colorIntensity, int duration) {
	//loop for duration
	while (duration > 0) {
		//set pure color
		setPureColor(color);
		//wait a bit
		delayMicroseconds(colorIntensity*10);
		//now dilute it by setting it off
		setPureColor(black);
		//wait the rest of the time
		delayMicroseconds((100 - colorIntensity)*10);
		//decrease time passed
		duration--;
	}
}