CXX=g++

INCLUDE=-Idependencies/zydis/include/

CXXFLAGS=-std=c++11 -Wall -Wextra -O3 -g
LDFLAGS=dependencies/zydis/build/libZydis.a

odb: $(wildcard src/*.cpp src/*.hpp)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $^ $(LDFLAGS) -o $@
	
