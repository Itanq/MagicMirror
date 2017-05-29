
ProjDir=/home/zmant/GitHub/MagicMirror

INCLUDE=-I$(ProjDir)/include \
		-I/usr/include \
		
LDFLAGS=-L$(ProjDir)/build/objs/ \
		-L/usr/lib/x86_64-linux-gnu/ \
		-l:libkcf.so

sourcefiles=$(wildcard $(ProjDir)/src/*.cpp)
objfiles=$(addprefix $(ProjDir)/build/objs/,$(subst .cpp,.o,$(notdir $(sourcefiles))))

CXXFLAGS=-std=c++14

$(shell mkdir -p $(ProjDir)/build/objs)
$(shell mkdir -p $(ProjDir)/lib)

.PHONY:all

all:$(ProjDir)/lib/libkcf.so
	rm -rf $(ProjDir)/build/objs

$(ProjDir)/lib/libkcf.so:$(objfiles)
	$(CXX) -o $@ $^ $(CXXFLAG) $(LDFLAGS)

$(ProjDir)/build/objs/%.o:$(ProjDir)/src/%.cpp $(ProjDir)/src/%.cpp.d
	$(CXX) -o $@ -c $^ $(CXXFLAGS) $(INCLUDE)

(ProjDir)/src/%.cpp.d:$(ProjDir)/src/%.cpp
	$(CXX) -MM $< -o $@

clean:
	rm -rf main $(ProjDir)/lib
