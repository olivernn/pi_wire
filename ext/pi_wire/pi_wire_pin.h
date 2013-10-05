#ifndef PI_WIRE_PIN
#define PI_WIRE_PIN

#include <pi_wire.h>

extern VALUE cPiWirePin;

void Init_pi_wire_pin();
int pin_number(VALUE);

#endif
