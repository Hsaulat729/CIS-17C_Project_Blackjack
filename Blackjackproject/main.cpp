/*Created by Humza A Saulat
 * CIS-17C- 43673
 * Professor Mark E. Lehr
 * Norco College
 * 5/5/2025
 */

#include <iostream>
#include "Deck.h"
#include "Dealer.h"
#include "Player.h"
#include "Splitting.h"
#include "Double_Down.h"
#include "Help.h" // Include the Help header for rules display
#include <string>

int main() {
    // Introduction and welcoming player to the game
    std::cout << "Welcome to the Spectacular Virtual Blackjack Table!\n";
    std::cout << "The cards are shuffling, the bets are mounting, and the stakes are as high as the sky!\n\n";
    
    // Ask the player if they want to see the rules
    std::cout << "Would you like to see the rules of Blackjack? (y/n): ";
    char showRules;
    std::cin >> showRules;
    if (showRules == 'y' || showRules == 'Y') {
        // Display the rules
        Help::displayRules(); 
    }

    // Initialize the deck and shuffle it
    Deck deck;
    
    deck.shuffle();
    
    // Set initial amount for the player
    double startingMoney = 1000; 
    
    Player player(startingMoney);
    
    Dealer dealer;

    // Main game loop
    while (true) {
        std::cout << "You currently have $" << player.getMoney() << ". How daring do you feel today? What's your bet? ";
        double betAmount;
        
        // Player inputs their bet amount
        std::cin >> betAmount; 
        
         // Place the bet
        player.placeBet(betAmount);

        //dealer initialized for new game
        dealer.newGame();
        
        // Prepare the player's hand for a new game
        player.clearHand(); 

        // Draw initial cards for the player
        player.addCard(deck.drawCard());
        
        player.addCard(deck.drawCard());
        
        //Dealer's initial hand is shown
        std::cout << "\nThe dealer smirks as he reveals his initial hand:\n";
        
        dealer.displayInitialHand();
        
        std::cout << "Your cards whisper a tale of fortune or despair:\n";
        player.displayHand();

        // Check if the player can split their hand
        if (player.canSplit()) {
            Splitting::offerSplit(player, deck);
        }

        // Offer to double down if conditions are met
        if (player.getHandValue() == 9 || player.getHandValue() == 10 || player.getHandValue() == 11) {
            
            std::cout << "Fortune favors the bold! Do you wish to double down? (y/n): ";
            
            char response;
            
            std::cin >> response;
            if (response == 'y' || response == 'Y') {
                
                 // Double the bet
                player.placeBet(player.getCurrentBet());
                
                // Add one more card
                player.addCard(deck.drawCard()); 
                
                // Show the updated hand
                player.displayHand(); 

                if (player.getHandValue() > 21) {
                    
                    std::cout << "Alas, fate is cruel! You bust with a hand value of " << player.getHandValue() << ".\n";
                    
                    std::cout << "You lost $" << player.getCurrentBet() << ".\n\n";
                    continue;
                }
                // Skip to dealer's turn if the player is finished
                goto DEALER_TURN; 
            }
        }

        // Normal game play loop for hitting or standing
        char decision;
        do {
            std::cout << "Will you hit (h) or stand (s)? Choose wisely: ";
            
            std::cin >> decision;

            if (decision == 'h' || decision == 'H') {
                //Player's decision for hitting
                player.addCard(deck.drawCard());
                player.displayHand();

                if (player.getHandValue() > 21) {
                    //If player busts
                    std::cout << "Oh, tragedy! You bust with a hand value of " << player.getHandValue() << ".\n";
                    
                    std::cout << "You lost $" << player.getCurrentBet() << ".\n";
                    break;
                }
            } else {
                
                std::cout << "A calm decision to stand. Let's see how the cards fall.\n";
            }
        } while (decision != 's' && decision != 'S');

        DEALER_TURN:
        // Dealer's game play logic
        while (dealer.mustHit()) {
            //Dealer takes card
            dealer.dealCardToSelf();
            
            //Dealer shows hand
            dealer.displayHand();
            
            if (dealer.getHandValue() > 21) {
                
                std::cout << "The dealer fumbles and busts with a hand value of " << dealer.getHandValue() << "!\n";
                player.winBet();
                break;
                
            }
        }

        // Comparison of hands if neither has busted
        if (dealer.getHandValue() <= 21 && player.getHandValue() <= 21) {
            
            if (player.getHandValue() > dealer.getHandValue()) {
                
                player.winBet();
            } else if (player.getHandValue() < dealer.getHandValue()) {
                
                std::cout << "The dealer grins, victorious!\n";
                
                std::cout << "You lost $" << player.getCurrentBet() << ".\n";
            } else {
                player.drawBet();
                std::cout << "It ends in a draw. Your bet is returned to you.\n";
            }
        }

        // Update and display player's current financial status
        std::cout << "\nYour fortune now stands at $" << player.getMoney() << ".\n";
        
        std::cout << "Do you wish to tempt fate again? (y/n): ";
        
        //initializing response for playing again
        char playAgain;
        
        //user's input for playing again
        std::cin >> playAgain;
        
        if (playAgain != 'y' && playAgain != 'Y') {
            
            std::cout << "\nThank you for playing at our esteemed table. Return when the cards call you again!\n";
            break;
            
        }
    }

    return 0;
}
