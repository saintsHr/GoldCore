SRC := $(wildcard src/*.c)
OBJ := $(patsubst src/%.c, build/%.o, $(SRC))
CFLAGS := -Iinclude -lGL -lGLFW -lopenal -lode
TARGET := GoldCore

all: $(TARGET)

$(TARGET): $(OBJ)
	mkdir -p bin
	gcc $(OBJ) -o bin/$@

build/%.o: src/%.c
	mkdir -p build
	gcc -c $< $(CFLAGS) -o $@

clean:
	rm -rf build $(TARGET)
