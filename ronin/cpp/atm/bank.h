/*
 *  Manages dialogue between ATM and the bank.
 */

class Bank {

  public:

    Bank();
    ~Bank();

    enum AccountType { CHECKING, SAVINGS, MONEY_MARKET };

    bool IsPinCorrect(int card_num, int pin);

};
