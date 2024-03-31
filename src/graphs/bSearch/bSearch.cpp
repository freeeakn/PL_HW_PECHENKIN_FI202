/**
 * @file bSearch.cpp
 * @author Arthur Pechenkin
 * @brief Main function of the program
 * @version 0.1
 * @date 01.04.2024
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "bSearch.h"

/**
 * @brief Main function of the program
 * @return 0 on success, non-zero on failure
 */
int main() {
  int n; // Number of vertices in the graph
  int m; // Number of edges in the graph

  std::cout << "Enter the number of vertices: ";
  std::cin >> n;

  std::cout << "Enter the number of edges: ";
  std::cin >> m;

  Graph graph(n);

  std::cout << "Enter the edges of the graph:" << std::endl;
  for (int i = 0; i < m; i++) {
    int u, v; // Edge from vertex u to vertex v

    std::cin >> u >> v;

    graph.addEdge(u, v);
  }

  int start; // Starting vertex

  std::cout << "Enter the starting vertex: ";
  std::cin >> start;

  graph.bfs(start);

  return 0;
}