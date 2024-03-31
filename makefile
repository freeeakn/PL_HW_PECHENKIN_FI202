OS = $(shell uname)

ifeq ($(OS),Linux)
	FILENAME = polygons mvc decorator fabric sort
else
	FILENAME = polygons.exe mvc.exe decoratore.exe fabric.exe sort.exe
endif
ifeq ($(OS),Darwin)
	FILENAME = polygons mvc decorator fabric sort
endif

CC = g++
FORMAT = clang-format -i
FLAGS = -std=c++20 -Wall -Werror -Wextra

all:
	$(CC) $(FLAGS) src/polygons/polygons.cpp -o polygons
	$(CC) $(FLAGS) src/controller/mvc.cpp -o mvc
	$(CC) $(FLAGS) src/decorator/decorator.cpp -o decorator
	$(CC) $(FLAGS) src/fabric/fabric.cpp -o fabric
	$(CC) $(FLAGS) src/sorting/sorting.cpp -o sort

polygons:
	$(CC) $(FLAGS) src/polygons/polygons.cpp -o polygons

mvc:
	$(CC) $(FLAGS) src/controller/mvc.cpp -o mvc

decorator:
	$(CC) $(FLAGS) src/decorator/decorator.cpp -o decorator

fabric:
	$(CC) $(FLAGS) src/fabric/fabric.cpp -o fabric

sort:
	$(CC) $(FLAGS) src/sorting/sorting.cpp -o sort

lint:
	$(FORMAT) src/**/*.h
	$(FORMAT) src/**/*.cpp

clean:
	rm -rf $(FILENAME)