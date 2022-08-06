# 1 "/Users/esby/Documents/Spectroscopy/Code/07_color_prediction/07_color_prediction.ino"
# 2 "/Users/esby/Documents/Spectroscopy/Code/07_color_prediction/07_color_prediction.ino" 2
# 3 "/Users/esby/Documents/Spectroscopy/Code/07_color_prediction/07_color_prediction.ino" 2
# 4 "/Users/esby/Documents/Spectroscopy/Code/07_color_prediction/07_color_prediction.ino" 2

const int RED = 3;
const int GREEN = 5;
const int BLUE = 6;

const int RED_DISPLAY = 9;
const int GREEN_DISPLAY = 10;
const int BLUE_DISPLAY = 11;

SerialTransfer trans;

void setup()
{
    Config_Init();
    if (TCS34725_Init() != 0)
    {
        Serial.print("TCS34725 initialization error!!\r\n");
    }

    Serial.print("TCS34725 initialization success!!\r\n");

    pinMode(RED, 0x1);
    pinMode(GREEN, 0x1);
    pinMode(BLUE, 0x1);

    analogWrite(RED, 121);
    analogWrite(GREEN, 54);
    analogWrite(BLUE, 94);

    pinMode(RED_DISPLAY, 0x1);
    pinMode(GREEN_DISPLAY, 0x1);
    pinMode(BLUE_DISPLAY, 0x1);
}

RGB rgb, RGB888;
void loop()
{
    rgb = TCS34725_Get_RGBData();
    RGB888 = TCS34725_GetRGB888(rgb);
    printSensor(rgb);
    displayLED(RGB888);

    delay(500);
}

void displayLED(RGB rgb)
{
    analogWrite(RED_DISPLAY, rgb.R);
    analogWrite(GREEN_DISPLAY, rgb.G);
    analogWrite(BLUE_DISPLAY, rgb.B);
}

void printSensor(RGB rgb)
{
    Serial.print("R = ");
    Serial.print(rgb.R);
    Serial.print(" G = ");
    Serial.print(rgb.G);
    Serial.print(" B = ");
    Serial.print(rgb.B);
    Serial.print("\r\n");
}

void sendData(RGB rgb)
{
    u16 arr[] = {rgb.R, rgb.G, rgb.B};
    trans.sendDatum(arr);
}
