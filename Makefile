C_FILES := $(wildcard src/*.c)
CC_FLAGS := -std=c11 -Iinclude -DDEBUG
LIBS := 
PLATFORM_FLAGS := 

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	PLATFORM_FLAGS += -DLINUX
	C_FILES += src/platform/linux.c
endif
ifeq ($(UNAME_S),Darwin)
	PLATFORM_FLAGS += -DMAC
	C_FILES += src/platform/mac.c
	LIBS += -framework Hypervisor
endif

OBJ_FILES := $(C_FILES:.c=.o)

all: libhyper.dylib test

libhyper.dylib: $(OBJ_FILES)
	clang -g $(CC_FLAGS) $(PLATFORM_FLAGS) -dynamiclib $(LIBS) -o libhyper.dylib $(OBJ_FILES)

%.o: %.c
	clang $(CC_FLAGS) $(PLATFORM_FLAGS) -c -g -o $@ $<

test: test/test.c libhyper.dylib
	clang -g -Iinclude -DDEBUG $(PLATFORM_FLAGS) -std=c11 -L. -lhyper test/test.c -o test/test

clean:
	rm src/*.o || true
	rm src/platform/*.o || true
	rm libhyper.dylib
	rm test/test || true
