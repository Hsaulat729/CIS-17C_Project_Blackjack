// Dealer.h
/*Created by Humza A Saulat
 * CIS-17C- 43673
 * Professor Mark E. Lehr
 * Norco College
 * 5/5/2025
 */
#ifndef DEALER_H
#define DEALER_H

#include "Deck.h"
#include <list>
#include <stack>
#include <map>
#include <algorithm>
#include <iterator>
#include <iostream>

class Dealer {
    //dont want any piece of code to touch any private sections
private:
    //creating stack for deck
    
    std::stack<Card> deck;
    
    //creating list for hand instead of using vector
    
    std::list<Card> hand;
    int handValue;
    bool isSoft;

    void calculateHandValue() {
        handValue = 0;
        int aceCount = 0;
        
        //giving values for dealers hand
        
        //matches in deck.h
        std::map<std::string, int> cardValues = {
            {"2", 2}, {"3", 3}, {"4", 4}, {"5", 5}, {"6", 6},
            {"7", 7}, {"8", 8}, {"9", 9}, {"10", 10},
            {"Jack", 10}, {"Queen", 10}, {"King", 10}, {"Ace", 11}
        };

        for (const Card& card : hand) {
            
            //values assigned to cards with their rank
            int value = cardValues[card.rank];
            
            //initializes ace can be worth 1
            if (card.rank == "Ace") {
                aceCount++;
                handValue += 11;
            } else {
                handValue += value;
            }
        }
        
        //logic for amount of aces in hand increases hand value
        while (handValue > 21 && aceCount > 0) {
            handValue -= 10;
            aceCount--;
        }
        isSoft = (aceCount > 0) && (handValue <= 21);
    }

public:
    // utilizing STL for dealers hand
    Dealer() : handValue(0), isSoft(false) {
        Deck initialDeck;
        
        //deck is shuffled again
        initialDeck.shuffle();
        
        while (!initialDeck.isEmpty()) {
            deck.push(initialDeck.drawCard());
        }
    }
    
    //"drawing cards for dealers self"

    void dealCardToSelf() {
        if (!deck.empty()) {
            hand.push_back(deck.top());
            deck.pop();
            calculateHandValue();
        }
    }
// allows for dealers hand to be redone for new game
    void newGame() {
        //hand is cleared for dealer for new game
        hand.clear();
        //initial hand value is set to 0
        handValue = 0;
        isSoft = false;
    }

    const std::list<Card>& getHand() const {
        return hand;
    }

    int getHandValue() const {
        return handValue;
    }

    bool mustHit() const {
        //testing to see if hand value is below 17 causing dealer to hit again
        return handValue < 17 || (isSoft && handValue == 17);
    }

    void displayHand() const {
        
        //displaying dealer's hand
        std::cout << "Dealer's hand:" << std::endl;
        for (const Card& card : hand) {
            //displaying rank and suit of card pulled by dealer
            std::cout << card.rank << " of " << card.suit << std::endl;
            
        }
    }
// show initial hand to user
    void displayInitialHand() const {
        if (!hand.empty()) {
            auto it = hand.begin();
            std::cout << "Dealer's shown card: " << it->rank << " of " << it->suit << std::endl;
            std::cout << "One card hidden" << std::endl;
        }
    }

    void displayFullHand() const {
        displayHand();  // Assuming displayHand() shows all cards
    }
};

#endif // DEALER_H
