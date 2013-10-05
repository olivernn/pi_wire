#include <pi_wire.h>

VALUE mPiWire;

static VALUE hello_world(VALUE klass) {
  return rb_str_new2("Hello, World!");
}

static VALUE init_wiring_pi(VALUE klass) {
  wiringPiSetup();
  return Qtrue;
}

void Init_pi_wire() {
  mPiWire = rb_define_module("PiWire");
  rb_define_module_function(mPiWire, "hello_world", hello_world, 0);
  rb_define_module_function(mPiWire, "init", init_wiring_pi, 0);

  rb_define_const(mPiWire, "OUTPUT_MODE", INT2FIX(OUTPUT));

  rb_define_const(mPiWire, "LOW", INT2FIX(LOW));
  rb_define_const(mPiWire, "HIGH", INT2FIX(HIGH));

  Init_pi_wire_pin();
}
