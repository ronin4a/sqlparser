#include "atm.h"
#include "atmparts.h"
#include "bank.h"
#include "money.h"
#include "session.h"

ATM::ATM(int number, const char * location, Bank &bank) :
  _number(number),
  _location(location),
  _bank(bank),
  _display(*new Display()),
  _operatorPanel(*new OperatorPanel()),
  _atm_balance(*new Money()),
  _cardReader (*new CardReader()),
  _keyboard (*new Keyboard())
{ }

ATM::~ATM() { }

void ATM::StartUpATM() {
  //  Make a call to OperatorPanel to turn on ATM
  //  #TODO: have this be a separate UI/agent inputting
  _operatorPanel.TurnOnOperatorPanel();
  _state = RUNNING;

  std::cout << "Confirm number of $20 bills in the ATM." << std::endl;

  int num_bills;

  while (!(std::cin >> num_bills)) {
    std::cout << "Please enter an int." << std::endl;
    std::cin.clear();
    std::cin.ignore(20000, '\n');
  }

  //  Add initial cash to ATM
  _atm_balance += _operatorPanel.GetInitialCash(num_bills);


}

//  Shut down ATM and return cash to Bank
//  #TODO:  fill this out
void ATM::ShutDownATM() {
}

void ATM::CheckATMCash() {
  std::cout << "$" << _atm_balance.ReturnDollars() << std::endl;
}

//  PRIMARY FUNCTION
//  Conditions for exiting
//  - ATM runs out of cash (alerts Operator)
//  - Card is invalid (call RejectCard())
//  - PIN is incorrect for three tries (call RejectCard())
void ATM::ServiceCustomers() {

  while ((_atm_balance.ReturnDollars() > 0) 
      && _operatorPanel.IsOperatorPanelOn()) {

    //  Get card
    _display.RequestCard();
    CardReader::ReaderStatus check_card;
    check_card = _cardReader.CheckForInsertedCard();
    if (check_card != CardReader::CARD_HAS_BEEN_READ) {
      std::cout << "Invalid card." << std::endl;
      break;
    }

    //  Start up a Session
    Session *session = new Session(_cardReader.CardNumber(), *this, _bank);
    session -> RunSession();
    delete session;
    
    break;
  }
}

int ATM::GetCustomerPIN() const {
  _display.RequestPIN();
  return _keyboard.ReadPIN();
}

int ATM::ReEnterPIN() const {
  return 0;
};

int ATM::GetMenuChoice() {
  _display.DisplayMenu();
  return _keyboard.ReadMenuChoice();
}

