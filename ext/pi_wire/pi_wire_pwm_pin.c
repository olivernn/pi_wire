#include <pi_wire_pwm_pin.h>

static VALUE write(VALUE self, VALUE rb_int) {
  pwmWrite(pin_number(self), NUM2INT(rb_int));
  return Qtrue;
}

void Init_pi_wire_pwm_pin() {
  VALUE cPiWirePWMPin = rb_define_class_under(mPiWire, "PWMPin", cPiWirePin);

  rb_define_method(cPiWirePWMPin, "write", write, 1);
  rb_define_alias(cPiWirePWMPin, "<<", "write");
}
