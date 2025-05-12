#pragma once
#include "Suit.h"
class Card
{
	Suit m_suit; // Type of suit of card
	int m_value; // From 1 to 10, 11 = Jack, 12 = Queen, 13 = King

	// Constructor: initializes the values in each card
	Card(Suit suit, int value)
	{
		suit = m_suit;
		value = m_value;
	}
	// Compares if 2 cards are the same
	bool operator==(Card& card)
	{
		return m_suit == card.m_suit && m_value == card.m_value;
	}

};