// Splitting.h
/*Created by Humza A Saulat
 * CIS-17C- 43673
 * Professor Mark E. Lehr
 * Norco College
 * 5/5/2025
 */
#ifndef SPLITTING_H
#define SPLITTING_H

#include "Player.h"
#include <list>
#include <iostream>

class Splitting {
public:
    static void offerSplit(Player& player, Deck& deck) {
        
        // Check if the player's initial two cards are of the same rank and splitting is possible
        
        if (player.canSplit()) {
            std::cout << "Your cards have the same rank. Would you like to split them? (y/n): ";
            char response;
            std::cin >> response;
            if (response == 'y' || response == 'Y') {
                // Split the hand and deal an additional card to each hand
                
                std::list<Card> firstHand, secondHand;
                
                // Add the first card to the first new hand
                
                firstHand.push_back(player.getHand().front());  
                 // Add the second card to the second new hand
                
                secondHand.push_back(player.getHand().back()); 

                // Draw an additional card for each hand
                firstHand.push_back(deck.drawCard());
                
                secondHand.push_back(deck.drawCard());

                // Set the split hands in the player object
                player.setSplitHands(firstHand, secondHand);
                // Split hands first and second controller
                std::cout << "Hand 1 after splitting:" << std::endl;
                
                player.displaySplitHand(firstHand);
                
                std::cout << "Hand 2 after splitting:" << std::endl;
                
                player.displaySplitHand(secondHand);
            }
        }
    }
};

#endif // SPLITTING_H
