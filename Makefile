all: testing

testing: src/testing.cpp
	@echo "---"
	@echo "Compiling testing.cpp"

	g++ -pthread src/testing.cpp src/myLogger.cpp -o testing

	@echo "Finished compiling testing.cpp"