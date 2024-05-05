// DoubleDown.h
/*Created by Humza A Saulat
 * CIS-17C- 43673
 * Professor Mark E. Lehr
 * Norco College
 * 5/5/2025
 */
#ifndef DOUBLE_DOWN_H
#define DOUBLE_DOWN_H

#include "Player.h"

class DoubleDown {
public:
    static void offerDoubleDown(Player& player, Card newCard) {
        
        if (player.getHandValue() >= 9 && player.getHandValue() <= 11) {
            
            std::cout << "Would you like to double down? (y/n): ";
            char response;
            
            std::cin >> response;
            
            if (response == 'y' || response == 'Y') {
                // Place an additional bet equal to the original
                player.placeBet(player.getCurrentBet()); 
                // Add only one card to the player's hand
                player.addCard(newCard);  
                // Ensure no further cards can be added
                player.setDoubleDown(true); 
            }
        }
    }
};

#endif // DOUBLE_DOWN_H
