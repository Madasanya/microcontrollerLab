//www.elegoo.com
//2016.12.8

// Define Pins
#define BLUE 3
#define GREEN 5
#define RED 6
#define ASCII_HASH 35
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

int	isHexString(String input)
{
  int ret = 1;

  if (input[0] != ASCII_HASH || ft_strlen(input) != HEX_LENGTH)
    ret = 0;

  for (int i = 1; i < HEX_LENGTH && ret != 0; i++)
  {
    if (!(isHexadecimalDigit(input[i])))
      ret = 0;
  }

	return (ret);
}

int getIndex(char c)
{
	int	idx;

	idx = 0;
	while (base[idx] != c)
		idx++;

	return (idx);
}

int hexToInt(char first, char second)
{
  int baseSize = (sizeof(base)/sizeof(char));
  return (getIndex(first) * pow(baseSize, 1) + getIndex(second) * pow(baseSize, 0));
}

// main loop
void loop()
{
  if (Serial.available() > 0)
  {
    String hexCode = Serial.readString();
    hexCode.trim();
    if (!isHexString(hexCode))
    {
      Serial.print("Input ");
      Serial.print(hexCode);
      Serial.println(" is not a hex format (#XXXXXX with X as 0 - 9 or A - F)");
      redValue = 0;
      greenValue = 0;
      blueValue = 0;
    }
    else
    { 
      redValue = hexToInt(hexCode[1], hexCode[2]);
      greenValue = hexToInt(hexCode[3], hexCode[4]);
      blueValue = hexToInt(hexCode[5], hexCode[6]);
      Serial.println(redValue);
      Serial.println(greenValue);
      Serial.println(blueValue);
    }
  }
  analogWrite(RED, redValue);
  analogWrite(GREEN, greenValue);
  analogWrite(BLUE, blueValue);
}
