OS = $(shell uname)

ifeq ($(OS),Linux)
	FILENAME = polygons mvc decorator fabric
else
	FILENAME = polygons.exe mvc.exe decoratore.exe fabric.exe
endif
ifeq ($(OS),Darwin)
	FILENAME = polygons mvc decorator fabric
endif

CC = g++
FORMAT = clang-format -i
FLAGS = -std=c++20 -Wall -Werror -Wextra

all:
	$(CC) $(FLAGS) src/polygons/polygons.cpp -o polygons
	$(CC) $(FLAGS) src/controller/mvc.cpp -o mvc
	$(CC) $(FLAGS) src/decorator/decorator.cpp -o decorator
	$(CC) $(FLAGS) src/fabric/fabric.cpp -o fabric

lint:
	$(FORMAT) *.h
	$(FORMAT) *.cpp

clean:
	rm -rf $(FILENAME)