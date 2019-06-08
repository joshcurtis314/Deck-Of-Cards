This file explains how to use the DeckOfCards object.

A full demo is given in the file DeckOfCards.cpp, printing the key results along the way to the output stream.  The steps in that file are:

1.	Declare a DeckOfCards (see DeckOfCards.h).  Upon declaration, the CardDeck will be initialized to contain an array (a C++ vector is used) of 52 Card objects.
	Each Card object (see card.h) has a "Suit" and a "Value".  The possible suits and values are enumerated (see suitsandvalues.h).
	At this point, the cards in the deck are in order, like when one buys them from the store.
2.	Shuffle the DeckOfCards.  After shuffling, the cards appear in the CardDeck in random order.
3.	One card is dealt by calling Deal- it will always be the first card in the shuffled order (the "top" card).
	Note that the CardDeck has had that first card removed from it- there are now 51 cards remaining in the deck.
4.	Optionally Deal the rest of the cards.  They come out in the shuffled order.
	Each time a card is dealt from the CardDeck, the CardDeck has that card removed from it.  When finished, there are no cards left in the CardDeck.
	This mimics what the dealer would be holding in their hand- a deck that always contains one less card after they deal one.
	In this way, the CardDeck is always representative of what the dealer is holding.