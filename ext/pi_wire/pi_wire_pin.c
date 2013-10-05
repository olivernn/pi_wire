#include <pi_wire_pin.h>

VALUE cPiWirePin;

int pin_number(VALUE self) {
  VALUE pin_number = rb_ivar_get(self, rb_intern("@number"));
  return NUM2INT(pin_number);
}

static VALUE set_mode(VALUE self, VALUE rb_int) {
  pinMode(pin_number(self), NUM2INT(rb_int));
  return Qtrue;
}

void Init_pi_wire_pin() {
  cPiWirePin = rb_define_class_under(mPiWire, "Pin", rb_cObject);

  rb_define_private_method(cPiWirePin, "mode=", set_mode, 1);
}
