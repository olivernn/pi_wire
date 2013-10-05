module PiWire
  class PWMPin < PiWire::Pin
    attr_reader :number

    def initialize
      @number = 1
      self.mode = PiWire::PWM_MODE
    end
  end
end
