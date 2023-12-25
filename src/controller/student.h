#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>

class student {
private:
  std::string firstName, lastName;
  int *ratings;
  int n;
  std::string id; // Unique identifier

public:
  student() {
    firstName = "John";
    lastName = "Doe";
    srand(time(NULL));
    n = 10;
    ratings = new int[n];
    for (int i = 0; i < n; i++)
      ratings[i] = rand() % 5 + 1;
    generateID(); // Generate a unique ID
  }

  student(std::string firstName, std::string lastName, int k) {
    this->firstName = firstName;
    this->lastName = lastName;
    srand(time(NULL));
    n = k;
    ratings = new int[n];
    for (int i = 0; i < n; i++)
      ratings[i] = rand() % 5 + 1;
    generateID(); // Generate a unique ID
  }

  std::string getFirstName() { return firstName; }

  std::string getLastName() { return lastName; }

  int *getRatings() { return ratings; }

  int getN() { return n; }

  std::string getID() { return id; } // Getter for the unique ID

  void print() {
    std::cout << "ID: " << id << ", " << lastName << " " << firstName
              << "; rate: ";
    for (int j = 0; j < n; j++)
      std::cout << ratings[j] << " ";
    std::cout << std::endl;
  }

  double averageRatings() {
    double sum = 0;
    for (int i = 0; i < n; i++)
      sum += ratings[i];
    return sum / n;
  }

private:
  void generateID() {
    // Generate a unique ID based on current time
    time_t now = time(0);
    id = std::to_string(now);
  }
};