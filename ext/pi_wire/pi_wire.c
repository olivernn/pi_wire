#include <ruby.h>

static VALUE hello_world(VALUE klass) {
  return rb_str_new2("Hello, World!");
}

void Init_pi_wire() {
  VALUE mPiWire = rb_define_module("PiWire");
  rb_define_module_function(mPiWire, "hello_world", hello_world, 0);
}
