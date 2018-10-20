#include "atm.h"
#include "bank.h"
#include "session.h"

Session::Session(int card_number, ATM &atm, Bank &bank):
  _card_number(card_number),
  _atm(atm),
  _bank(bank)
{}

Session::~Session() {}

void Session::RunSession() {

  //  Get PIN
  //  #TODO check valid PIN
  _pin = _atm.GetCustomerPIN();
  
  //  Get menu choice
  int menu_choice;
  menu_choice = _atm.GetMenuChoice();

  switch (menu_choice) {
    case 1:
      std::cout << "You chose 1" << std::endl;
      break;
    case 2:
      std::cout << "You chose 2" << std::endl;
      break;
    case 3:
      std::cout << "You chose 3" << std::endl;
      break;
    case 4:
      std::cout << "You chose 4" << std::endl;
      break;
    default:
      std::cout << "Second guard rail FAILED." << std::endl;
  }
}

int Session::ReturnCardNumber() {
  return _card_number;
}

int Session::ReturnPIN() {
  return _pin;
}

