/**
 * @file main.cpp
 * @author Arthur Pechenkin
 * @brief This program defines two classes, People and Peoples, for managing and sorting a list of people.
 *
 * A longer description of the program, possibly including:
 * This is a C++ file that defines a variety of sorting algorithms and a `People` class for storing and manipulating person objects.
 * The `People` class has the following properties and methods:
 * `info`: A `LNS` struct containing the person's last name, name, and surName.
 * `birthDate`: A string containing the person's birth date.
 * `brainVolume`: A double containing the person's brain volume.
 * `getInfo()`: Returns a copy of the `LNS` struct containing the person's information.
 * `getBirthDate()`: Returns a copy of the string containing the person's birth date.
 * `getBrainVolume()`: Returns a copy of the double containing the person's brain volume.
 * `setInfo(lastName, name, surname)`: Sets the person's information.
 * `setBirthDate(date)`: Sets the person's birth date.
 * `setBrainVolume(brainVolume)`: Sets the person's brain volume.
 * The `Peoples` class is a container for a list of `People` objects. It has the
 * following properties and methods:
 * `peopleList`: A vector of `People` objects.
 * `getPeopleList()`: Returns a copy of the vector containing all the people.
 * `addPerson(lastName, name, surname, birthDate, brainVolume)`: Adds a new person to the list.
 * Overall, this file provides a simple way to store and manipulate a list of people and sort them using a variety of algorithms.
 *
 * @version 0.2
 * @date 31-03-2024
 *
 * @copyright Copyright (c) 2024 Arthur Pechenkin. All rights reserved.
 *
 */
#include "sorting.h"
/**
 * @brief Main function of the program.
 *
 * This function is responsible for:
 * - Performing any necessary initializations.
 * - Creating any necessary data structures.
 * - Calling the main program logic.
 * - Cleaning up any resources used by the program.
 *
 * @return int Returns an integer value indicating the program exit status.
 */
int main() {
  srand(time(NULL));

  // Test with a list of size 10
  Peoples peopleList10;
  for (int i = 0; i < 10; i++) {
    string lastName = generateRandomString(rand() % 10);
    string name = generateRandomString(rand() % 10);
    string surName = generateRandomString(rand() % 10);
    string birthDate = to_string(rand() % 10000) + "/01/1980";
    double brainVolume = rand() % 1000 + 1;
    peopleList10.addPerson(lastName, name, surName, birthDate, brainVolume);
    cout
        << "================================================================\n";
    cout << lastName << endl;
    cout << name << endl;
    cout << surName << endl;
    cout << birthDate << endl;
    cout << brainVolume << endl;
    cout
        << "================================================================\n";
  }
  mergeSort(peopleList10);
  cout << "sorted:\n";
  for (int i = 0; i < 10; i++) {
    cout
        << "================================================================\n";
    cout << peopleList10.getPeopleList()[i].getInfo().lastName << endl;
    cout << peopleList10.getPeopleList()[i].getInfo().name << endl;
    cout << peopleList10.getPeopleList()[i].getInfo().surName << endl;
    cout << peopleList10.getPeopleList()[i].getBirthDate() << endl;
    cout << peopleList10.getPeopleList()[i].getBrainVolume() << endl;
    cout
        << "================================================================\n";
  }

  // // Test with a list of size 100
  // Peoples peopleList100;
  // for (int i = 0; i < 100; i++) {
  //   string lastName = generateRandomString(rand() % 10);
  //   string name = generateRandomString(rand() % 10);
  //   string surName = generateRandomString(rand() % 10);
  //   string birthDate = to_string(rand() % 10000) + "/01/1980";
  //   double brainVolume = rand() % 1000 + 1;
  //   peopleList100.addPerson(lastName, name, surName, birthDate, brainVolume);
  //   cout
  //       <<
  //       "================================================================\n";
  //   cout << lastName << endl;
  //   cout << name << endl;
  //   cout << surName << endl;
  //   cout << birthDate << endl;
  //   cout << brainVolume << endl;
  //   cout
  //       <<
  //       "================================================================\n";
  // }
  // mergeSort(peopleList100);
  // for (int i = 0; i < 10; i++) {
  //   cout
  //       <<
  //       "================================================================\n";
  //   cout << peopleList10.getPeopleList()[i].getInfo().lastName << endl;
  //   cout << peopleList10.getPeopleList()[i].getInfo().name << endl;
  //   cout << peopleList10.getPeopleList()[i].getInfo().surName << endl;
  //   cout << peopleList10.getPeopleList()[i].getBirthDate() << endl;
  //   cout << peopleList10.getPeopleList()[i].getBrainVolume() << endl;
  //   cout
  //       <<
  //       "================================================================\n";
  // }

  return 0;
}

/**
 * @brief generates a random string of a given length
 * @param length the length of the random string
 * @return the random string
 */
string generateRandomString(unsigned const int length) {
  string randomString;
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dis('a', 'z');
  for (unsigned int i = 0; i < length; i++)
    randomString += static_cast<char>(dis(gen));
  return randomString;
}

/**
 * @brief Bubble sort algorithm implementation
 * @param peopleList list of people to sort
 */
void bubbleSort(Peoples &peopleList) {
  int size = peopleList.getPeopleList().size();

  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      LNS info1 = peopleList.getPeopleList()[j].getInfo();
      LNS info2 = peopleList.getPeopleList()[j + 1].getInfo();

      if (info1.lastName > info2.lastName)
        swap(peopleList.getPeopleList()[j], peopleList.getPeopleList()[j + 1]);
    }
  }
}

/**
 * @brief Selection sort algorithm implementation
 * @param peopleList list of people to sort
 */
void selectionSort(Peoples &peopleList) {
  int size = peopleList.getPeopleList().size();
  for (int i = 0; i < size - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < size; j++) {
      if (peopleList.getPeopleList()[j].getInfo().lastName <
          peopleList.getPeopleList()[minIndex].getInfo().lastName) {
        minIndex = j;
      }
    }
    swap(peopleList.getPeopleList()[minIndex], peopleList.getPeopleList()[i]);
  }
}

/**
 * @brief Merges two sorted sub-lists into a single sorted list.
 *
 * This function merges the two sorted sub-lists starting from indices `left`
 * and `middle` (both inclusive) into a single sorted list, starting from index
 * `left`.
 *
 * @param list The input list to be merged.
 * @param left The index of the first element of the first sub-list.
 * @param middle The index of the last element of the first sub-list.
 * @param right The index of the last element of the second sub-list.
 */
void merge(Peoples &list, int left, int middle, int right) {
  int n1 = middle - left + 1;
  int n2 = right - middle;

  vector<People> leftList(n1);
  vector<People> rightList(n2);

  for (int i = 0; i < n1; i++) {
    leftList[i] = list.getPeopleList()[left + i];
  }
  for (int j = 0; j < n2; j++) {
    rightList[j] = list.getPeopleList()[middle + 1 + j];
  }

  int i = 0;
  int j = 0;
  int k = left;

  while (i < n1 && j < n2) {
    if (leftList[i].getInfo().lastName <= rightList[j].getInfo().lastName) {
      list.getPeopleList()[k] = leftList[i];
      i++;
    } else {
      list.getPeopleList()[k] = rightList[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    list.getPeopleList()[k] = leftList[i];
    i++;
    k++;
  }

  while (j < n2) {
    list.getPeopleList()[k] = rightList[j];
    j++;
    k++;
  }
}

/**
 * @brief merge sort helper implementation
 * @param peopleList list of people to sort
 */
void mergeSortHelper(Peoples &list, int left, int right) {
  if (left < right) {
    int middle = left + (right - left) / 2;

    mergeSortHelper(list, left, middle);
    mergeSortHelper(list, middle + 1, right);

    merge(list, left, middle, right);
  }
}

/**
 * @brief merge sort algorithm implementation
 * @param peopleList list of people to sort
 */
void mergeSort(Peoples &peopleList) {
  int size = peopleList.getPeopleList().size();
  mergeSortHelper(peopleList, 0, size - 1);
}

/**
 * @brief Partition function for quick sort
 *
 * This function partitions the input list into two parts: the elements less
 * than the pivot and the elements greater than or equal to the pivot. The
 * function swaps the elements to reorder the list in place.
 *
 * @param list The input list to be partitioned
 * @param low The index of the first element in the list
 * @param high The index of the last element in the list
 * @return The index of the pivot element
 */
int partition(Peoples &list, int low, int high) {
  People pivot = list.getPeopleList()[high];
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++) {
    if (list.getPeopleList()[j].getInfo().lastName < pivot.getInfo().lastName) {
      i++;
      swap(list.getPeopleList()[i], list.getPeopleList()[j]);
    }
  }
  swap(list.getPeopleList()[i + 1], list.getPeopleList()[high]);
  return (i + 1);
}

void quickSortHelper(Peoples &list, int low, int high) {
  if (low < high) {
    int pi = partition(list, low, high);

    quickSortHelper(list, low, pi - 1);
    quickSortHelper(list, pi + 1, high);
  }
}

/**
 * @brief Quick sort algorithm implementation
 * @param peopleList list of people to sort
 */
void quickSort(Peoples &peopleList) {
  int size = peopleList.getPeopleList().size();
  quickSortHelper(peopleList, 0, size - 1);
}

/**
 * @brief Shell sort algorithm implementation
 * @param peopleList list of people to sort
 */
void shellSort(Peoples &peopleList) {
  int n = peopleList.getPeopleList().size();
  for (int gap = n / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < n; i++) {
      People temp = peopleList.getPeopleList()[i];
      int j;
      for (j = i - gap; j >= 0 && peopleList.getPeopleList()[j].getBirthDate() >
                                      temp.getBirthDate();
           j -= gap) {
        peopleList.getPeopleList()[j + gap] = peopleList.getPeopleList()[j];
      }
      peopleList.getPeopleList()[j + gap] = temp;
    }
  }
}

/**
 * @brief Heapifies a subtree of size n starting at index i.
 *
 * This function heapifies a subtree of size n starting at index i. It does so
 * by finding the largest child node and swapping it with the parent node if
 * necessary. This process is repeated for each node in the subtree until the
 * entire subtree is heapified.
 *
 * @param peopleList The input list.
 * @param n The size of the subtree.
 * @param i The index of the root of the subtree.
 */
void heapify(Peoples &peopleList, int n, int i) {
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  /**
   * If the left child of node i exists and is greater than the largest child
   * node, set largest to the left child.
   */
  if (l < n && peopleList.getPeopleList()[l].getBirthDate() >
                   peopleList.getPeopleList()[largest].getBirthDate())
    largest = l;

  /**
   * If the right child of node i exists and is greater than the largest child
   * node, set largest to the right child.
   */
  if (r < n && peopleList.getPeopleList()[r].getBirthDate() >
                   peopleList.getPeopleList()[largest].getBirthDate())
    largest = r;

  /**
   * If the largest child node is not the same as node i, swap them.
   */
  if (largest != i) {
    People swap = peopleList.getPeopleList()[i];
    peopleList.getPeopleList()[i] = peopleList.getPeopleList()[largest];
    peopleList.getPeopleList()[largest] = swap;

    /**
     * Recursively heapify the subtree rooted at the new largest node.
     */
    heapify(peopleList, n, largest);
  }
}

void heapSort(Peoples &peopleList) {
  int size = peopleList.getPeopleList().size();
  for (int i = size / 2 - 1; i >= 0; i--)
    heapify(peopleList, size, i);

  for (int i = size - 1; i > 0; i--) {
    People temp = peopleList.getPeopleList()[0];
    peopleList.getPeopleList()[0] = peopleList.getPeopleList()[i];
    peopleList.getPeopleList()[i] = temp;

    heapify(peopleList, i, 0);
  }
}

void bucketSort(Peoples &peopleList) {
  int size = peopleList.getPeopleList().size();
  if (size <= 1)
    return;

  Peoples buckets;

  int maxBrainVolume = peopleList.getPeopleList()[0].getBrainVolume();
  for (int i = 1; i < size; i++) {
    if (peopleList.getPeopleList()[i].getBrainVolume() > maxBrainVolume)
      maxBrainVolume = peopleList.getPeopleList()[i].getBrainVolume();
  }

  double interval = (double)maxBrainVolume / size;

  for (int i = 0; i < size; i++) {
    int index =
        (int)(peopleList.getPeopleList()[i].getBrainVolume() / interval);
    buckets.getPeopleList()[index] =
        People(peopleList.getPeopleList()[i].getInfo().lastName,
               peopleList.getPeopleList()[i].getInfo().name,
               peopleList.getPeopleList()[i].getInfo().surName,
               peopleList.getPeopleList()[i].getBirthDate(),
               peopleList.getPeopleList()[i].getBrainVolume());
  }

  int i = 0;
  for (auto &person : buckets.getPeopleList()) {
    peopleList.getPeopleList()[i] = person;
    i++;
  }
}

/**
 * @brief Counting sort algorithm implementation
 * @param peopleList list of people to sort
 * @param place the base of the counting sort
 */
void countingSort(Peoples &peopleList, int place) {
  int size = peopleList.getPeopleList().size();
  vector<int> count(10, 0);
  vector<People> output(size);

  for (int i = 0; i < size; i++) {
    int num =
        (int)((float)peopleList.getPeopleList()[i].getBrainVolume() / place) %
        10;
    count[num]++;
  }

  for (int i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }

  for (int i = size - 1; i >= 0; i--) {
    int num =
        (int)((float)peopleList.getPeopleList()[i].getBrainVolume() / place) %
        10;
    output[count[num] - 1] = peopleList.getPeopleList()[i];
    count[num]--;
  }

  for (int i = 0; i < size; i++) {
    peopleList.getPeopleList()[i] = output[i];
  }
}

/**
 * @brief Radix sort algorithm implementation
 * @param peopleList list of people to sort
 */
void radixSort(Peoples &peopleList) {
  int maxBrainVolume = peopleList.getPeopleList()[0].getBrainVolume();
  for (int i = 1; i < peopleList.getPeopleList().size(); i++) {
    if (peopleList.getPeopleList()[i].getBrainVolume() > maxBrainVolume)
      maxBrainVolume = peopleList.getPeopleList()[i].getBrainVolume();
  }

  for (int place = 1; maxBrainVolume / place > 0; place *= 10) {
    countingSort(peopleList, place);
  }
}

/**
 * @brief Insertion sort algorithm implementation
 * @param peopleList list of people to sort
 * @param left left index of the subarray
 * @param right right index of the subarray
 */
void insertionSort(Peoples &peopleList, int left, int right) {
  for (int i = left + 1; i <= right; i++) {
    People key = peopleList.getPeopleList()[i];
    int j;
    for (j = i - 1; j >= left && peopleList.getPeopleList()[j].getBirthDate() >
                                     key.getBirthDate();
         j--) {
      peopleList.getPeopleList()[j + 1] = peopleList.getPeopleList()[j];
    }
    peopleList.getPeopleList()[j + 1] = key;
  }
}

/**
 * @brief Timsort is an adaptive hybrid sorting algorithm that uses both
 * insertion sort and merge sort.
 *
 * Timsort works by splitting the input array into smaller sub-arrays and
 * sorting them using insertion sort. Then, it merges the sorted sub-arrays back
 * into a single sorted array. This process is repeated until the entire input
 * array is sorted.
 *
 * Timsort is an adaptive sorting algorithm, which means it can automatically
 * choose the best sorting algorithm for each sub-array based on its size and
 * content. This improves the performance of the algorithm compared to a generic
 * sorting algorithm that uses the same sorting algorithm for all sub-arrays.
 *
 * Timsort is an efficient sorting algorithm, especially for large input arrays.
 * It is faster than most other stable sorting algorithms, such as merge sort
 * and quick sort.
 *
 * @param peopleList The input list of people to be sorted.
 */
void timSort(Peoples &peopleList) {
  int size = peopleList.getPeopleList().size();
  int blockSize = 32;

  for (int i = 0; i < size; i += blockSize) {
    insertionSort(peopleList, i, min((i + blockSize - 1), (size - 1)));
  }

  for (int size = blockSize; size < size; size = 2 * size) {
    for (int left = 0; left < size; left += 2 * size) {
      int mid = left + size - 1;
      int right = min((left + 2 * size - 1), (size - 1));

      if (peopleList.getPeopleList()[mid].getBirthDate() <=
          peopleList.getPeopleList()[right].getBirthDate()) {
        continue;
      }

      merge(peopleList, left, mid, right);
    }
  }
}