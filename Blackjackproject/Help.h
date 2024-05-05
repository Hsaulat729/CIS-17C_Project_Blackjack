// Help.h - Provides help and game rules for the Blackjack game.
/*Created by Humza A Saulat
 * CIS-17C- 43673
 * Professor Mark E. Lehr
 * Norco College
 * 5/5/2025
 */
#ifndef HELP_H
#define HELP_H

#include <iostream>
#include <string>

class Help {
public:
    //Basic rules of Blackjack
    static void displayRules() {
        
        std::cout << "\n===== Blackjack Rules =====\n";
        
        std::cout << "1. The goal of blackjack is to beat the dealer's hand without going over 21.\n";
        
        std::cout << "2. Face cards (Kings, Queens, Jacks) are worth 10 points. Aces are worth 1 or 11 points, whichever makes a better hand.\n";
        
        std::cout << "3. Each player starts with two cards, one of the dealer's cards is hidden until the end.\n";
        
        std::cout << "4. To 'Hit' is to ask for another card. To 'Stand' is to hold your total and end your turn.\n";
        
        std::cout << "5. If you go over 21 you bust, and the dealer wins regardless of the dealer's hand.\n";
        
        std::cout << "6. If you are dealt 21 from the start (Ace & 10), you got a blackjack.\n";
        
        std::cout << "7. Dealer will hit until his/her cards total 17 or higher.\n";
        
        std::cout << "8. Doubling down is allowed on the first two cards, doubling your bet and receiving exactly one more card.\n";
        
        std::cout << "9. Split is allowed when you have two of the same card - the pair is split into two hands.\n";
        
        std::cout << "10. You can only double/split on the first move, or first move of a hand created by a split.\n";
        
        
        //Basic Tips of Blackjack
        
        std::cout << "12. HELPFUL TIPS FOR BEGINNERS-----------------------------------------------------------------------\n";
        
        std::cout << "13. Split aces and 8s\n";
        
        std::cout << "14. Stand on 17\n";
        
        std::cout << "15. Always hit 12 to 16\n";
        
        std::cout << "If hand is 11 always double\n";
        
        std::cout << "If hand is 8 or less always hit, it is too low to double and is impossible to bust\n";
        
        std::cout << "If wanting to play safe can always stand on anything at 18 above.\n";
        
        std::cout << "Stand on two face card draw as you are already 20 and will always be a safe bet\n";
        
        std::cout << "GOOD LUCK IN YOUR GAMES OF BLACKJACK AND ABOVE ALL, HAVE FUN!!!!!\n";
        
        std::cout << std::endl;
                
    }
        
};

#endif // HELP_H
