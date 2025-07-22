#define FAN1_INPUT 8
#define FAN1_OUTPUT 9

#define FAN2_INPUT 11
#define FAN2_OUTPUT 12

void setup() {
  // put your setup code here, to run once:
  pinMode(FAN1_INPUT, INPUT);
  pinMode(FAN1_OUTPUT, OUTPUT);
  pinMode(FAN2_INPUT, INPUT);
  pinMode(FAN2_OUTPUT, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(FAN1_OUTPUT, 50);
  analogWrite(FAN2_OUTPUT, 50);
  delay(1000);
  analogWrite(FAN1_OUTPUT, 100);
  analogWrite(FAN2_OUTPUT, 100);
  delay(1000);
  analogWrite(FAN1_OUTPUT, 150);
  delay(1000);
  analogWrite(FAN1_OUTPUT, 200);
  delay(1000);
  analogWrite(FAN1_OUTPUT, 250);
  delay(10000);
}
