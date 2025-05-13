#pragma once
#include "Suit.h"
#include <string>
#include <iostream>
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
	bool operator==(const Card& other) const
	{
		return m_suit == other.m_suit && m_value == other.m_value;
	}
};

inline std::ostream& operator<<(std::ostream& os, const Card& card)
{
	std::string valueStr;
	switch (card.GetValue()) {
	case 11: 
		valueStr = "Jack"; 
		break;
	case 12: 
		valueStr = "Queen"; 
		break;
	case 13: 
		valueStr = "King"; 
		break;
	default: 
		valueStr = std::to_string(card.GetValue()); 
		break;
	}

	std::string suitStr;
	switch (card.GetSuit()) 
	{
	case Suit::HEART: 
		suitStr = "HEART"; 
		break;
	case Suit::DIAMOND: 
		suitStr = "DIAMOND"; 
		break;
	case Suit::SPADE: 
		suitStr = "SPADE"; 
		break;
	case Suit::CLUB: 
		suitStr = "CLUB"; 
		break;
	}

	os << valueStr << " of " << suitStr;
	return os;
}