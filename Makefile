CC ?= gcc
CFLAGS = -Wall -Wextra
LIBS = -ldl -lm -lSDL2 -lSDL2_image -lSDL2_ttf
BIN_DIR = ./bin

# Installs needed packages
configure:
	chmod u+x ./install.sh && ./install.sh
# Compiles and runs tests
run:
	mkdir -p $(BIN_DIR)
	${CC} tests/main.c $(CFLAGS) -o $(BIN_DIR)/main -Iinclude ./src/*.c $(LIBS)

