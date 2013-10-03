# coding: utf-8
lib = File.expand_path('../lib', __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require 'pi_wire/version'

Gem::Specification.new do |spec|
  spec.name          = "pi_wire"
  spec.version       = PiWire::VERSION
  spec.authors       = ["Oliver Nightingale"]
  spec.email         = ["oliver.nightingale1@gmail.com"]
  spec.description   = %q{Ruby bindings to WiringPi}
  spec.summary       = %q{Ruby bindings to WiringPi}
  spec.homepage      = ""
  spec.license       = "MIT"

  spec.files         = `git ls-files`.split($/)
  spec.executables   = spec.files.grep(%r{^bin/}) { |f| File.basename(f) }
  spec.test_files    = spec.files.grep(%r{^(test|spec|features)/})
  spec.require_paths = ["lib"]
  spec.extensions   << "ext/pi_wire/extconf.rb"

  spec.add_development_dependency "bundler", "~> 1.3"
  spec.add_development_dependency "rake"
  spec.add_development_dependency "rake-compiler"
end
