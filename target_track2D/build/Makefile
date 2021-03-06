
MakefileDir=$(shell pwd)/$(lastword $(MAKEFILE_LIST))
BuildDir=$(shell dirname $(MakefileDir))
ProjDir=$(shell dirname $(BuildDir))

3rdparty=$(ProjDir)/../3rdParty

INCLUDE=-I/usr/include \
		-I$(ProjDir)/include \
		-I$(3rdparty)/KCFTracker/include \
		
LDFLAGS=-L/usr/lib/x86_64-linux-gnu \
		-L$(ProjDir)/build/objs \
		-L$(3rdparty)/KCFTracker/lib \
		-l:libkcf.a -lopencv_core -lopencv_imgproc -lopencv_highgui

sourcefiles=$(wildcard $(ProjDir)/src/*.cpp)
objfiles=$(addprefix $(ProjDir)/build/objs/,$(subst .cpp,.o,$(notdir $(sourcefiles))))

CXXFLAGS=-std=c++14 -shared -fPIC

$(shell mkdir -p $(ProjDir)/build/objs)
$(shell mkdir -p $(ProjDir)/lib)

.PHONY:all

all:$(ProjDir)/lib/libtracker.so $(ProjDir)/demo
	rm -rf $(ProjDir)/build/objs

$(ProjDir)/demo:$(ProjDir)/demo.cpp
	$(CXX) -Wl,--rpath $(ProjDir)/lib -o $@ $^ -std=c++14 $(INCLUDE) $(LDFLAGS) -L$(ProjDir)/lib -ltracker

$(ProjDir)/lib/libtracker.so:$(objfiles)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

$(ProjDir)/build/objs/%.o:$(ProjDir)/src/%.cpp $(ProjDir)/build/objs/%.cpp.d
	$(CXX) -o $@ -c $< $(CXXFLAGS) $(INCLUDE)

$(ProjDir)/build/objs/%.cpp.d:$(ProjDir)/src/%.cpp
	$(CXX) $< -MM $(CXXFLAGS) $(INCLUDE) > $@

clean:
	rm -rf $(ProjDir)/demo $(ProjDir)/lib $(ProjDir)/build/objs
