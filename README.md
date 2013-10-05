# PiWire

PiWire is a ruby wrapper around the [wiringPi](http://wiringpi.com) C library.

## Installation

PiWire requires the wiringPi library be installed to work, make sure you have succesfully installed wiringPi _before_ trying to install PiWire.

Add this line to your application's Gemfile:

    gem 'pi_wire'

And then execute:

    $ bundle

Or install it yourself as:

    $ gem install pi_wire

## Usage

As with wiringPi you must initialize PiWire before you start using it.

    PiWire.init

If you don't do this then at best things wont work, and at worst your program will crash.

### LED Blink

This is effectively the hello world program of electronics:

    require 'pi_wire'

    PiWire.init

    pin = PiWire::OutputPin.new(1)

    loop do
      pin.toggle!
      sleep 0.5
    end

### Output Pin

A new output pin can be created, specifiying the wiringPi pin number to use:

    pin = PiWire::OutputPin.new(0)

You can now read and write from this pin:

    pin.read # will return PiWire::LOW (0) or PiWire::HIGH (1)
    pin.write PiWire::HIGH

### PWM Pin

A new PWM pin can be created, this will use pin number 1 by default.

    pin = PiWire::PWMPin.new

You can write to this pin, by default the range is from 0 to 1023

    pin.write 512

## Tests

Run the tests with `rake`, these must be run as a superuser.

## Contributing

1. Fork it
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create new Pull Request
