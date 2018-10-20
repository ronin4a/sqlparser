#include <iostream>

class ATM;
class Bank;

class Session {

  public:
    Session(int card_number, ATM &atm, Bank &bank);
    ~Session();

    void RunSession();

    int ReturnCardNumber();
    int ReturnPIN();

  private:
    int _card_number;
    int _pin;

    ATM &_atm;
    Bank &_bank;
    enum {  RUNNING, FINISHED, ABORTED} _status;
    //Transaction *_current_transaction;

};

