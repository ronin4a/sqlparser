#include "atm.h"
#include "bank.h"
#include "money.h"
#include "session.h"
#include "status.h"

Transaction::Transaction(Session &session, ATM &atm, Bank &bank) :
  _session(session),
  _atm(atm),
  _bank(bank)
{ }

Transaction::~Transaction() { };

Transaction *Transaction::ChooseTransaction(Session &session, 
      ATM &atm,
      Bank &bank) {

  //  Get menu choice
  int menu_choice;
  menu_choice = _atm.GetMenuChoice();

  switch (menu_choice) {
    case 1:
      return new WithDrawalTransaction(session, atm, bank);
    case 2:
      return new DepositTransaction(session, atm, bank);
    case 3:
      return new TransferTransaction(session, atm, bank);
    case 4:
      return new InquiryTransaction(session, atm, bank);
    default:
      std::cout << "CRITICAL ERROR" << std::endl;
  }
}

//  #TODO
Status::Code Transaction::ExecuteTransaction() {
}

//  --------------------- Sub-constructors ---------------------  //

WithdrawalTransaction::WithdrawalTransaction(Session &session, ATM &atm, Bank &bank) :
  Transaction(session, atm, bank)
{ }

DepositTransaction::DepositTransaction(Session &session, ATM &atm, Bank &bank) :
  Transaction(session, atm, bank)
{ }

TransferTransaction::TransferTransaction(Session &session, ATM &atm, Bank &bank) :
  Transaction(session, atm, bank)
{ }

InquiryTransaction::InquiryTransaction(Session &session, ATM &atm, Bank &bank) :
  Transaction(session, atm, bank)
{ }


//  ---------  Sub-mutators: Additional details from client  -----------  //

Status::Code WithdrawalTransaction::GetTransactionFromCustomer() {
}

Status::Code DepositTransaction::GetTransactionFromCustomer() {
}

Status::Code TransferTransaction::GetTransactionFromCustomer() {
}

Status::Code Inquirytransaction::GetTransactionFromCustomer() {
}

//  --------------  Sub-mutators: Send request to bank  ---------------  //

Status::Code WithdrawalTransaction::SendToBank(){
}

Status::Code DepositTransaction::SendToBank(){
}

Status::Code TransferTransaction::SendToBank(){
}

Status::Code Inquirytransaction::SendToBank(){
}


//  --------------  Sub-mutators: Complete Transaction  ----------------  //

Status::Code WithdrawalTransaction::CompleteApprovedTransaction() {
}

Status::Code DepositTransaction::CompleteApprovedTransaction() {
}

Status::Code TransferTransaction::CompleteApprovedTransaction() {
}

Status::Code Inquirytransaction::CompleteApprovedTransaction() {
}
