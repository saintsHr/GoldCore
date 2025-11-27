SRC := $(wildcard src/*.c)
LIB_SRC := $(filter-out src/main.c, $(SRC))
LIB_OBJ := $(patsubst src/%.c, build/%.o, $(LIB_SRC))
MAIN_OBJ := $(patsubst src/%.c, build/%.o, src/main.c)

CFLAGS  := -Iinclude
LDFLAGS := -lGL -lglfw -lopenal -lode -lm

TARGET := GoldCore
STATIC := lib$(TARGET).a

all: bin/$(TARGET)
lib: lib/$(STATIC)

bin/$(TARGET): $(MAIN_OBJ)
	mkdir -p bin
	gcc $(MAIN_OBJ) -Llib -l$(TARGET) -o $@ $(LDFLAGS)

lib/$(STATIC): $(LIB_OBJ)
	mkdir -p lib
	ar rcs $@ $(LIB_OBJ)

build/%.o: src/%.c
	mkdir -p build
	gcc -c $< $(CFLAGS) -o $@

clean:
	rm -rf build bin lib
