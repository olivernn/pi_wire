#include <pi_wire_serial.h>

static char *get_file_name(VALUE self) {
  VALUE rb_file_name = rb_ivar_get(self, rb_intern("@name"));
  return StringValueCStr(rb_file_name);
}

static int get_baud_rate(VALUE self) {
  VALUE rb_baud_rate = rb_ivar_get(self, rb_intern("@baud_rate"));
  return NUM2INT(rb_baud_rate);
}

static int get_fd(VALUE self) {
  VALUE rb_fd = rb_ivar_get(self, rb_intern("@fd"));
  return NUM2INT(rb_fd);
}

static VALUE open_serial_file(VALUE self) {
  char *file_name = get_file_name(self);
  int baud_rate = get_baud_rate(self);
  int fd = serialOpen(file_name, baud_rate);

  if (fd == -1) {
    rb_raise(rb_eRuntimeError, "Couldn't open %s", file_name);
  }

  rb_ivar_set(self, rb_intern("@fd"), INT2NUM(fd));
  return Qnil;
}

static VALUE serial_write(VALUE self, VALUE str) {
  int fd = get_fd(self);
  char *s = StringValueCStr(str);
  serialPuts(fd, s);
  return Qtrue;
}

static VALUE serial_read(VALUE self) {
  int fd = get_fd(self);
  int chars_available = serialDataAvail(fd);
  int i;
  char *str = malloc(chars_available + 2);

  if (chars_available == -1) {
    rb_raise(rb_eRuntimeError, "No data to read");
    return Qnil;
  }

  for (i = 0; i < chars_available; i++) {
    str[i] = serialGetchar(fd);
  }

  str[chars_available +1] = '\0';

  return rb_str_new2(str);
}

static VALUE serial_close(VALUE self) {
  int fd = get_fd(self);
  serialClose(fd);
  return Qtrue;
}

void Init_pi_wire_serial() {
  VALUE cPiWireSerial = rb_define_class_under(mPiWire, "Serial", rb_cObject);

  rb_define_method(cPiWireSerial, "write", serial_write, 1);
  rb_define_method(cPiWireSerial, "read", serial_read, 0);
  rb_define_method(cPiWireSerial, "close", serial_close, 0);

  rb_define_private_method(cPiWireSerial, "open", open_serial_file, 0);
}
