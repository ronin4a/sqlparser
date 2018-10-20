/*  Classes for parts of the ATM:
 *     - CardReader
 *     - Display
 *     - Keyboard
 *     - CashDispenser
 *     - EnvelopeAcceptor
 *     - ReceiptPrinter
 *     - OperatorPanel
 */

#include <iostream>

class Money;

//  CardReader for accepting and ejecting cards
class CardReader {

  public:
    CardReader();
    ~CardReader();

    enum ReaderStatus
    {
      NO_CARD,
      UNREADABLE_CARD,
      CARD_HAS_BEEN_READ
    };

    ReaderStatus CheckForInsertedCard();

    int CardNumber() const;

  private:

    ReaderStatus _status;
    int _card_number_read;
    void AcceptCard();
    void EjectCard();

};

//  Display class = UI for the user.
//  Currently just text stream onto the terminal.
//  If there is an appetite to port this over via a web UI, then maybe learn how
//  to use a Python to wrap this -> push to web UI using Flask.
class Display {

  private:
    void DisplayHeader();
    void DisplayFooter();

  public:
    Display();
    ~Display();

    //  Accessors and Mutators

    //  --  Initial screens
    void RequestCard();
    void RequestPIN();


    //  --  Display options
    void DisplayMenu();
    /*

    //  --  Follow-up actions/requests
    void RequestAmountEntry();
    void RequestDepositEnvelope();

    //  --  Error messaging
    void ReportCardUnreadable();
    void ReportTransactionFailure();
    void RequestReEnterPIN();
    void ReportCardRetained();

    //  --  Misc display options
    void EchoInput(char *echo_this);
    void ClearDisplay();
    */

};

class OperatorPanel {
  public:
    OperatorPanel();
    ~OperatorPanel();

    bool IsOperatorPanelOn();

    //  Human Operator must confirm initial num of $20 denominations
    Money GetInitialCash(int num_bills);
    void TurnOnOperatorPanel();
    void TurnOffOperatorPanel();

  private:
    bool _operator_panel_status;
  
};

class Keyboard {
  public:
    Keyboard();
    ~Keyboard();

    int ReadPIN();
    int ReadMenuChoice();
    Money ReadAmountEntry();

};

/*
class CashDispenser {
  public:
    CashDispenser();
    ~CashDispenser();
};

class EnvelopeAcceptor {
  public:
    EnvelopeAcceptor();
    ~EnvelopeAcceptor();
};

class ReceiptPrinter {
  public:
    ReceiptPrinter();
    ~ReceiptPrinter();
};

*/
