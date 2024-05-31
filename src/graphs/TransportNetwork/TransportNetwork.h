#include <iostream>
#include <string>
using namespace std;

class transport_grid {
private:
  int number;
  int **stops;
  string *names;
  /**
   * Initializes the transport grid by allocating memory for stops and names
   * arrays. The stops array is a 2D array of integers, where each row
   * represents a stop and each column represents a connected stop. The names
   * array is a 1D array of strings, where each element represents the name of a
   * stop. The initial values of the stops array are set to 0, and the names
   * array is initialized with default names.
   */
  void init() {
    // Allocate memory for stops array
    stops = new int *[number];
    // Allocate memory for names array
    names = new string[number];

    // Initialize stops array and names array
    for (int i = 0; i < number; i++) {
      // Allocate memory for each row of stops array
      stops[i] = new int[2];
      // Initialize each element of stops array to 0
      for (int j = 0; j < 2; j++) {
        stops[i][j] = 0;
      }
      // Initialize names array with default names
      names[i] = "stop #" + to_string(i + 1);
    }
  }
  /**
   * Destroys the transport grid by deallocating memory for stops and names
   * arrays. This method is responsible for freeing up the dynamically allocated
   * memory to prevent memory leaks. After calling this method, the stops and
   * names arrays will be set to nullptr.
   */
  void destroy() {
    int i = 0;
    // Deallocate memory for each row of stops array
    while (i < number) {
      delete[] stops[i];
      stops[i] = nullptr;
      i++;
    }
    // Deallocate memory for stops array
    delete[] stops;
    stops = nullptr;
  }

public:
  /**
   * Default constructor for the transport_grid class.
   * Initializes the transport grid with a default number of stops (3).
   * Calls the init() method to allocate memory for stops and names arrays.
   */
  transport_grid() {
    number = 3;
    init();
  }
  /**
   * Constructor for the transport_grid class.
   * Initializes the transport grid with a specified number of stops.
   *
   * @param n - The number of stops to be initialized in the transport grid.
   *
   * @post The transport grid is initialized with the specified number of stops.
   *       The stops array and names array are allocated memory and initialized.
   *       The initial values of the stops array are set to 0, and the names
   * array is initialized with default names.
   */
  transport_grid(int n) {
    number = n;
    init();
  }
  /**
   * Adds stops to the transport grid using a 2D array of integers.
   *
   * @param a - A 2D array of integers representing the stops to be added.
   *            The first element of each sub-array represents the number of
   * stops connected to the current stop. The subsequent elements represent the
   * connected stops.
   *
   * @post The stops array in the transport grid is updated with the new stops.
   *       The stops array is modified in-place, without creating a new array.
   *
   * @note The input array 'a' should be properly initialized and allocated
   * memory before calling this method. The number of rows in the array should
   * match the number of stops in the transport grid. The first element of each
   * sub-array should not exceed the maximum number of connected stops.
   *
   * @example
   * int stops_data[3][3] = {{2, 1, 2}, {2, 0, 2}, {2, 1, 2}};
   * transport_grid tg(3);
   * tg.add_stops(stops_data);
   */
  void add_stops(int **a) {
    for (int i = 0; i < number; i++) {
      for (int j = 0; j < a[i][0]; j++) {
        stops[i][j] = a[i][j];
      }
    }
  }
  /**
   * Nullifies the stops in the transport grid.
   * This method sets all the values in the stops array to 0.
   *
   * @post The stops array in the transport grid is updated with all values set
   * to 0. The stops array is modified in-place, without creating a new array.
   *
   * @note This method is useful when resetting the stops in the transport grid
   * to their initial state.
   *
   * @example
   * transport_grid tg(3);
   * tg.add_stops(stops_data); // Assume stops_data is properly initialized
   * tg.null_stops(); // All stops in the transport grid are now set to 0
   */
  void null_stops() {
    for (int i = 0; i < number; i++) {
      for (int j = 0; j < stops[i][0]; j++) {
        stops[i][j] = 0;
      }
    }
  }
  /**
   * Automatically adds stops to the transport grid.
   * This method initializes the stops array with a predefined pattern.
   * The pattern is as follows:
   * - Stop 0 is connected to stops 1 and the last stop.
   * - Each subsequent stop is connected to the previous stop, the next stop,
   * and the last stop.
   * - The last stop is connected to stops 0 and the second-to-last stop.
   *
   * @post The stops array in the transport grid is updated with the new stops.
   *       The stops array is modified in-place, without creating a new array.
   *       The memory allocated for the previous stops array is deallocated.
   *
   * @note This method is useful for testing or demonstration purposes.
   *       It does not provide a flexible way to add stops to the transport
   * grid. It is recommended to use the add_stops() method for more control over
   * the stops added to the transport grid.
   *
   * @example
   * transport_grid tg(5);
   * tg.auto_add_stops(); // The stops array in the transport grid is updated
   * with the new stops.
   */
  void auto_add_stops() {
    int i = 0;
    // Deallocate memory for each row of stops array
    while (i < number) {
      delete[] stops[i];
      stops[i] = nullptr;
      i++;
    }
    i = 1;
    // Initialize stop 0
    stops[0] = new int[3];
    stops[0][0] = 2;
    stops[0][1] = 1;
    stops[0][2] = number;
    // Initialize subsequent stops
    while (i < number) {
      stops[i] = new int[3];
      stops[i][0] = 3;
      stops[i][1] = i - 1;
      stops[i][2] = i + 1;
      i++;
    }
    // Initialize last stop
    stops[number - 1] = new int[2];
    stops[number - 1][0] = 2;
    stops[number - 1][1] = 0;
  }
  /**
   * Prints the stops in the transport grid.
   * This method iterates through the stops array and prints the names and
   * connected stops for each stop.
   *
   * @post The stops in the transport grid are printed to the console.
   *       The output format is as follows:
   *       - Each line represents a stop and its connected stops.
   *       - The stop name is printed followed by a colon and a space.
   *       - The connected stops are printed as a space-separated list.
   *
   * @note The stops are printed with 1-based indexing, meaning the stop numbers
   * start from 1.
   *
   * @example
   * transport_grid tg(3);
   * tg.add_stops(stops_data); // Assume stops_data is properly initialized
   * tg.print_stops(); // Prints:
   * stop #1: 2 3
   * stop #2: 1 3
   * stop #3: 1 2
   */
  void print_stops() {
    for (int i = 0; i < number; i++) {
      cout << names[i] << ": ";
      for (int j = 1; j < stops[i][0]; j++) {
        cout << stops[i][j] + 1 << ' ';
      }
      cout << endl;
    }
  }
  /**
   * Prints the stops for a specific stop in the transport grid.
   * This method iterates through the stops array for a specific stop and prints
   * the name and connected stops.
   *
   * @param i - The index of the stop to be printed. The index is 0-based.
   *
   * @post The stops for the specified stop in the transport grid are printed to
   * the console. The output format is as follows:
   *       - The stop name is printed followed by a colon and a space.
   *       - The connected stops are printed as a space-separated list.
   *
   * @note The stops are printed with 1-based indexing, meaning the stop numbers
   * start from 1. The index 'i' should be within the valid range of stop
   * indices (0 to number-1).
   *
   * @example
   * transport_grid tg(3);
   * tg.add_stops(stops_data); // Assume stops_data is properly initialized
   * tg.print_stops(1); // Prints: stop #2: 1 3
   */
  void print_stops(int i) {
    cout << names[i] << ": ";
    for (int j = 1; j < stops[i][0]; j++) {
      cout << stops[i][j] << ' ';
    }
    cout << endl;
  }
  /**
   * Prints the name of a specific stop in the transport grid.
   * This method prints the name of the stop at the given index.
   *
   * @param i - The index of the stop to be printed. The index is 0-based.
   * @param s - A string parameter that should be "name" to indicate that the
   * name should be printed.
   *
   * @post The name of the specified stop in the transport grid is printed to
   * the console. The output format is as follows:
   *       - The stop name is printed.
   *
   * @note The stops are printed with 1-based indexing, meaning the stop numbers
   * start from 1. The index 'i' should be within the valid range of stop
   * indices (0 to number-1). The string parameter '' should be "name" to
   * indicate that the name should be printed.
   *
   * @example
   * transport_grid tg(3);
   * tg.add_stops(stops_data); // Assume stops_data is properly initialized
   * tg.print_stops(1, "name"); // Prints: stop #2
   */
  void print_stops(int i, string s) {
    if (s == "name")
      cout << names[i];
  }
  /**
   * Renames the stop at the specified index.
   *
   * @param n - The index of the stop to be renamed. The index is 0-based.
   * @param s - The new name for the stop.
   *
   * @post The name of the stop at the specified index in the transport grid is
   * updated to the new name. The names array in the transport grid is modified
   * in-place, without creating a new array.
   *
   * @note The index 'n' should be within the valid range of stop indices (0 to
   * number-1). The new name '' should be a non-empty string.
   *
   * @example
   * transport_grid tg(3);
   * tg.rename(1, "New Stop Name"); // The name of the second stop in the
   * transport grid is updated to "New Stop Name".
   */
  void rename(int n, string s) { names[n] = s; }
  /**
   * Adds a stop to the transport grid using an array of integers.
   *
   * @param n - The index of the stop to which the new stop will be added. The
   * index is 0-based.
   * @param a - An array of integers representing the connected stops for the
   * new stop. The first element of the array represents the number of connected
   * stops. The subsequent elements represent the connected stops.
   *
   * @post The stops array in the transport grid is updated with the new stop.
   *       The stops array is modified in-place, without creating a new array.
   *       The memory allocated for the previous stops array is not deallocated.
   *
   * @note The input array 'a' should be properly initialized and allocated
   * memory before calling this method. The number of elements in the array
   * should match the number of connected stops for the new stop. The first
   * element of the array should not exceed the maximum number of connected
   * stops. The index 'n' should be within the valid range of stop indices (0 to
   * number-1).
   *
   * @example
   * int new_stop_data[3] = {2, 1, 2};
   * transport_grid tg(3);
   * tg.add_stop(1, new_stop_data); // The second stop in the transport grid is
   * updated with the new stop data.
   */
  void add_stop(int n, int *a) {
    for (int i = 0; i < stops[i][0]; i++)
      stops[n][i] = a[i];
  }
  /**
   * Adds a stop to the transport grid using user input.
   *
   * @param n - The index of the stop to which the new stop will be added. The
   * index is 0-based.
   *
   * @post The stops array in the transport grid is updated with the new stop.
   *       The stops array is modified in-place, without creating a new array.
   *       The memory allocated for the previous stops array is not deallocated.
   *
   * @note The index 'n' should be within the valid range of stop indices (0 to
   * number-1). The user is prompted to enter the connected stops for the new
   * stop. The input validation checks for invalid stop indices and
   * self-referential stops.
   *
   * @example
   * transport_grid tg(3);
   * tg.add_stop(1); // The second stop in the transport grid is updated with
   * user input for connected stops.
   */
  void add_stop(int n) {
    int in;
    cout << "Add stops by " << names[n] << endl;
    for (int i = 0; i < stops[i][0]; i++) {
    step:
      cin >> in;
      if (in - 1 >= number) {
        cout << "Wrong input: there ain't " << in << "th stop. Add again"
             << endl;
        goto step;
      }
      if (in - 1 == n) {
        cout << "Wrong input: its next stop can't be itself. Add again" << endl;
        goto step;
      }
      stops[n][i] = in;
    }
  }
  /**
   * Checks if there is a direct route between two stops in the transport grid.
   *
   * @param a - The index of the starting stop. The index is 0-based.
   * @param b - The index of the destination stop. The index is 0-based.
   *
   * @return true if there is a direct route between stop 'a' and stop 'b',
   * false otherwise.
   *
   * @note This method only checks for direct connections between stops.
   *       It does not consider indirect connections through other stops.
   *
   * @example
   * transport_grid tg(3);
   * tg.add_stops(stops_data); // Assume stops_data is properly initialized
   * bool hasRoute = tg.isThereRoute(1, 2); // Check if there is a direct route
   * from stop #2 to stop #3 if (hasRoute) { cout << "There is a direct route
   * between stop #2 and stop #3" << endl; } else { cout << "There is no direct
   * route between stop #2 and stop #3" << endl;
   * }
   */
  bool isThereRoute(int a, int b) {
    int i = 0;
    bool br = false;
    while (i < stops[a][0]) {
      if (stops[a][i] == b) {
        br = true;
        break;
      }
      i++;
    }
    return br;
  }
  /**
   * Checks if there is a direct or indirect route between two stops in the
   * transport grid.
   *
   * @param a - The index of the starting stop. The index is 0-based.
   * @param b - The index of the destination stop. The index is 0-based.
   *
   * @return true if there is a route between stop 'a' and stop 'b', false
   * otherwise.
   *
   * @note This method checks for direct and indirect connections between stops.
   *       It uses a recursive approach to explore all possible connections.
   *
   * @example
   * transport_grid tg(3);
   * tg.add_stops(stops_data); // Assume stops_data is properly initialized
   * bool hasRoute = tg.isThereWay(1, 2); // Check if there is a route from stop
   * #2 to stop #3 if (hasRoute) { cout << "There is a route between stop #2 and
   * stop #3" << endl; } else { cout << "There is no route between stop #2 and
   * stop #3" << endl;
   * }
   */
  bool isThereWay(int a, int b) {
    int i = 0;
    bool br = false;

    // Check direct connections
    while (i < stops[a][0]) {
      if (stops[a][i] == b) {
        br = true;
        break;
      }
      i++;
    }

    i = 0;
    // If no direct connection found, check indirect connections
    if (!br) {
      while (i < stops[a][0]) {
        if (isThereWay(stops[a][i], b)) {
          br = true;
          break;
        }
        i++;
      }
    }

    return br;
  }
  /**
   * Checks if there is a direct route between two stops in the transport grid.
   *
   * @param a - The index of the starting stop. The index is 0-based.
   * @param b - The index of the destination stop. The index is 0-based.
   * @param count - The remaining steps to reach the destination stop.
   *
   * @return true if there is a direct route between stop 'a' and stop 'b' with
   * the remaining steps, false otherwise.
   *
   * @note This method only checks for direct connections between stops.
   *       It does not consider indirect connections through other stops.
   *       The 'count' parameter is used to track the remaining steps in the
   * recursive calls.
   *
   * @example
   * transport_grid tg(3);
   * tg.add_stops(stops_data); // Assume stops_data is properly initialized
   * bool hasRoute = tg.isThereRoute(1, 2, 2); // Check if there is a direct
   * route from stop #2 to stop #3 with 2 remaining steps if (hasRoute) { cout
   * << "There is a direct route between stop #2 and stop #3 with 2 remaining
   * steps" << endl; } else { cout << "There is no direct route between stop #2
   * and stop #3 with 2 remaining steps" << endl;
   * }
   */
  bool isThereRoute(int a, int b, int count) {
    int i = 0, c = 1;
    bool br = false;
    while (i < stops[a][0]) {
      if ((stops[a][i] == b) and (1 == count)) {
        br = true;
        break;
      }
      i++;
    }
    i = 0;
    if (!br)
      while (i < stops[a][0]) {
        c++;
        if (isThereRoute(stops[a][i], b, count - 1) and (c == count)) {
          br = true;
          break;
        }
        i++;
      }
    return br;
  }
};