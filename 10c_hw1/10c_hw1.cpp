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
    int startMoney = 100;
    Player* p = new Player(startMoney);
    Player* d = new Player(900);
    
    //enveloping while loop to keep playing until player has 0 money or dealer reaches 0 money (i.e. dealer loses 900, because dealer will be designed to not gain money on player's loss)
    while (p->getMoney() != 0) {
        bool bust = false;
        int bet;
        cout << "\nYou have $" << p->getMoney() << ". Enter bet: ";

        cin >> bet;

        while (bet > p->getMoney()) {
            cout << "\nInsufficient balance. Bet exceeds player's current money. Try again: ";
            cin >> bet;
        }

        p->setMoney(p->getMoney() - bet);


        cout << "Your cards: ";
        p->showHand();

        p->getHand().sumTotalValue();
        cout << "Your total is " << p->getHand().getTotalValue() << "Do you want another card (y/n)? "; 

        while (response != 'n') {
            cin >> response;

            p->getHand().addCard();
            cout << "New card: " << p->getHand().showNewCard() << endl;

            cout << "Your cards: ";
            p->showHand();

            p->getHand().sumTotalValue();

            if (p->getHand().getTotalValue() <= 7.5) {
                cout << "Your total is " << p->getHand().getTotalValue() << "Do you want another card (y/n)? ";
            }
            else {
                bust = true;
                cout << "Too bad. You lose " << bet << ".";
                //don't update player's money - it was already taken away immediately after the bet was made
            }
        }

        //if player did not bust, total <= 7.5, it becomes the dealer's turn
        //otherwise the player has lost, skip the below portion involving the dealer drawing cards
        int dealerTotal = 0;
        if (!bust) {
            cout << "Dealer's cards: ";
            d->showHand();

            d->getHand().sumTotalValue();
            dealerTotal = d->getHand().getTotalValue();
            cout << "The dealer's total is " << dealerTotal << endl; 
            //while loop here for while dealer's total is <= 5.5
            while (dealerTotal <= 5.5) {
                d->getHand().addCard();
                cout << "New card: " << d->getHand().showNewCard();

                cout << "Dealer's cards: ";
                d->showHand();

                d->getHand().sumTotalValue();
                dealerTotal = d->getHand().getTotalValue();
                cout << "The dealer's total is " << dealerTotal << endl; //add Hand to Player's private members so the totalValue can be accessed
            }
        }

        //if dealer's total <= 7.5 && total > playerTotal player loses
        // ...continue other cases for win, lose, tie
        //game round ends there and game's overall while loop continues until palyer reaches 0 money or dealer loses 900
        if (dealerTotal > 7.5) {
            //player win
            p->setMoney(p->getMoney() + 2 * bet);
            cout << "You win " << bet << "." << endl;
        }
        else if (dealerTotal > p->getHand().getTotalValue()) {
            //dealer win
            cout << "Too bad. You lose " << bet << "." << endl;
        }
        else if (dealerTotal < p->getHand().getTotalValue()) {
            //player win
            p->setMoney(p->getMoney + 2 * bet);
            cout << "You win " << bet << "." << endl;
        }
        else {
            //tie
            p->setMoney(p->getMoney + bet);
            cout << "It was a tie. There player's bet has been returned. " << endl;
        }
    }

    return 0;
}
