MakefileDir=$(shell pwd)/$(lastword $(MAKEFILE_LIST))
BuildDir=$(shell dirname $(MakefileDir))
ProjDir=$(shell dirname $(BuildDir))

OutLib=$(ProjDir)/lib
BuildTmpDir=$(ProjDir)/build/objs

INCLUDE=-I/usr/include \
		-I$(ProjDir)/include \

LDFLAGS=-L/usr/lib/x86_64-linux-gnu \
		-lopencv_core -lopencv_imgproc -lopencv_highgui

sourcefiles=$(wildcard $(ProjDir)/src/*.cpp)
objects=$(addprefix $(BuildTmpDir)/,$(subst .cpp,.o,$(notdir $(sourcefiles))))

CXXFLAGS=-g -Wall -pthread -std=c++11 -Wc++11-compat -shared -fPIC

$(shell mkdir -p $(OutLib) $(BuildTmpDir))


.PHONY:all
	
all:$(OutLib)/libkcf.so $(OutLib)/libkcf.a

$(OutLib)/libkcf.a:$(objects)
	$(AR) rcsf $@ $^

$(OutLib)/libkcf.so:$(objects)
	$(CXX) -o $@ $^ $(LDFLAGS) $(CXXFLAGS)

$(BuildTmpDir)/%.o:$(ProjDir)/src/%.cpp $(ProjDir)/src/%.cpp.d	
	$(CXX) -o $@ -c $< $(CXXFLAGS) $(INCLUDE)

$(ProjDir)/src/%.cpp.d:$(ProjDir)/src/%.cpp
	$(CXX) $< -MM $(CXXFLAGS) $(INCLUDE) > $@

clean:
	rm -rf $(OutLib) $(BuildTmpDir)

