//
//    FILE: demo_hw_spi.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: demo DAC8550 library Arduino with hardware SPI
// VERSION: 0.1.1
//     URL: https://github.com/RobTillaart/DAC8550


#include "DAC8550.h"


DAC8550 DAC(7);


void setup()
{
  Serial.begin(115200);
  Serial.println(__FILE__);
  DAC.begin();
}

void loop()
{
  //  // minimal sawtooth
  //  for (uint16_t val = 0; val < 65500; val+= 30)
  //  {
  //    DAC.setValue(val);
  //    int av = analogRead(A0);
  //
  //    Serial.print(val);
  //    Serial.print("\t ==> \t");
  //    Serial.println(av);
  //  }

  // minimal sinus
  for (long i = 0; i < 360; i++ )
  {
    long sinValue = 32767 + 32767 * sin( i * (PI / 180.0));
    DAC.setValue(sinValue);
    Serial.println(sinValue);
    int av = analogRead(A0);
    Serial.print(sinValue);
    Serial.print("\t ==> \t");
    Serial.println(av);
    delay(10);
  }
}

// -- END OF FILE --