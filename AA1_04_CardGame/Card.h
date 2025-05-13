#pragma once
#include "Suit.h"
#include <string>
class Card
{
private:
	Suit m_suit; // Type of suit of card
	int m_value; // From 1 to 10, 11 = Jack, 12 = Queen, 13 = King
public:
	// Constructor: initializes the values in each card
	Card(Suit suit, int value)
	{
		m_suit = suit;
		m_value = value;
	}
	int GetValue() const
	{
		return m_value;
	}
	Suit GetSuit() const
	{
		return m_suit;
	}
	// Compares if 2 cards are the same
	bool operator==(const Card& other)
	{
		return m_suit == other.m_suit && m_value == other.m_value;
	}
};