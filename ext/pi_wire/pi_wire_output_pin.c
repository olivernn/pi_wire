#include <pi_wire_output_pin.h>

static VALUE read(VALUE self) {
  int pin_value = digitalRead(pin_number(self));
  return INT2FIX(pin_value);
}

static VALUE write(VALUE self, VALUE rb_int) {
  digitalWrite(pin_number(self), NUM2INT(rb_int));
  return Qtrue;
}

void Init_pi_wire_output_pin() {
  VALUE cPiWireOutputPin = rb_define_class_under(mPiWire, "OutputPin", cPiWirePin);

  rb_define_method(cPiWireOutputPin, "read", read, 0);
  rb_define_method(cPiWireOutputPin, "write", write, 1);
  rb_define_alias(cPiWireOutputPin, "<<", "write");
}
