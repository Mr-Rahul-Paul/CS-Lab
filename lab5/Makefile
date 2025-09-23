CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall
TARGET = knapsack_timing
SOURCE = knapsack_timing.cpp

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCE)

run: $(TARGET)
	./$(TARGET)

plot: run
	python3 plot_results.py

clean:
	rm -f $(TARGET) knapsack_timing_results.csv knapsack_timing_graph.png

.PHONY: all run plot clean
