//define the mode on either 3D merged (0) or 3D separate (1) or 2D separate (2)
#define MODE 2

//color pin setup
#define RED_PIN 11
#define GREEN_PIN 10
#define BLUE_PIN 9

//axis pin setup
#define X_PIN A0
#define Y_PIN A1
#define Z_PIN A2

//create color type
typedef struct {
	int red;
	int green;
	int blue;
} color;

//default colors (RGB)
const color red = {255, 0, 0}, green = {0, 255, 0}, blue = {0, 0, 255}, magenta = {255, 0, 255}, yellow = {255, 255, 0}, cyan = {0, 255, 255}, white = {255, 255, 255}, black = {0, 0, 0};

//init vars
//the colorIntensity is in %n and the duration is in ms
int colorIntensity = 100, duration = 200;

void setup() {
	//pin setup
	pinMode(RED_PIN, OUTPUT);
	pinMode(GREEN_PIN, OUTPUT);
	pinMode(BLUE_PIN, OUTPUT);
	pinMode(X_PIN, INPUT);
	pinMode(Y_PIN, INPUT);
	pinMode(Z_PIN, INPUT);

	//serial setup
	Serial.begin(9600);
}

void loop() {
	// put your main code here, to run repeatedly:
	//read values
	int x = analogRead(X_PIN);
	int y = analogRead(Y_PIN);
	int z = analogRead(Z_PIN);

#if MODE == 0
//set the color of the led depending on the axis output
//setColor({int(x/1023.0*255), int(y/1023*255), int(z/1023*255)}, colorIntensity, duration);
//that's only good when the value of the axis is between 0 and 1023
//in reality my values go from 266 to 398
//so I need to map them to 0-255
//and if they go out of the expected range i just need to clamp them
setColor({int(map(x, 266, 398, 0, 255)), int(map(y, 266, 398, 0, 255)), int(map(z, 266, 398, 0, 255))}, colorIntensity, duration);
#elif MODE == 1
//set the color of the led depending on the axis output
//set the color to red if the x axis is the most different from the center which is 332
//set the color to green if the y axis is the most different from the center which is 332
//set the color to blue if the z axis is the most different from the center which is 332
if (abs(x - 332) > abs(y - 332) && abs(x - 332) > abs(z - 332)) {
	setColor(red, colorIntensity, duration);
} else if (abs(y - 332) > abs(x - 332) && abs(y - 332) > abs(z - 332)) {
	setColor(green, colorIntensity, duration);
} else if (abs(z - 332) > abs(x - 332) && abs(z - 332) > abs(y - 332)) {
	setColor(blue, colorIntensity, duration);
} else {
	setColor(black, colorIntensity, duration);
}
#elif MODE == 2
//same as mode 1 but with 2D so only x and y, if both are different enough from the center then the color is blue
//the treshold should be like 33%/2 of the range so 11
if (abs(x - 332) > 22 && abs(y - 332) > 22 ) {
	setColor(blue, colorIntensity, duration);
} else if (abs(x - 332) > abs (y - 332) && abs(x - 332) > 66) {
	setColor(red, colorIntensity, duration);
} else if (abs(y - 332) > abs (x - 332) && abs(y - 332) > 66) {
	setColor(green, colorIntensity, duration);
} else {
	setColor(black, colorIntensity, duration);
}
#endif

//print values
Serial.print("X: ");
Serial.print(x);
Serial.print(" Y: ");
Serial.print(y);
Serial.print(" Z: ");
Serial.println(z);
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