CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra
LIBS := -pthread
SRCS := $(wildcard *.cpp)
EXES := $(SRCS:.cpp=)

all: $(EXES)

%: %.cpp
	$(CXX) $(CXXFLAGS) $(LIBS) -o $@ $^

clean:
	rm -f $(EXES)

.PHONY: all clean