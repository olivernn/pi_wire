#include <pi_wire_output_pin.h>

static int pin_number(VALUE self) {
  VALUE pin_number = rb_ivar_get(self, rb_intern("@number"));
  return NUM2INT(pin_number);
}

static VALUE set_mode(VALUE self, VALUE rb_int) {
  pinMode(pin_number(self), NUM2INT(rb_int));
  return Qtrue;
}

static VALUE read(VALUE self) {
  int pin_value = digitalRead(pin_number(self));
  return INT2FIX(pin_value);
}

static VALUE write(VALUE self, VALUE rb_int) {
  digitalWrite(pin_number(self), NUM2INT(rb_int));
  return Qtrue;
}

void Init_pi_wire_output_pin() {
  VALUE cPiWireOutputPin = rb_define_class_under(mPiWire, "OutputPin", rb_cObject);

  rb_define_method(cPiWireOutputPin, "read", read, 0);
  rb_define_method(cPiWireOutputPin, "write", write, 1);
  rb_define_alias(cPiWireOutputPin, "<<", "write");

  rb_define_private_method(cPiWireOutputPin, "mode=", set_mode, 1);
}
