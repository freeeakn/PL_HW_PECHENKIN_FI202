/**
 * @file main.cpp
 * @author Arthur Pechenkin
 * @brief A brief description of the program.
 *
 * A longer description of the program, possibly including:
 * - A brief background on the problem the program aims to solve.
 * - A description of the main functions and features of the program.
 * - A list of any libraries or frameworks used in the program.
 * - Any other relevant information about the program.
 *
 * @version 0.1
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
  bubbleSort(peopleList10);
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

  // Test with a list of size 100
  Peoples peopleList100;
  for (int i = 0; i < 100; i++) {
    string lastName = generateRandomString(rand() % 10);
    string name = generateRandomString(rand() % 10);
    string surName = generateRandomString(rand() % 10);
    string birthDate = to_string(rand() % 10000) + "/01/1980";
    double brainVolume = rand() % 1000 + 1;
    peopleList100.addPerson(lastName, name, surName, birthDate, brainVolume);
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
  bubbleSort(peopleList100);
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
  for (int i = 0; i < length; i++)
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