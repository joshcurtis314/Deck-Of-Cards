// Header file to define the Card class, and the attributes of a single card
#include <iostream>
#include <string>
#include "suitsandvalues.h"

class Card {
public:
	// Bare constructor- should not be used
	Card() {}

	// Constructor where a suit and value are specified
	Card(CardSuit suit, CardValue value) {
		mSuit = suit;
		mValue = value;
	}

	// Constructor where another card is passed for initialization instead
	Card(Card* card) {
		mSuit = card->Suit();
		mValue = card->Value();
	}

	// Set the suit or value separately
	void Suit(CardSuit suit) { mSuit = suit; }
	void Value(CardValue value) { mValue = value; }

	// report what the suit or value currently is
	CardSuit Suit() { return mSuit; }
	CardValue Value() { return mValue; }

	// ability to print out the Card easily
 	friend std::ostream& operator<< (std::ostream &out, const Card& card) {
		switch (card.mValue) {
		case Ace	:	out << "A"; break;
		case Two	:	out << "2"; break;
		case Three	:	out << "3"; break;
		case Four	:	out << "4"; break;
		case Five	:	out << "5"; break;
		case Six	:	out << "6"; break;
		case Seven	:	out << "7"; break;
		case Eight	:	out << "8"; break;
		case Nine	:	out << "9"; break;
		case Ten	:	out << "10"; break;
		case Jack	:	out << "J"; break;
		case Queen	:	out << "Q"; break;
		case King	:	out << "K"; break;
		}

		switch (card.mSuit) {
		case Diamond:	out << "d"; break;
		case Club	:	out << "c"; break;
		case Heart	:	out << "h"; break;
		case Spade	:	out << "s"; break;
		}

		return out;
	}

private:
	CardSuit mSuit;
	CardValue mValue;
};