
MakefileDir=$(shell pwd)/$(lastword $(MAKEFILE_LIST))
BuildDir=$(shell dirname $(MakefileDir))
ProjDir=$(shell dirname $(BuildDir))

OutLib=$(ProjDir)/lib
3rdparty=$(ProjDir)/../3rdParty
BuildTempDir=$(ProjDir)/build/objs


INCLUDE=-I/usr/include \
		-I$(ProjDir)/include \
		-I$(3rdparty)/SeetaFaceEigen/FaceDetection/include \
		-I$(3rdparty)/SeetaFaceEigen/FaceIdentification/include

sourcefiles=$(wildcard $(ProjDir)/src/*.cpp)
objects=$(addprefix $(BuildTempDir)/, $(subst .cpp,.o,$(notdir $(sourcefiles))))

LDFLAGS=-L/usr/lib/x86_64-linux-gnu \
		-L$(3rdparty)/SeetaFaceEigen/FaceDetection/lib \
		-l:libstfd.a -lopencv_core -lopencv_highgui -lopencv_imgproc

CXXFLAGS=-Wall -std=c++14 -shared -fPIC

$(shell mkdir -p $(BuildTempDir) $(OutLib))

.PHONY:all

all:$(OutLib)/libfaceident.so $(OutLib)/libfaceident.a $(ProjDir)/demo
	rm -rf $(BuildTempDir)

$(ProjDir)/demo:$(ProjDir)/demo.cpp
	$(CXX) -Wl,-rpath=$(OutLib) -o $@ $< $(INCLUDE) $(LDFLAGS) -L$(OutLib) -lfaceident -std=c++14

$(OutLib)/libfaceident.a:$(objects)
	$(AR) rcsf $@ $(objects)

$(OutLib)/libfaceident.so:$(objects)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

$(BuildTempDir)/%.o:$(ProjDir)/src/%.cpp $(ProjDir)/src/%.cpp.d
	$(CXX) -o $@ -c $< $(CXXFLAGS) $(INCLUDE)

$(ProjDir)/src/%.cpp.d:$(ProjDir)/src/%.cpp
	$(CXX) $< -MM $(CXXFLAGS) $(INCLUDE) > $@

clean:
	rm -rf $(ProjDir)/demo $(OutLib) $(BuildTempDir)


