#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int x, y, turns, time;
    Point(int _x, int _y, int _turns, int _time) : x(_x), y(_y), turns(_turns), time(_time) {}
};

/**
 * Performs a breadth-first search (BFS) on a 2D grid to find the shortest path from a start point to an end point.
 * The grid is represented as a 2D vector of integers, where 0 represents an empty cell and 1 represents an obstacle.
 * The function also takes into account the maximum number of turns allowed during the search.
 *
 * @param grid The 2D grid representing the environment.
 * @param startX The x-coordinate of the start point.
 * @param startY The y-coordinate of the start point.
 * @param endX The x-coordinate of the end point.
 * @param endY The y-coordinate of the end point.
 * @param maxTurns The maximum number of turns allowed during the search.
 *
 * @return The shortest time taken to reach the end point from the start point, or -1 if no path is found.
 */
int bfs(vector<vector<int>>& grid, int startX, int startY, int endX, int endY, int maxTurns) {
    int n = grid.size(), m = grid[0].size();
    // visited[x][y][turns] is true if cell (x, y) has been visited with 'turns' number of turns.
    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(maxTurns + 1, false)));
    queue<Point> q;
    q.push(Point(startX, startY, 0, 0));
    visited[startX][startY][0] = true;

    int dx[] = { 1, 0, -1, 0 };
    int dy[] = { 0, 1, 0, -1 };

    while (!q.empty()) {
        Point p = q.front();
        q.pop();

        if (p.x == endX && p.y == endY) {
            return p.time;
        }

        for (int i = 0; i < 4; ++i) {
            int newX = p.x + dx[i];
            int newY = p.y + dy[i];
            int newTurns = p.turns;
            int newTime = p.time + 1;

            // If the direction of movement is not the same as the previous movement, increment the number of turns.
            if (i!= 0) {
                newTurns++;
            }

            // Check if the new cell is within the grid boundaries, not an obstacle, and the number of turns does not exceed the maximum allowed turns.
            if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY]!= 1 && newTurns <= maxTurns) {
                if (!visited[newX][newY][newTurns]) {
                    visited[newX][newY][newTurns] = true;
                    q.push(Point(newX, newY, newTurns, newTime));
                }
            }
        }
    }

    return -1;
}
