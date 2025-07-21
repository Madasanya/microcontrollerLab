//www.elegoo.com
//2016.12.8

// Define Pins
#define BLUE 3
#define GREEN 5
#define RED 6
#define HASH 35
#define HEX_LENGTH 7

void setup()
{
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
}

// define variables
int redValue = 0;
int greenValue = 0;
int blueValue = 0;
char base[16] = "0123456789ABCDEF";

int	ft_strlen(String string)
{
	int	len;

	len = 0;
	while (string[len] != '\0')
		len++;
	return (len);
}

int	isHex(String input)
{
  int ret = 1;
  if (input[0] != HASH || ft_strlen(input) != HEX_LENGTH + 1)
    ret = 0;
  for (int i = 1; i < HEX_LENGTH; i++)
  {
    Serial.println("Test02");
    Serial.println(input[i]);
    if (!((input[i] > 47 && input[i] < 58) || (input[i] > 64 && input[i] < 71)))
    {
      Serial.println("Test03");
      Serial.println(input[i]);
      ret = 0;
    }
  }
  Serial.println(ret);
	return ret;
}

// main loop
void loop()
{
  #define delayTime 10 // fading time between colors

  if (Serial.available() > 0)
  {
    String hexCode = Serial.readString();
    if (!isHex(hexCode))
    {
      Serial.print("Input ");
      Serial.print(hexCode);
      Serial.println(" was not a hex format (#000000)");
      redValue = 255;
      greenValue = 0;
    }
    else
    {
      greenValue = 255;
      redValue = 0;
    }
  }


  analogWrite(RED, redValue);
  analogWrite(GREEN, greenValue);
  analogWrite(BLUE, blueValue);
  delay(delayTime);


}
