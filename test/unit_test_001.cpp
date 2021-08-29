//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2021-02-04
// PURPOSE: unit tests for the DAC8550
//          https://github.com/RobTillaart/DAC8550
//          https://github.com/Arduino-CI/arduino_ci/blob/master/REFERENCE.md
//

// supported assertions
// ----------------------------
// assertEqual(expected, actual);               // a == b
// assertNotEqual(unwanted, actual);            // a != b
// assertComparativeEquivalent(expected, actual);    // abs(a - b) == 0 or (!(a > b) && !(a < b))
// assertComparativeNotEquivalent(unwanted, actual); // abs(a - b) > 0  or ((a > b) || (a < b))
// assertLess(upperBound, actual);              // a < b
// assertMore(lowerBound, actual);              // a > b
// assertLessOrEqual(upperBound, actual);       // a <= b
// assertMoreOrEqual(lowerBound, actual);       // a >= b
// assertTrue(actual);
// assertFalse(actual);
// assertNull(actual);

// // special cases for floats
// assertEqualFloat(expected, actual, epsilon);    // fabs(a - b) <= epsilon
// assertNotEqualFloat(unwanted, actual, epsilon); // fabs(a - b) >= epsilon
// assertInfinity(actual);                         // isinf(a)
// assertNotInfinity(actual);                      // !isinf(a)
// assertNAN(arg);                                 // isnan(a)
// assertNotNAN(arg);                              // !isnan(a)


#include <ArduinoUnitTests.h>


#include "Arduino.h"
#include "DAC8550.h"


unittest_setup()
{
}

unittest_teardown()
{
}


unittest(test_HW_constructor)
{
  DAC8550 DAC(10);
  DAC.begin();

  for (uint16_t val = 0; val < 65500; val += 30)
  {
    DAC.setValue(val);
    if (DAC.getValue() != val)
    {
      fprintf(stderr, "%d -> %d\n", val, DAC.getValue());
    }
  }
  DAC.setValue(100);
  assertEqual(100, DAC.getValue());
}


unittest(test_SW_constructor)
{
  DAC8550 DAC(4, 5, 6);
  DAC.begin();
  
  for (uint16_t val = 0; val < 65500; val += 30)
  {
    DAC.setValue(val);
    if (DAC.getValue() != val)
    {
      fprintf(stderr, "%d -> %d\n", val, DAC.getValue());
    }
  }
  DAC.setValue(100);
  assertEqual(100, DAC.getValue());
}


unittest(test_powerDown)
{
  DAC8550 DAC(4, 5, 6);
  DAC.begin();
  
  DAC.setPowerDown(DAC8550_POWERDOWN_NORMAL);
  assertEqual(DAC8550_POWERDOWN_NORMAL, DAC.getPowerDownMode());
  
  DAC.setPowerDown(DAC8550_POWERDOWN_1K);
  assertEqual(DAC8550_POWERDOWN_1K, DAC.getPowerDownMode());
  
  DAC.setPowerDown(DAC8550_POWERDOWN_100K);
  assertEqual(DAC8550_POWERDOWN_100K, DAC.getPowerDownMode());
  
  DAC.setPowerDown(DAC8550_POWERDOWN_HIGH_IMP);
  assertEqual(DAC8550_POWERDOWN_HIGH_IMP, DAC.getPowerDownMode());
}


unittest_main()

// --------
