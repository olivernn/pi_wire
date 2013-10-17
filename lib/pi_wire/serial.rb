module PiWire
  class Serial
    attr_reader :name, :baud_rate

    def initialize(name, baud_rate)
      @name = name
      @baud_rate = baud_rate
      open

      if block_given?
        yield self
        close
      end
    end
  end
end
