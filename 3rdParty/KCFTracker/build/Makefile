
MakefileDir=$(shell pwd)/$(lastword $(MAKEFILE_LIST))
BuildDir=$(shell dirname $(MakefileDir))
ProjDir=$(shell dirname $(BuildDir))

INCLUDE=-I/usr/include \
		-I$(ProjDir)/include \
		
LDFLAGS=-L/usr/lib/x86_64-linux-gnu \
		-L$(ProjDir)/build/objs \
		-L$(3rdpary)/KCFTracker/lib \
		-lopencv_core -lopencv_imgproc -lopencv_highgui

sourcefiles=$(wildcard $(ProjDir)/src/*.cpp)
objfiles=$(addprefix $(ProjDir)/build/objs/,$(subst .cpp,.o,$(notdir $(sourcefiles))))

CXXFLAGS=-std=c++14 -shared -fPIC

$(shell mkdir -p $(ProjDir)/build/objs)
$(shell mkdir -p $(ProjDir)/lib)

.PHONY:all

all:$(ProjDir)/lib/libkcf.so $(ProjDir)/lib/libkcf.a
	rm -rf $(ProjDir)/build/objs

$(ProjDir)/lib/libkcf.a:$(objfiles)
	$(AR) rcsf $@ $^

$(ProjDir)/lib/libkcf.so:$(objfiles)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

$(ProjDir)/build/objs/%.o:$(ProjDir)/src/%.cpp $(ProjDir)/build/objs/%.cpp.d
	$(CXX) -o $@ -c $< $(CXXFLAGS) $(INCLUDE)

$(ProjDir)/build/objs/%.cpp.d:$(ProjDir)/src/%.cpp
	$(CXX) $< -MM $(CXXFLAGS) $(INCLUDE) > $@

clean:
	rm -rf $(ProjDir)/lib

