#include <LM35.h>

// Temperature sensor
LM35 lm35(PIN_ANA_TEMPERATURE);
// Read the temperature
temperature = lm35.getTemp(CELCIUS);
