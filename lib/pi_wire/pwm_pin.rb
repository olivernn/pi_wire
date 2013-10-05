module PiWire
  class PWMPin < Pin
    def initialize
      @number = 1
      self.mode = PiWire::PWM_MODE
    end
  end
end
