#include "money.h"

// -----------------  Constructors  ----------------- //

Money::Money() {
  _cents = 0.0;
}

Money::Money(int dollars) {
  _cents = 100L * dollars;
}

Money::Money(int dollars, long cents) {
  _cents = 100L * dollars + cents;
}

Money::~Money() {
}

// -------------  Overloaded operators  ------------- //

Money Money::operator + (const Money &other) const {
  return Money(0, _cents + other._cents);
}

Money Money::operator - (const Money &other) const {
  return Money(0, _cents - other._cents);
}

Money Money::operator += (const Money &other) {
  _cents += other._cents;
  return *this;
}

Money Money::operator -= (const Money &other) {
  _cents -= other._cents;
  return *this;
}

bool Money::operator == (const Money &other) const {
  return (_cents == other._cents);
}

bool Money::operator < (const Money &other) const {
  return (_cents < other._cents);
}

// -------------------  Acessors  ------------------- //

int Money::ReturnDollars() const {
  return (int) _cents / 100;
}

int Money::ReturnCents() const {
  return (int) _cents;
}

void Money::PrintCents() {
  std::cout << _cents << std::endl;
}
