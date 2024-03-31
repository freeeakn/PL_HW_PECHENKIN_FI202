#ifndef SORTING_H
#define SORTING_H

#include <iostream>
#include <vector>
#include <string>
#include <random>

using namespace std;

struct LNS {
  string lastName;
  string name;
  string surName;
};

class People {
private:
  LNS info;
  string birthDate;
  double brainVolume;

public:
  People() {
    /**
     * default constructor
     */
    // do something
  }

  People(const string lastName, const string name, const string surName) {
    /**
     * constructor
     * @param lastName string containing the last name of the person
     * @param name string containing the first name of the person
     * @param surname string containing the surname of the person
     */
    this->info.lastName = lastName;
    this->info.name = name;
    this->info.surName = surName;
  }
  //? Getters

  LNS getInfo() {
    /**
     * Returns the information of the person
     * @return LNS object containing the information of the person
     */
    return info;
  }
  string getBirthDate() {
    /**
     * Returns the birth date of the person
     * @return string containing the birth date of the person
     */
    return birthDate;
  }
  double getBrainVolume() {
    /**
     * Returns the brain volume of the person
     * @return double containing the brain volume of the person
     */
    return brainVolume;
  }
  //? Setters

  void setInfo(const string lastName, const string name, const string surname) {
    /**
     * Sets the information of the person
     * @param lastName string containing the last name of the person
     * @param name string containing the first name of the person
     * @param surname string containing the surname of the person
     */
    this->info.lastName = lastName;
    this->info.name = name;
    this->info.surName = surname;
  }
  /**
   * Sets the birth date of the person
   * @param date string containing the birth date of the person
   */
  void setBirthDate(const string date) { this->birthDate = date; }
  /**
   * Sets the brain volume of the person
   * @param brainVolume double containing the brain volume of the person
   */
  void setBrainVolume(const double brainVolume) {
    this->brainVolume = brainVolume;
  }
};

class Peoples {
private:
  vector<People> peopleList;

public:
  Peoples() {
    // create a new person object and set its properties
    People *newPerson = new People();
    /**
     * sets the information of the person
     * @param lastName string containing the last name of the person
     * @param name string containing the first name of the person
     * @param surname string containing the surname of the person
     */
    newPerson->setInfo("Doe", "John", "Jr.");
    /**
     * sets the birth date of the person
     * @param date string containing the birth date of the person
     */
    newPerson->setBirthDate("01/01/1980");
    /**
     * sets the brain volume of the person
     * @param brainVolume double containing the brain volume of the person
     */
    newPerson->setBrainVolume(1500.0);

    // add the person to the list of people
    peopleList.push_back(*newPerson);

    // delete the person object
    delete newPerson;
  }
  //? Getters
  vector<People> getPeopleList() { return peopleList; }
  //? Setters
  /**
   * Adds a new person to the list of people
   * @param lastName string containing the last name of the person
   * @param name string containing the first name of the person
   * @param surname string containing the surname of the person
   */
  void addPerson(const string lastName, const string name, const string surname,
                 const string birthDate, const double brainVolume) {
    People *newPerson = new People();
    /**
     * sets the information of the person
     * @param lastName string containing the last name of the person
     * @param name string containing the first name of the person
     * @param surname string containing the surname of the person
     */
    newPerson->setInfo(lastName, name, surname);
    /**
     * sets the birth date of the person
     * @param date string containing the birth date of the person
     */
    newPerson->setBirthDate(birthDate);
    /**
     * sets the brain volume of the person
     * @param brainVolume double containing the brain volume of the person
     */
    newPerson->setBrainVolume(brainVolume);

    // add the person to the list of people
    peopleList.push_back(*newPerson);

    // delete the person object
    delete newPerson;
  }
  /**
   * Removes a person from the list of people
   * @param lastName string containing the last name of the person
   * @param name string containing the first name of the person
   * @param surname string containing the surname of the person
   */
};


string generateRandomString(unsigned const int length);
void bubbleSort(Peoples &peopleList);
// void insertionSort(Peoples &peopleList);
// void selectionSort(Peoples &peopleList);
// void mergeSort(Peoples &peopleList);
// void quickSort(Peoples &peopleList);

#endif // SORTING_H
