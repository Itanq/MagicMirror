
ProjDir=/home/zmant/GitHub/MagicMirror

INCLUDE=-I$(ProjDir)/include \
		-I/usr/include \
		
LDFLAGS=-L$(ProjDir)/build/objs/ \
		-L/usr/lib/x86_64-linux-gnu/ \
		-lopencv_core -lopencv_imgproc -lopencv_highgui

sourcefiles=$(wildcard $(ProjDir)/src/*.cpp)
objfiles=$(addprefix $(ProjDir)/build/objs/,$(subst .cpp,.o,$(notdir $(sourcefiles))))

CXXFLAGS=-std=c++14 -shared -fPIC

$(shell mkdir -p $(ProjDir)/build/objs)
$(shell mkdir -p $(ProjDir)/lib)

.PHONY:all

all:$(ProjDir)/lib/libkcf.so $(ProjDir)/demo
	rm -rf $(ProjDir)/build/objs

$(ProjDir)/demo:$(ProjDir)/demo.cpp
	$(CXX) -Wl,--rpath $(ProjDir)/lib -o $@ $^ -std=c++14 $(INCLUDE) $(LDFLAGS) -L$(ProjDir)/lib -lkcf

$(ProjDir)/lib/libkcf.so:$(objfiles)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

$(ProjDir)/build/objs/kcftracker.o:$(ProjDir)/src/kcftracker.cpp
	$(CXX) -o $@ -c $^ $(CXXFLAGS) $(INCLUDE)

$(ProjDir)/build/objs/fhog.o:$(ProjDir)/src/fhog.cpp
	$(CXX) -o $@ -c $^ $(CXXFLAGS) $(INCLUDE)

clean:
	rm -rf main $(ProjDir)/lib $(ProjDir)/build/objs
