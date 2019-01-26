CXX=g++

INCLUDE=-Idependencies/zydis/include/ -Isrc/include

CXXFLAGS=-std=c++11 -Wall -Wextra -O3 -g
LDFLAGS=dependencies/zydis/build/libZydis.a

obt: $(wildcard src/*.cpp src/*.hpp src/**/*.cpp src/**/*.hpp)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $^ $(LDFLAGS) -o $@
	
