SRC := $(wildcard src/*.c)
OBJ := $(patsubst src/%.c, build/%.o, $(SRC))

CFLAGS  := -Iinclude
LDFLAGS := -lGL -lglfw -lopenal -lode -lm

TARGET := GoldCore

all: $(TARGET)

$(TARGET): $(OBJ)
	mkdir -p bin
	gcc $(OBJ) -o bin/$@ $(LDFLAGS)

build/%.o: src/%.c
	mkdir -p build
	gcc -c $< $(CFLAGS) -o $@

clean:
	rm -rf build bin