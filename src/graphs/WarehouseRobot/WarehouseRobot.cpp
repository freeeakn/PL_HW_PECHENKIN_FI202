#include "WarehouseRobot.h"

/**
 * @brief Main function of the warehouse robot simulation.
 *
 * This function reads the grid size, the grid itself, the start and end positions, and the maximum turns.
 * It then calls the bfs function to find the minimum time required for the robot to reach the end position.
 *
 * @return 0 to indicate successful program execution.
 */
int main() {
    int n, m;
    cin >> n >> m;  // Read the grid size

    // Initialize the grid with zeros
    vector<vector<int>> grid(n, vector<int>(m));

    int startX, startY, endX, endY;  // Variables to store the start and end positions

    // Read the grid and find the start and end positions
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];  // Read the grid cell value

            // If the cell value is 2, it's the start position
            if (grid[i][j] == 2) {
                startX = i;
                startY = j;
            }
            // If the cell value is 3, it's the end position
            else if (grid[i][j] == 3) {
                endX = i;
                endY = j;
            }
        }
    }

    int maxTurns;  // Variable to store the maximum turns
    cin >> maxTurns;  // Read the maximum turns

    // Call the bfs function to find the minimum time required to reach the end position
    int minTime = bfs(grid, startX, startY, endX, endY, maxTurns);

    cout << minTime << endl;  // Print the minimum time

    return 0;  // Indicate successful program execution
}