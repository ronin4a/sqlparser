#include "atmparts.h"
#include "money.h"

//  ------------------------ CardReader ------------------------  //
CardReader::CardReader() :
  _status(NO_CARD)
{
}

CardReader::~CardReader() {
}

void CardReader::AcceptCard() {
  _status = CARD_HAS_BEEN_READ;
}

void CardReader::EjectCard() {
  _status = UNREADABLE_CARD;
}

CardReader::ReaderStatus CardReader::CheckForInsertedCard() {
  //  #TODO: Actually have hardware that checks for a legit card; for now, this
  //  should just be a straight accept

  std::cout << "..enter card number..." << std::endl;

  while (!(std::cin >> _card_number_read)) {
    std::cout << "Please enter an actual integer." << std::endl;
    std::cin.clear();
    std::cin.ignore(20000, '\n');
  };

  CardReader::AcceptCard();

  return _status;
}

int CardReader::CardNumber() const {
  return _card_number_read;
}

//  -------------------------- Display -------------------------  //

Display::Display() {
}

Display::~Display() {
}

void Display::DisplayHeader() {
  std::cout << "---------------- ATM ----------------" << std::endl;
}

void Display::DisplayFooter() {
  std::cout << "--- Press ESC anytime to CANCEL -----" << std::endl;
}

//  --  Initial screens
void Display::RequestCard() {

  DisplayHeader();
  for (int i = 0; i < 3; i++)
    std::cout << std::endl;

  std::cout << "  Please input card." << std::endl;

  for (int i = 0; i < 3; i++)
    std::cout << std::endl;
  DisplayFooter();

}

void Display::RequestPIN() {

  DisplayHeader();
  for (int i = 0; i < 3; i++)
    std::cout << std::endl;

  std::cout << "  Please input PIN." << std::endl;

  for (int i = 0; i < 3; i++)
    std::cout << std::endl;
  DisplayFooter();

}

//  --  Display options
void Display::DisplayMenu() {
  DisplayHeader();
  std::cout << std::endl;
  std::cout << "        1.  WITHDRAW CASH." << std::endl;
  std::cout << "        2.  MAKE DEPOSIT." << std::endl;
  std::cout << "        3.  TRANSFER MONEY." << std::endl;
  std::cout << "        4.  CHECK BALANCE." << std::endl;
  std::cout << std::endl;
  DisplayFooter();
}

/*
//  --  Follow-up actions/requests
void Display::RequestAmountEntry();
void Display::RequestDepositEnvelope();

//  --  Error messaging
void Display::ReportCardUnreadable();
void Display::ReportTransactionFailure();
void Display::RequestReEnterPIN();

void Display::ReportCardRetained();

//  --  Misc display options
void Display::EchoInput(char *echo_this);
void Display::ClearDisplay();
*/

//  ----------------------- OperatorPanel ----------------------  //

OperatorPanel::OperatorPanel() {
}

OperatorPanel::~OperatorPanel() {
}

void OperatorPanel::TurnOnOperatorPanel() {
  _operator_panel_status = true;
}

void OperatorPanel::TurnOffOperatorPanel() {
  _operator_panel_status = false;
}

bool OperatorPanel::IsOperatorPanelOn() {
  return _operator_panel_status;
}

Money OperatorPanel::GetInitialCash(int num_bills) {
  Money starting_amount(num_bills * 20);
  return starting_amount;
}

//  ------------------------- Keyboard -------------------------  //

Keyboard::Keyboard() {}
Keyboard::~Keyboard() {}

int Keyboard::ReadPIN() {
  //  #TODO:  create hardware api for this
  std::cout << "...enter pin..." << std::endl;

  int entered_pin;

  while (!(std::cin >> entered_pin)) {
    std::cout << "Integers only." << std::endl;
    std::cin.clear();
    std::cin.ignore(20000, '\n');
  };

  return entered_pin;
}

int Keyboard::ReadMenuChoice() {
  //  #TODO:  create hardware api for this

  int menu_choice;
  while (!(std::cin >> menu_choice) || 
      (menu_choice < 1 || menu_choice > 4)) {
    std::cout << "Invalid menu choice." << std::endl;
    std::cin.clear();
    std::cin.ignore(20000, '\n');
  };

  return menu_choice;
  
}


Money Keyboard::ReadAmountEntry() {
  Money x;
  return x;
}
