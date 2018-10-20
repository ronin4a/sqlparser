#include <iostream>
#include "atm.h"
#include "atmparts.h"
#include "bank.h"
#include "money.h"
#include "session.h"
#include "transaction.h"
#include "status.h"

#define ATM_NUMBER 42
#define ATM_LOCATION "SVL"

using namespace std;

int main() {

  Bank theBank;
  ATM currentATM(ATM_NUMBER, ATM_LOCATION, theBank);

  currentATM.StartUpATM();
  currentATM.CheckATMCash();
  currentATM.ServiceCustomers();

  return 0;

}

