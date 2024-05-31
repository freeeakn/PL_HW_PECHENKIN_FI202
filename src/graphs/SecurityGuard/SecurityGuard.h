#include <iostream>
#include <fstream>
using namespace std;

#define BUFFER_SIZE 100

int countIslands(char grid[][BUFFER_SIZE], int rows, int cols, int i, int j) {
    if (grid[i][j] != '#') {
        return 0;
    }

    grid[i][j] = '.';

    countIslands(grid, rows, cols, i + 1, j);
    countIslands(grid, rows, cols, i - 1, j);
    countIslands(grid, rows, cols, i, j + 1);
    countIslands(grid, rows, cols, i, j - 1);

    return 1;
}
