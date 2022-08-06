#include "SerialTransfer.h"


SerialTransfer myTransfer;

byte led;
byte red;
byte green;
byte blue;

void setup()
{
  Serial.begin(115200);
  myTransfer.begin(Serial);
}


void loop()
{
  if(myTransfer.available())
  {
    // send all received data back to Python
    //for(uint16_t i=0; i < myTransfer.bytesRead; i++)
      led   = myTransfer.packet.rxBuff[0];
      red   = myTransfer.packet.rxBuff[1];
      green = myTransfer.packet.rxBuff[2];
      blue  = myTransfer.packet.rxBuff[3];

      myTransfer.packet.txBuff[0] = led;
      myTransfer.packet.txBuff[1] = red;
      myTransfer.packet.txBuff[2] = green;
      myTransfer.packet.txBuff[3] = blue;

    myTransfer.sendData(myTransfer.bytesRead);
  }
}
