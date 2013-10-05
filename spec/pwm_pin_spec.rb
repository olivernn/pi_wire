require 'spec_helper'

describe PiWire::PWMPin do
  describe "#number" do
    subject { PiWire::PWMPin.new }
    its(:number) { should == 1 }
  end
end
