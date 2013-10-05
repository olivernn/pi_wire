require 'mkmf'

LIBDIR = RbConfig::CONFIG['libdir']
INCLUDEDIR = RbConfig::CONFIG['includedir']

HEADER_DIRS = [
  '/opt/local/include',
  '/usr/local/include',
  INCLUDEDIR,
  '/usr/include'
]

LIB_DIRS = [
  '/opt/local/lib',
  '/usr/local/lib',
  LIBDIR,
  '/usr/lib'
]

dir_config('wiringPi', HEADER_DIRS, LIB_DIRS)

unless find_header('wiringPi.h', *HEADER_DIRS)
  abort 'wiringPi is missing, please install wiringPi'
end

unless find_library('wiringPi', nil, *LIB_DIRS)
  abort 'wiringPi is missing, please install wiringPi'
end

create_makefile('pi_wire/pi_wire')
