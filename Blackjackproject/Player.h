/*Created by Humza A Saulat
 * CIS-17C- 43673
 * Professor Mark E. Lehr
 * Norco College
 * 5/5/2025
 */
#ifndef PLAYER_H
#define PLAYER_H

#include "Deck.h"
#include <list>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <map>

class Player {
private:
     // List to store cards in the player's current hand
    std::list<Card> hand; 
    
    // Lists to store cards in each of the split hands, if splitting occurs
    
    std::list<Card> splitHand1, splitHand2; 
    
    // The total value of the current hand, computed according to blackjack rules
    
    int handValue; 
    
    // True if the hand contains an Ace counted as 11 without busting
    
    bool isSoft; 
    
    // Player's total money available for betting
    double money; 
    
    // Current bet amount placed by the player
    
    double currentBet; 
    // Flag to indicate if the player has chosen to double down
    bool doubleDown; 

    // Private method to calculate the value of a given hand
    void calculateHandValue(const std::list<Card>& cards, int& value) {
        value = 0;
        // Number of Aces, which can potentially be valued as 1 or 11
        int aceCount = 0; 
        
        std::map<std::string, int> cardValues = {
            
            {"2", 2}, {"3", 3}, {"4", 4}, {"5", 5}, {"6", 6},
            
            {"7", 7}, {"8", 8}, {"9", 9}, {"10", 10},
            
            {"Jack", 10}, {"Queen", 10}, {"King", 10}, {"Ace", 11}
        };

        // Calculate the value of the hand, accounting for Aces
        std::for_each(cards.begin(), cards.end(), [&](const Card& card) {
            
            int cardValue = cardValues[card.rank];
            if (card.rank == "Ace") {
                aceCount++;
                value += 11;
            } else {
                value += cardValue;
            }
        });

        // If value exceeds 21 and there are Aces in the hand, reduce their value to 1
        while (value > 21 && aceCount > 0) {
            value -= 10;
            aceCount--;
        }
    }

public:
    // Constructor initializes player with a given amount of money
    Player(double initialMoney) : handValue(0), isSoft(false), money(initialMoney), currentBet(0), doubleDown(false) {}

    // Adds a card to the player's hand and recalculates its value
    void addCard(const Card& card) {
        if (!doubleDown) {
            hand.push_back(card);
            calculateHandValue(hand, handValue);
        }
    }

    // Places a bet, ensuring the player has enough money to cover it
    bool placeBet(double bet) {
        if (bet > money) {
            std::cout << "Not enough money to place that bet. You have $" << money << " available." << std::endl;
            return false;
        }
        currentBet = bet;
        money -= bet;
        return true;
    }

    // Clears the current hand to prepare for a new round
    void clearHand() {
        hand.clear();
        handValue = 0;
        isSoft = false;
        doubleDown = false;
    }

    // Returns the total value of the current hand
    int getHandValue() const {
        return handValue;
    }

    // Returns the current bet amount
    double getCurrentBet() const {
        return currentBet;
    }

    // Sets the double down status
    void setDoubleDown(bool value) {
        doubleDown = value;
    }

    // Processes a win, doubling the current bet
    void winBet() {
        std::cout << "Congratulations! Your winning current bet: $" << currentBet << std::endl;
        money += currentBet * 2;
        currentBet = 0;
    }

    // Handles a draw, returning the bet to the player
    void drawBet() {
        std::cout << "It's a draw. Returning your bet: $" << currentBet << std::endl;
        money += currentBet;
        currentBet = 0;
    }

    // Returns the player's total money
    double getMoney() const {
        return money;
    }

    // Checks if the player is bankrupt
    bool isBankrupt() const {
        return money <= 0;
    }

    // Returns the cards in the player's current hand
    const std::list<Card>& getHand() const {
        return hand;
    }

    // Determines if the player's hand is eligible for splitting
    bool canSplit() const {
        return hand.size() == 2 && hand.front().rank == hand.back().rank;
    }

    // Sets up split hands if splitting occurs
    void setSplitHands(const std::list<Card>& hand1, const std::list<Card>& hand2) {
        splitHand1 = hand1;
        splitHand2 = hand2;
    }

    // Displays the current hand of the player
    void displayHand() const {
        std::cout << "Player's hand:" << std::endl;
        std::for_each(hand.begin(), hand.end(), [](const Card& card) {
            std::cout << card.rank << " of " << card.suit << std::endl;
        });
    }

    // Displays split hand if splitting has occurred
    void displaySplitHand(const std::list<Card>& splitHand) const {
        
        std::cout << "Split hand:" << std::endl;
        std::for_each(splitHand.begin(), splitHand.end(), [](const Card& card) {
            
            std::cout << card.rank << " of " << card.suit << std::endl;
        });
    }
};

#endif // PLAYER_H
