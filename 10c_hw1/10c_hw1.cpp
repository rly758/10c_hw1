#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
using namespace std;

// Global constants (if any)


// Non member functions declarations (if any)


// Non member functions implementations (if any)


// Stub for main
int main() {
    /* --STATEMENTS-- */
    char response = 'y';
    int startMoney = 100, bet;
    Player* p = new Player(startMoney);
    Player* d = new Player(900);
    
    //enveloping while loop to keep playing until player has 0 money or dealer reaches 0 money (i.e. dealer loses 900, because dealer will be designed to not gain money on player's loss)
    while (p->getMoney() != 0) {
        cout << "You have $" << p->getMoney() << ". Enter bet: ";

        cin >> bet;

        while (bet > p->getMoney()) {
            cout << "\nInsufficient balance. Bet exceeds player's current money. Try again: ";
            cin >> bet;
        }

        p->setMoney(p->getMoney() - bet);


        cout << "Your cards: " << endl;
        p->showHand();

        p->getHand().sumTotalValue();
        cout << "Your total is " << p->getHand().getTotalValue() << "Do you want another card (y/n)? "; 

        while (response != 'n') {
            cin >> response;

            p->getHand().addCard();
            cout << "New card:\n\t" << p->getHand().showNewCard() << endl;

            cout << "Your cards: " << endl; //implement showCards function for Hand 
            cout << "Your total is " << "Do you want another card (y/n)? "; //Add Hand as a private member of Player to access the player's hand's total value
        }

        //if player has not lost yet, total <= 7.5
        //else the palyer has lost, skip the below portion involving the dealer drawing cards

        cout << "Dealer's cards: " << endl; //showCards
        cout << "The dealer's total is " << endl; //add Hand to Player's private members so the totalValue can be accessed
        //while loop here for while dealer's total is <= 5.5
        cout << "New card: " << endl; //add Hand to Player's private members so the totalValue can be accessed
        cout << "Dealer's cards: " << endl; //showCards
        cout << "The dealer's total is " << endl; //add Hand to Player's private members so the totalValue can be accessed
        //end while loop

        //if dealer's total <= 7.5 && total > playerTotal player loses
        // ...continue other cases for win, lose, tie
        //game round ends there and game's overall while loop continues until palyer reaches 0 money or dealer loses 900
    }

    return 0;
}
