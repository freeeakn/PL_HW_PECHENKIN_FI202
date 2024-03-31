#ifndef BSEARCH_H
#define BSEARCH_H
/**
 * @file bSearch.h
 * @author Arthur Pechenkin
 * @brief Header file of the program
 * @version 0.1
 * @date 01.04.2024
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "../../queue/queue.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * @class Graph
 * @brief Class of the graph
 */
class Graph {
private:
  vector<vector<int>> adjacencyMatrix; // Матрица смежности графа

public:
  /**
   * @brief constructs a graph with n vertices
   * @param n number of vertices in the graph
   */
  Graph(int n) { adjacencyMatrix.resize(n, vector<int>(n, 0)); }

  /**
   * @brief adds an edge to the graph
   * @param u first vertex
   * @param v second vertex
   */
  void addEdge(int u, int v) {
    // Add an edge from vertex u to vertex v
    adjacencyMatrix[u][v] = 1;
    // Add an edge from vertex v to vertex u (for undirected graphs)
    adjacencyMatrix[v][u] = 1;
  }

  /**
   * @brief performs a breadth-first search on a graph
   * @param start the starting vertex of the search
   * @return a vector containing the distances from the starting vertex to each
   * vertex in the graph
   */
  vector<int> bfs(int start) {
    int size = adjacencyMatrix.size(); // number of vertices in the graph

    vector<bool> visited(size, false); // boolean array to mark visited vertices
    vector<int> distance(size, -1);    // array to store distances to vertices
    vector<int> parent(size, -1);      // array to store parents of vertices

    Queue q; // queue for traversing vertices

    visited[start] = true; // mark the starting vertex as visited
    distance[start] = 0;   // set the distance to the starting vertex to 0
    q.enqueue(start);      // add the starting vertex to the queue

    while (!q.isEmpty()) {
      int current = q.dequeue(); // get the next vertex from the queue

      // traverse the neighbors of the current vertex
      for (int neighbor = 0; neighbor < size; neighbor++) {
        if (adjacencyMatrix[current][neighbor] == 1 && !visited[neighbor]) {
          // if there is an edge from the current vertex to the neighbor and the
          // neighbor is not visited
          visited[neighbor] = true; // mark the neighbor as visited
          distance[neighbor] =
              distance[current] + 1;  // update the distance to the neighbor
          parent[neighbor] = current; // update the parent of the neighbor
          q.enqueue(neighbor);        // add the neighbor to the queue
        }
      }
    }

    return distance; // return the distances from the starting vertex
  }

  /**
   * @brief performs a breadth-first search on a graph
   * @param start the starting vertex of the search
   * @param end the ending vertex of the search
   * @return a vector containing the indices of the vertices on the shortest
   * path from the starting vertex to the ending vertex
   */
  vector<int> findShortestPath(int start, int end) {
    int size = adjacencyMatrix.size();
    vector<int> distance = bfs(start);
    vector<int> parent(size, -1);

    vector<int> shortestPath;

    int current = end;
    while (current != -1) {
      shortestPath.push_back(current);
      current = parent[current];
    }
    reverse(shortestPath.begin(), shortestPath.end());

    return shortestPath;
  }

  /**
   * @brief finds the shortest cycle in the graph
   *
   * @return a vector containing the indices of the vertices on the shortest
   * cycle
   */
  vector<int> findShortestCycle() {
    // Number of vertices in the graph
    int size = adjacencyMatrix.size();

    // Shortest cycle
    vector<int> shortestCycle;
    int shortestCycleLength =
        size + 1; // Initial length of the longest cycle is n + 1

    // Try each starting vertex
    for (int start = 0; start < size; start++) {
      // Perform a breadth-first search from the starting vertex
      vector<int> distance = bfs(start);

      // Check each possible ending vertex
      for (int end = 0; end < size; end++) {
        // If there is an edge from the starting vertex to the ending vertex,
        // and the distance to the ending vertex is known, and the distance
        // to the ending vertex plus 1 is less than the current shortest cycle
        if (adjacencyMatrix[start][end] == 1 && distance[end] != -1 &&
            distance[end] + 1 < shortestCycleLength) {
          // Clear the shortest cycle
          shortestCycle.clear();
          shortestCycle.push_back(start);
          shortestCycle.push_back(end);
          shortestCycleLength = distance[end] + 1;
        }
      }
    }

    return shortestCycle;
  }

  /**
   * @brief finds the connected components of the graph
   *
   * @return a vector of vectors containing the indices of the vertices in each
   * connected component
   */
  vector<vector<int>> findConnectedComponents() {
    int size = adjacencyMatrix.size(); // Number of vertices in the graph

    vector<bool> visited(size, false); // Boolean array to mark visited vertices
    vector<vector<int>>
        connectedComponents; // Vector of vectors to store connected components

    for (int start = 0; start < size; start++) {
      if (!visited[start]) {   // If the vertex has not been visited
        vector<int> component; // Connected component

        vector<int> distance = bfs(
            start); // Distance from the starting vertex to all other vertices

        for (int i = 0; i < size; i++) {
          if (adjacencyMatrix[start][i] == 1 &&
              distance[i] != -1) { // If there is an edge from the starting
                                   // vertex to the current vertex and the
                                   // current vertex has been visited
            component.push_back(
                i); // Add the current vertex to the connected component
            visited[i] = true; // Mark the current vertex as visited
          }
        }

        connectedComponents.push_back(
            component); // Add the connected component to the vector of
                        // connected components
      }
    }

    return connectedComponents; // Return the vector of connected components
  }

  /**
   * @brief finds the cut vertices of the graph
   *
   * @return a vector containing the indices of the cut vertices
   */
  vector<int> findCutVertices() {
    // Number of vertices in the graph
    int size = adjacencyMatrix.size();

    // Cut vertices
    vector<int> cutVertices;

    // Try each vertex
    for (int vertex = 0; vertex < size; vertex++) {
      // Visited vertices
      vector<bool> visited(size, false);
      visited[vertex] = true; // Mark the current vertex as visited

      // Number of connected components after removing the vertex
      int numComponents = 0;

      // Try each starting vertex
      for (int start = 0; start < size; start++) {
        if (!visited[start]) { // If the vertex has not been visited
          bfs(start); // Perform a breadth-first search from the starting vertex
          numComponents++;
        }
      }

      if (numComponents > 1) {
        cutVertices.push_back(
            vertex); // Add the vertex to the list of cut vertices
      }
    }

    return cutVertices;
  }
};

#endif // BSEARCH_H
