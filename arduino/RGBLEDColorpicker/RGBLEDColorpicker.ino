#define BLUE 3
#define GREEN 5
#define RED 6
#define ASCII_HASH 35
#define HEX_LENGTH 7
#define DELAY_TIME 1
#define OFF 0

// define variables
const char base[] = "0123456789ABCDEF";
const int baseSize = (sizeof(base) / sizeof(char)) - 1; // -1 in the equataion for null terminator of base string

static int isHexString(String input);
static int getIndex(char c);
static int hexToInt(char first, char second);

void setup()
{
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  analogWrite(RED, OFF);
  analogWrite(GREEN, OFF);
  analogWrite(BLUE, OFF);
}

// main loop
void loop()
{
  static int redValue = 0;
  static int greenValue = 0;
  static int blueValue = 0;

  if (Serial.available() > 0)
  {
    String hexCode = Serial.readString();
    hexCode.trim();
    if (!isHexString(hexCode))
    {
      Serial.print("Input ");
      Serial.print(hexCode);
      Serial.println(" is not a hex format (#XXXXXX with X as 0 - 9 or A - F)");
      redValue = OFF;
      greenValue = OFF;
      blueValue = OFF;
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
    analogWrite(RED, redValue);
    analogWrite(GREEN, greenValue);
    analogWrite(BLUE, blueValue);
  }
  delay(DELAY_TIME);
}

static int	isHexString(String input)
{
  int ret = 1;

  if (input[0] != ASCII_HASH || input.length() != HEX_LENGTH)
    ret = 0;

  for (int i = 1; i < HEX_LENGTH && ret != 0; i++)
  {
    if (!(isHexadecimalDigit(input[i])))
      ret = 0;
  }

	return (ret);
}

static int getIndex(char c)
{
	int	idx;

	idx = 0;
	while (base[idx] != c)
		idx++;

	return (idx);
}

static int hexToInt(char first, char second)
{
  return (getIndex(first) * baseSize + getIndex(second));
}
