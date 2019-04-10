class Greeting
	def initialize(text)
		@text = text
	end

	def welcome
		@text
	end
end

my_object = Greeting.new("Hello")
my_object.class
my_object.class.instance_methods(false)
my_object.instance_variables