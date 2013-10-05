#ifndef PI_WIRE
#define PI_WIRE

#include <ruby.h>
#include <wiringPi.h>

extern VALUE mPiWire;

void Init_pi_wire();

#include <pi_wire_pin.h>
#include <pi_wire_output_pin.h>
#include <pi_wire_pwm_pin.h>

#endif
