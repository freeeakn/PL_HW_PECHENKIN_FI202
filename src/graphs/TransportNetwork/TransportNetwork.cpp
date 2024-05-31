#include "TransportNetwork.h"

/**
 * @brief Main function of the program.
 *
 * This function initializes a transport grid, adds stops, renames them, and
 * checks for a route between two stops.
 *
 * @return 0 if the program runs successfully.
 */
int main() {
  int n = 5;             ///< Number of stops to be added.
  int *arr = new int[4]; ///< Array to hold coordinates of a stop.
  arr[0] = 0;
  arr[1] = 0;
  arr[2] = 0;
  arr[3] = 0;

  transport_grid tg(n); ///< Initialize a transport grid with n stops.
  tg.auto_add_stops();  ///< Automatically add stops to the grid.
  tg.add_stop(4, arr);  ///< Add a stop with coordinates from arr.

  tg.rename(0, "4 street"); ///< Rename the stop at index 0.
  tg.rename(1, "hospital"); ///< Rename the stop at index 1.
  tg.rename(2, "palace");   ///< Rename the stop at index 2.
  tg.rename(3, "Park");     ///< Rename the stop at index 3.
  tg.rename(4, "airport");  ///< Rename the stop at index 4.

  int a = 0, b = 4; ///< Indices of the stops to check for a route.
  tg.print_stops(); ///< Print all stops.

  if (tg.isThereRoute(a, b,
                      1)) ///< Check if there is a route between stops a and b.
  {
    cout << "We can go from ";
    tg.print_stops(a, "name"); ///< Print the name of the stop at index a.
    cout << " to ";
    tg.print_stops(b, "name"); ///< Print the name of the stop at index b.
  } else {
    cout << "We can't go from ";
    tg.print_stops(a, "name"); ///< Print the name of the stop at index a.
    cout << " to ";
    tg.print_stops(b, "name"); ///< Print the name of the stop at index b.
  }

  return 0;
}