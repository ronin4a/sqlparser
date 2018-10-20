class ATM;
class Bank;
class Money;
class Session;
class Status;

class Transaction {

  public:
    Transaction(Session &session, ATM &atm, Bank &bank);
    ~Transaction();

    //  Get transaction choice from user
    static Transaction *ChooseTransaction(Session &session, ATM &atm, Bank &bank);

    //  Execute chosen transaction
    Status::Code ExecuteTransaction();

    virtual Status::Code GetTransactionFromCustomer() = 0;
    virtual Status::Code SendToBank() = 0;
    virtual Status::Code CompleteApprovedTransaction() = 0;

  protected:
    Session &_session;
    ATM &_atm;
    Bank &_bank;

    //  Each transaction tagged w/ unique serial number
    int _serial_number; 
    //  Each transaction gets updated balance and available balance
    Money _new_balance, _available_balance;

  private:
    static int _last_serial_number_assigned;

};

class WithDrawalTransaction : public Transaction {
  public:
    WithdrawalTransaction(Session &session, ATM &atm, Bank &bank);

    Status::Code GetTransactionFromCustomer() = 0;
    Status::Code SendToBank() = 0;
    Status::Code CompleteApprovedTransaction() = 0;

  private:
    Bank::AccountType _from_account;
    Money _amount;
};

class DepositTransaction : public Transaction {
  public:
    DepositTransaction(Session &session, ATM &atm, Bank &bank);

    Status::Code GetTransactionFromCustomer() = 0;
    Status::Code SendToBank() = 0;
    Status::Code CompleteApprovedTransaction() = 0;

  private:
    Bank::AccountType _from_account;
    Money _amount;
};

class TransferTransaction : public Transaction {
  public:
    TransferTransaction(Session &session, ATM &atm, Bank &bank);

    Status::Code GetTransactionFromCustomer() = 0;
    Status::Code SendToBank() = 0;
    Status::Code CompleteApprovedTransaction() = 0;

  private:
    Bank::AccountType _from_account, _to_account;
    Money _amount;
};

class InquiryTransaction : public Transaction {
  public:
    InquiryTransaction(Session &session, ATM &atm, Bank &bank);

    Status::Code GetTransactionFromCustomer() = 0;
    Status::Code SendToBank() = 0;
    Status::Code CompleteApprovedTransaction() = 0;

  private:
    Bank::AccountType _from_account;
};


