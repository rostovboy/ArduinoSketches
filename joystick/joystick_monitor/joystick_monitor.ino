// https://developer.alexanderklimov.ru/arduino/joystick.php
// https://www.youtube.com/watch?v=JFLTB5oGyc8
// https://3d-diy.ru/wiki/arduino-datchiki/arduino-joystick/
const int xPin = A1;
const int yPin = A0;
const int buttonPin = 3;

int xPosition = 0;
int yPosition = 0;
int buttonState = 0;

void setup() {
  Serial.begin(9600);

  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);

  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // Считываем показания с джойстика
  xPosition = analogRead(xPin);
  yPosition = analogRead(yPin);
  buttonState = digitalRead(buttonPin);
  Serial.print("X: ");
  Serial.print(xPosition);
  Serial.print(" | Y: ");
  Serial.print(yPosition);
  Serial.print(" | Button: ");
  Serial.println(buttonState);
  delay(1000);  // добавляем задержку между считыванием данных
}