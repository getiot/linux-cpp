CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -g
LDFLAGS = -lboost_python38 -lboost_numpy38 -lpython3.8 -lstdc++ -lm
INCLUDE_DIRS = -I/usr/include/python3.8
SRCS := $(wildcard *.cpp)
EXES := $(SRCS:.cpp=)

all: $(EXES)

%: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(EXES)

.PHONY: all clean