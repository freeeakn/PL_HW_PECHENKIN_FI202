#include <iostream>
#include <string>

class Hero {
protected:
  int hp, attack, armor, speed;

public:
  Hero() : hp(100), attack(2), armor(0), speed(15) {}

  virtual int getHp() { return hp; }
  virtual int getAttack() { return attack; }
  virtual int getSpeed() { return speed; }
  virtual int getArmor() { return armor; }

  void getState() {
    std::cout << "\033[91m-----------\033[0m" << std::endl
              << "Health: " << (this->getHp()) << std::endl
              << "Attack: " << this->getAttack() << std::endl
              << "Speed: " << this->getSpeed() << std::endl
              << "Armor: " << this->getArmor() << std::endl
              << "\033[91m-----------\033[0m" << std::endl;
  }
};

class Helmet : public Hero {
protected:
  Hero *hero;

public:
  Helmet(Hero *h) {
    this->hero = h;
    this->hp = 20;
    this->armor = 5;
  }

  int getHp() { return hp + hero->getHp(); }
  int getArmor() { return armor + hero->getArmor(); }
  int getAttack() { return hero->getAttack(); }
  int getSpeed() { return hero->getSpeed(); }
};

class Chestplate : public Hero {
protected:
  Hero *hero;

public:
  Chestplate(Hero *h) {
    this->hero = h;
    this->armor = 20;
    this->speed = -5;
  }
  int getSpeed() { return speed + hero->getSpeed(); }
  int getArmor() { return armor + hero->getArmor(); }
  int getAttack() { return hero->getAttack(); }
  int getHp() { return hero->getHp(); }
};

class Sword : public Hero {
protected:
  Hero *hero;

public:
  Sword(Hero *h) {
    this->hero = h;
    this->attack = 15;
    this->speed = -2;
  }
  int getSpeed() { return speed + hero->getSpeed(); }
  int getAttack() { return attack + hero->getAttack(); }
  int getHp() { return hero->getHp(); }
  int getArmor() { return hero->getArmor(); }
};

class Boots : public Hero {
protected:
  Hero *hero;

public:
  Boots(Hero *h) {
    this->hero = h;
    this->speed = 10;
    this->hp = 5;
  }
  int getSpeed() { return speed + hero->getSpeed(); }
  int getHp() { return hp + hero->getHp(); }
  int getArmor() { return hero->getArmor(); }
  int getAttack() { return hero->getAttack(); }
};