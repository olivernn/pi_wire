module PiWire
  class OutputPin < PiWire::Pin
    attr_reader :number

    def initialize(number)
      @number = number
      self.mode = PiWire::OUTPUT_MODE
    end

    def low?
      read == PiWire::LOW
    end

    def high?
      read == PiWire::HIGH
    end

    def low!
      write PiWire::LOW
    end

    def high!
      write PiWire::HIGH
    end

    def toggle!
      low? ? high! : low!
    end
  end
end
