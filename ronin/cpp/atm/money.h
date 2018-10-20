/*
 * Represents money for ATM and Bank classes.
 */

#include <iostream>

class Money {
  public:

    Money();
    ~Money();
    Money(int dollars);
    Money(int dollars, long cents);

    void PrintCents();

    Money operator + (const Money &other) const;
    Money operator - (const Money &other) const;
    Money operator += (const Money &other);
    Money operator -= (const Money &other);

    int ReturnDollars() const;
    int ReturnCents() const;

    bool operator == (const Money &other) const;
    bool operator < (const Money &other) const;

  private:

    unsigned long _cents;
};
