// Definte pins for the red, green, and blue LEDs
#define RED_LED 6
#define BLUE_LED 9
#define GREEN_LED 5

// Overall brightness value
int brightness = 255;

// Sound detection pin
int btnPin = 3;

// Detection cooldown
int cooldown = 5000;
int lastActive = millis();
int val;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    // Send signals to RGB leds 
    pinMode(GREEN_LED, OUTPUT);
    pinMode(RED_LED, OUTPUT);
    pinMode(BLUE_LED, OUTPUT);
    // Input from SD module
    pinMode(btnPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Binding SD module input (0s and 1s)
  val = digitalRead(btnPin);
  // 5 second cooldown before detections
  boolean conditional = (millis() - lastActive) > cooldown;
  if(val==HIGH && conditional){
    rgbOn(brightness);
    lastActive = millis();
    if(brightness == 255) {
      brightness = 0;
    } else {
      brightness = 255; 
    }
  }
  delay(1);
}

// Turn all lights to given brightness 
void rgbOn(int brightness) {
  analogWrite(BLUE_LED, brightness);
  analogWrite(RED_LED, brightness);
  analogWrite(GREEN_LED, brightness);
}
