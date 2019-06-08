// Header file to define the DeckOfCards class and the attributes of a deck of cards
#include <vector>
#include <ctime>
#include <cstdlib>
#include "card.h"

#define NCARDS  52

class DeckOfCards {
public:
	// Constructor
	DeckOfCards() {
		// fill out the deck
		int order = 1;
		for (int suit = Diamond; suit <= Spade; suit++) {
			for (int value = Ace; value <= King; value++) {
				Card card((CardSuit)suit, (CardValue)value);
				Cards.push_back(card);
			}
		}
	}

	// Shuffle the deck into a random order
	void Shuffle() {
		// Make a new vector of cards- this will be the shuffled result
		std::vector<Card> NewCards;

		/* initialize random seed and throw away the first couple of random numbers */
		srand((unsigned)time(0));
		rand();
		rand();
		
		// choose one Card at a time from the Cards array
		while (Cards.size()) {
			// pick a random number from 0 to RAND_MAX inclusive
			int irand = rand();

			// put in the decimal range from [0...Cards.size())
			double drand = (double)irand;		// decimal version of irand
			drand /= (double)(RAND_MAX + 1);	// [0...1)
			drand *= (double)Cards.size();		// [0...Cards.size())

			// determine which integer position this means in Cards
			int index = (int)drand;  // [0...Cards.size()-1]

			// Store this card in the newCards array
			NewCards.push_back(Cards[index]);

			// and remove this card rom the Cards array
			Cards.erase(Cards.begin() + index);
		}

		// swap the (shuffled) NewCards into the Cards array
		Cards.swap(NewCards);
	}

	// Deal a card from the top of the deck- this fills out the dealt card into the card passed in
	void Deal(Card* card) {
		if (!Cards.size()) {
			std::cout << "--err: there are no more cards to deal in the deck" << std::endl;
			throw std::exception("--err: there are no more cards to deal in the deck");
		}

		// make a copy of the card to be dealt- the one on top of the deck
		card->Suit(Cards[0].Suit());
		card->Value(Cards[0].Value());

		// remove this card from the deck
		Cards.erase(Cards.begin());
	}

	// report the current number of cards in the deck
	int NumCards() { return Cards.size(); }

	// ability to return a requested card
	Card* operator[](int k) { return &Cards[k];  }

private:
	std::vector<Card> Cards;
};