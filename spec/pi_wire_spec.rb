require 'spec_helper'

describe PiWire do
  its(:hello_world) { should == "Hello, World!" }

  describe "#init" do
    it { PiWire.init.should be_true }
  end
end
