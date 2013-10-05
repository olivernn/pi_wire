require 'spec_helper'

describe PiWire::OutputPin do
  describe "#initialise" do
    subject(:pin) { PiWire::OutputPin.new(1) }
    its(:number) { should == 1 }
  end

  describe "#low?" do
    let(:pin) { PiWire::OutputPin.new(1) }

    subject { pin.low? }

    context "yes" do
      before { pin.stub(:read).and_return(PiWire::LOW) }
      it { should be_true }
    end

    context "no" do
      before { pin.stub(:read).and_return(PiWire::HIGH) }
      it { should be_false }
    end
  end

  describe "#high?" do
    let(:pin) { PiWire::OutputPin.new(1) }

    subject { pin.high? }

    context "yes" do
      before { pin.stub(:read).and_return(PiWire::HIGH) }
      it { should be_true }
    end

    context "no" do
      before { pin.stub(:read).and_return(PiWire::LOW) }
      it { should be_false }
    end
  end

  describe "#read" do
    subject(:pin) { PiWire::OutputPin.new(1) }

    context "high" do
      before { pin << PiWire::HIGH }
      it { should be_high }
    end

    context "low" do
      before { pin << PiWire::LOW }
      it { should be_low }
    end
  end

  describe "#high!" do
    subject(:pin) { PiWire::OutputPin.new(1) }

    context "currently high" do
      before { pin << PiWire::HIGH }

      it "sets the pin high" do
        pin.high!
        pin.should be_high
      end
    end

    context "currently low" do
      before { pin << PiWire::LOW }

      it "sets the pin high" do
        pin.high!
        pin.should be_high
      end
    end
  end

  describe "#low!" do
    subject(:pin) { PiWire::OutputPin.new(1) }

    context "currently high" do
      before { pin << PiWire::HIGH }

      it "sets the pin low" do
        pin.low!
        pin.should be_low
      end
    end

    context "currently low" do
      before { pin << PiWire::LOW }

      it "sets the pin low" do
        pin.low!
        pin.should be_low
      end
    end
  end

  describe "toggle!" do
    subject(:pin) { PiWire::OutputPin.new(1) }

    context "currently high" do
      before { pin << PiWire::HIGH }

      it "sets the pin low" do
        pin.toggle!
        pin.should be_low
      end
    end

    context "currently low" do
      before { pin << PiWire::LOW }

      it "sets the pin high" do
        pin.toggle!
        pin.should be_high
      end
    end
  end
end
