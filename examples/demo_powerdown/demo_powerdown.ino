//
//    FILE: demo_powerdown.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: demo DAC8550 library Arduino
// VERSION: 0.1.0
//     URL: https://github.com/RobTillaart/DAC8550


#include "DAC8550.h"


DAC8550 DAC(7);


void setup()
{
  Serial.begin(115200);
  Serial.println(__FILE__);
  DAC.begin();
  
  DAC.setValue(0);
  DAC.setPowerDown(DAC8550_POWERDOWN_HIGH_IMP);
}


void loop()
{
  Serial.println("Start sawtooth");
  for (uint16_t i = 0; i < 32000; i+= 100)
  {
    DAC.setValue(i);
  }

  Serial.println("Stop DAC for 5 seconds");
  DAC.setPowerDown(DAC8550_POWERDOWN_HIGH_IMP);
  uint32_t start = millis();
  while (millis() - start < 5000);
  DAC.setPowerDown(DAC8550_POWERDOWN_NORMAL);
  
  Serial.println("Continue sawtooth");
  for (uint16_t i = 32000; i < 64000; i+= 100)
  {
    DAC.setValue(i);
  }

}

// END OF FILE
