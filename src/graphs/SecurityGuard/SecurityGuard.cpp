#include "SecurityGuard.h"

#include "SecurityGuard.h"

int main() {
    ifstream inputFile("input.txt");
    
    int rows, cols;
    inputFile >> rows >> cols;

    char grid[BUFFER_SIZE][BUFFER_SIZE];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            inputFile >> grid[i][j];
        }
    }
    
    inputFile.close();

    int count = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == '#') {
                count += countIslands(grid, rows, cols, i, j);
            }
        }
    }

    cout << count << endl;

    return 0;
}
