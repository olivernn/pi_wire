require 'spec_helper'

describe PiWire do
  its(:hello_world) { should == "Hello, World!" }

  describe "constants" do
    it { PiWire::OUTPUT_MODE.should == 1 }
  end
end
