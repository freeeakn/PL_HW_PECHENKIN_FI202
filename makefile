.PHONY: all polygons mvc decorator fabric sort bSearch lint clean
OS = $(shell uname)

ifeq ($(OS),Linux)
	FILENAME = polygons mvc decorator fabric sort bSearch
else
	FILENAME = *.exe
endif
ifeq ($(OS),Darwin)
	FILENAME = polygons mvc decorator fabric sort bSearch
endif

CC = g++
FORMAT = clang-format -i
FLAGS = -std=c++20 -Wall -Werror -Wextra

all: polygons mvc decorator fabric sort bSearch
	@echo "all..."

polygons:
	@echo "starts compiling polygons..."
	$(CC) $(FLAGS) src/polygons/polygons.cpp -o polygons
	@echo "all..."

mvc:
	@echo "starts compiling mvc..."
	$(CC) $(FLAGS) src/controller/mvc.cpp -o mvc
	@echo "all..."

decorator:
	@echo "starts compiling decorator..."
	$(CC) $(FLAGS) src/decorator/decorator.cpp -o decorator
	@echo "all..."

fabric:
	@echo "starts compiling fabric..."
	$(CC) $(FLAGS) src/fabric/fabric.cpp -o fabric

sort:
	@echo "starts compiling sort..."
	$(CC) $(FLAGS) src/sorting/sorting.cpp -o sort
	@echo "all..."

bSearch:
	@echo "starts compiling sort..."
	$(CC) $(FLAGS) src/graphs/bSearch/bSearch.cpp -o bSearch
	@echo "all..."

lint:
	@echo "starts linting..."
	$(FORMAT) src/**/*.h
	$(FORMAT) src/**/**/*.h
	$(FORMAT) src/**/*.cpp
	$(FORMAT) src/**/**/*.cpp
	@echo "all..."

clean:
	@echo "Cleaning up..."
	rm -rf $(FILENAME)