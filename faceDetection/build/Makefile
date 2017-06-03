ProjDir=$(shell pwd)
OutLib=$(ProjDir)/lib
BuildTempDir=$(ProjDir)/build/objs


INCLUDE=-I/usr/include \
		-I$(ProjDir)/include

sourcefiles=$(wildcard $(ProjDir)/src/*.cpp)
objects=$(addprefix $(BuildTempDir)/, $(subst .cpp,.o,$(notdir $(sourcefiles))))

LDFLAGS=-L/usr/lib/x86_64-linux-gnu \
		-lopencv_core -lopencv_highgui -lopencv_imgproc

CXXFLAGS=-Wall -std=c++14 -shared -fPIC

$(shell mkdir -p $(BuildTempDir) $(OutLib))

.PHONY:all

all:$(OutLib)/libfacedetect.so $(ProjDir)/demo
	rm -rf $(BuildTempDir)

$(ProjDir)/demo:$(ProjDir)/facedetection_test.cpp
	$(CXX) -Wl,-rpath=$(OutLib) -o $@ $< $(INCLUDE) $(LDFLAGS) -L$(OutLib) -lfacedetect -std=c++14

$(OutLib)/libfacedetect.so:$(objects)
	$(CXX) -o $@ $^ $(LDFLAGS) $(CXXFLAGS)

$(BuildTempDir)/%.o:$(ProjDir)/src/%.cpp $(ProjDir)/src/%.cpp.d
	$(CXX) -o $@ -c $< $(INCLUDE) $(CXXFLAGS)

$(ProjDir)/src/%.cpp.d:$(ProjDir)/src/%.cpp
	$(CXX) $< -MM $(INCLUDE) $(CXXFLAGS) > $@

clean:
	rm -rf demo $(OutLib)


