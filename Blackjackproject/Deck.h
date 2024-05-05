#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <list>
#include <set>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <random>

struct Card {
    std::string suit;
    
    std::string rank;

    // Using operator <
    bool operator<(const Card& other) const {
        return (suit < other.suit) || (suit == other.suit && rank < other.rank);
    }
};

class Deck {
    
private:
    //intitializing private list for cards
    std::list<Card> cards;
    
    std::set<Card> usedCards;  // Set to track cards that have been drawn

public:
    
    Deck() {
        initialize();
    }

    void initialize() {
        //creating suits for cards
        static const std::string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
        
        //creating ranks for cards
        static const std::string ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
        cards.clear();
        
        usedCards.clear();

        for (const auto& suit : suits) {
            for (const auto& rank : ranks) {
                cards.push_back({suit, rank});
            }
        }
        shuffle();
    }

    void shuffle() {
        // Using a more modern approach to shuffling directly the list
        std::random_device rd;
        std::mt19937 g(rd());
        cards.sort([&g](const Card& a, const Card& b) { return std::uniform_int_distribution<>(0,1)(g); });
    }

    Card drawCard() {
        if (!cards.empty()) {
            Card drawn = cards.front(); 
            
            // Remove the top card
            cards.pop_front(); 
            
            // Track the card as used
            usedCards.insert(drawn);  
            return drawn;
        }
        
        // Return a blank card if none are left
        return Card{"", ""}; 
    }

    bool isEmpty() const {
        return cards.empty();
    }

    bool isCardUsed(const Card& card) const {
        return usedCards.find(card) != usedCards.end();
    }
};

#endif // DECK_H
