CPP_FILES := $(wildcard src/*.cpp)
CC_FLAGS := -std=c++14 -Iinclude -DDEBUG
LIBS := 
PLATFORM_FLAGS := 

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	PLATFORM_FLAGS += -DLINUX
endif
ifeq ($(UNAME_S),Darwin)
	PLATFORM_FLAGS += -DMAC
	LIBS += -framework Hypervisor
endif

OBJ_FILES := $(CPP_FILES:.cpp=.o)

all: libhyper.dylib test

libhyper.dylib: $(OBJ_FILES)
	clang++ -g $(CC_FLAGS) $(PLATFORM_FLAGS) -dynamiclib $(LIBS) -o libhyper.dylib $(OBJ_FILES)

%.o: %.cpp
	clang++ $(CC_FLAGS) $(PLATFORM_FLAGS) -c -g -o $@ $<

test: test/test.cpp libhyper.dylib
	clang++ -g -Iinclude -DDEBUG $(PLATFORM_FLAGS) -std=c++14 -L. -lhyper test/test.cpp -o test/test

clean:
	rm src/*.o || true
	rm src/platform/*.o || true
	rm libhyper.dylib
	rm test/test || true
