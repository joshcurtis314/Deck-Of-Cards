#include "pch.h"
#include <iostream>
#include "deckofcards.h"

int main()
{
	// Declare and initialize the CardDeck
	DeckOfCards CardDeck;

	// Print out the contents of the CardDeck, pre-shuffle
	std::cout << "After initializing the CardDeck, the deck contains " << CardDeck.NumCards() << " cards, in order:" << std::endl;
	for (int k = 0; k < CardDeck.NumCards(); k++) {
		Card* card = CardDeck[k];
		std::cout << *card << std::endl;
	}

	// Shuffle the cards
	CardDeck.Shuffle();

	// Print out the contents of the CardDeck, post-shuffle
	std::cout << "After shuffling the CardDeck, the " << CardDeck.NumCards() << " cards are in random order:" << std::endl;
	for (int k = 0; k < CardDeck.NumCards(); k++) {
		Card* card = CardDeck[k];
		std::cout << *card << std::endl;
	}

	// Deal one card
	std::cout << "The first card dealt is the top card in the deck:" << std::endl;
	Card card;
	CardDeck.Deal(&card);
	std::cout << card << std::endl;
	std::cout << "One card has been dealt- the CardDeck now contains " << CardDeck.NumCards() << " cards." << std::endl;

	// optionally deal the rest of the cards
	std::cout << "As we continue to deal the cards, they come out in the shuffled order:" << std::endl;
	while(CardDeck.NumCards()) {
		Card card;
		CardDeck.Deal(&card);
		std::cout << card << std::endl;
	}
	std::cout << "The cards have now all been dealt- the CardDeck contains " << CardDeck.NumCards() << " cards." << std::endl;

	return 0;
}
