#include "PlotsField.h"

/**
 * @brief Main function of the program.
 *
 * This function reads a grid from an input file, counts the number of '#'
 * characters, and then calls the PlotsField function for each '#' character to
 * calculate the total number of plots.
 *
 * @return 0 if the program runs successfully.
 */
int main() {
  // Open the input file
  ifstream inputFile("input.txt");

  // Read the number of rows and columns from the input file
  int rows, cols;
  inputFile >> rows >> cols;

  // Initialize the grid with BUFFER_SIZE
  char grid[BUFFER_SIZE][BUFFER_SIZE];
  // Read the grid from the input file
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      inputFile >> grid[i][j];
    }
  }

  // Close the input file
  inputFile.close();

  // Initialize the count of '#' characters
  int count = 0;
  // Iterate through the grid and count the '#' characters
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (grid[i][j] == '#') {
        // For each '#' character, call the PlotsField function and add the
        // result to the count
        count += PlotsField(grid, rows, cols, i, j);
      }
    }
  }

  // Print the total count of '#' characters
  cout << count << endl;

  // Return 0 to indicate successful program execution
  return 0;
}
