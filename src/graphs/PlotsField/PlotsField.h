#include <fstream>
#include <iostream>
using namespace std;

#define BUFFER_SIZE 100

/**
 * Function to recursively plot a field of '#' characters in a 2D grid.
 *
 * @param grid 2D character array representing the grid.
 * @param rows Number of rows in the grid.
 * @param cols Number of columns in the grid.
 * @param i Row index of the current cell.
 * @param j Column index of the current cell.
 *
 * @return 1 if a '#' character was found and plotted, 0 otherwise.
 *
 * The function uses a depth-first search approach to explore the grid.
 * It marks the current cell as '.' and recursively calls itself for its
 * neighboring cells. If a '#' character is found, it marks it as '.' and
 * returns 1. If no '#' character is found, it returns 0.
 */
int PlotsField(char grid[][BUFFER_SIZE], int rows, int cols, int i, int j) {
  if (grid[i][j] != '#') {
    return 0;
  }

  grid[i][j] = '.';

  PlotsField(grid, rows, cols, i + 1, j);
  PlotsField(grid, rows, cols, i - 1, j);
  PlotsField(grid, rows, cols, i, j + 1);
  PlotsField(grid, rows, cols, i, j - 1);

  return 1;
}
