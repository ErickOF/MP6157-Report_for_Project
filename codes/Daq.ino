#include "KalmanFilter.hpp"
#include <LM35.h>


// Pin for the temperature sensor
#define PIN_TEMPERATURE A0
// Pin for the the heating system status
#define PIN_STATUS 8
// Posible system status
#define SYSTEM_ON 1
#define SYSTEM_OFF 0

// Kalman Filter parameters
#define SYS_VAR 1
// -- Time constant of the system
#define TAU 20
// -- Gain of the system
#define Kp 0.5
// -- Sampling time
#define DELTA_T 1
// -- System dynamic
#define A (-1 / TAU)
#define B (Kp / TAU)


// Temperature sensor
LM35 lm35(PIN_TEMPERATURE);

// Kalman Filter
KalmanFilter<SYS_VAR> kf;

// Variable to store the temperature
double temperature;
// Variable for the system status
bool system_status;

// Kalman filter variables
double pk[SYS_VAR][SYS_VAR];
double xk[SYS_VAR][1];
double y[SYS_VAR][1];
double uk[SYS_VAR][1];
// Kalmen filter predictions
double pk1[SYS_VAR][SYS_VAR];
double xk1[SYS_VAR][1];

void setup()
{
  // Setup temperature data pin
  pinMode(PIN_TEMPERATURE, INPUT);

  // Setup system status switch
  pinMode(PIN_STATUS, INPUT);

  // Setting values
  temperature = 1.0;
  system_status = SYSTEM_OFF;

  // Set Kalman Filter parameters
  double h[1][SYS_VAR] = {{1.0}};
  double r = 0.0064;
  double phi[SYS_VAR][SYS_VAR] = {{0.6065}};
  double gamma[SYS_VAR][SYS_VAR] = {{0.1967}};
  double q[SYS_VAR][SYS_VAR] = {{1.0}};
  xk[0][0] = 1.0;
  pk[0][0] = 1.0;
  kf.set_params(h, r, phi, gamma, q);

  // Serial communication
  Serial.begin(9600);
}

void loop()
{
  // Read the temperature
  temperature = lm35.getTemp(CELCIUS);
  y[0][0] = temperature;
  // Read the system status
  system_status = digitalRead(PIN_STATUS);
  uk[0][0] = 10 * system_status;
  // Predict system behav
  kf.predict(xk, pk, y, uk, xk1, pk1);

  xk[0][0] = xk1[0][0];
  pk[0][0] = pk1[0][0];

  delay(999);
}
