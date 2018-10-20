/*
 *  This class represents the ATM itself.
 */

class Bank;
class Display;
class OperatorPanel;
class Money;
class CardReader;
class Keyboard;
class Session;

class ATM {

  public:

    //  --- Constructors and Destructores  --- //
    ATM(int number, const char * location, Bank &bank);
    ~ATM();

    //  --- Bookend operations  --- //
    void StartUpATM();
    void ShutDownATM();

    //  --- ATM OperatorPanel operations  --- //
    //  #TODO: include login/encryption for operator
    void CheckATMCash();
    
    //  --- ATM user operations --- //

    //  - General wrapper around other helper functions to run ATM
    void ServiceCustomers();

    //  - User interfaces
    int GetCustomerPIN() const;
    int ReEnterPIN() const;
    int GetMenuChoice();

    //  - Cash withdrawal
    Money GetRequestedAmount() const;
    bool CheckIfCashAvailable(Money amount_requested);
    void DispenseCash();

    //  - Deposit
    bool AcceptEnvelope();

    //  - Closing functions
    void IssueReceipt();

    //  - General reports
    bool ReportError();
    void RejectCard();
    void RetainCard();

    //Money

  private:

    int _number;  //  ID number
    const char * _location; //  Location of ATM
    Bank &_bank; //  Instance of Bank

    Display &_display;
    OperatorPanel &_operatorPanel;
    Money &_atm_balance;
    CardReader &_cardReader;
    Keyboard &_keyboard;

    /*
    //  Customer interfaces
    CashDispenser & _cashDispenser;
    EnvelopeAcceptor & _envelopeAcceptor;
    ReceiptPrinter & _receiptPrinter;

    //  Operator interface
    */

    //  ATM state
    enum {RUNNING, STOPPED} _state;

};
