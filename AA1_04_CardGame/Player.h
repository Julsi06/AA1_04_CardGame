#pragma once
#include "Card.h"
#include <vector>
#include <algorithm>
#include <iostream>
class Player
{
private:
	std::string m_id;
	std::vector<Card> m_hand; // Vector that contains the hand of cards each player has

	int GetSuitRank(Suit suit) const // Establishes priority of suits
	{
		switch (suit)
		{
		case Suit::HEART: return 4;
		case Suit::DIAMOND: return 3;
		case Suit::SPADE: return 2;
		case Suit::CLUB: return 1;
		default: return 0;
		}
	}
	bool GetOrderCards(const Card& card1, const Card& card2) // Returns the card either by suit priority or by highest value
	{
		if (GetSuitRank(card1.GetSuit()) != GetSuitRank(card2.GetSuit()))
			return GetSuitRank(card1.GetSuit()) > GetSuitRank(card2.GetSuit());
		return card1.GetValue() > card2.GetValue();
	}
public:
	void InsertCard(Card card) // Inserts card in player's hand
	{
		// it is incremented until the position is end()
		auto it = m_hand.begin();
		// Compares the card at that position with the card referenced as a parameter, and checks which one is of highest value
		while (it != m_hand.end() && GetOrderCards(*it, card))
		{
			++it;
		}
		// Places said card at said position (in this case, at the end)
		m_hand.insert(it, card);
	}
	Card GetCard() const // Returns random card
	{
		auto it = m_hand.begin();
		int randomCardIndex = rand() % m_hand.size();
		// Moves iterator until it reaches the randomCardIndex position, the returns the value
		std::advance(it, randomCardIndex);
		return *it;
	}
	Card GetCard(const Suit& suit) // Returns the card with highest value of said suit
	{
		// Goes through each element of the vector
		// Option 1
		for (auto it = 0;it < m_hand.size();++it)
		{
			if (m_hand[it].GetSuit() == suit)
				return m_hand[it];
		}
		// Option 2
		/*for (const auto& it : m_hand)
		{
			if (it.GetSuit() == suit)
				return it;
		}*/
	}
	friend std::ostream operator<<(std::ostream& os, const Player& player) // Prints player's id and hand
	{
		
	}
	void SortCards() // Sorts cards in suits and from highest to lowest value
	// Suit Sort: HEART -> DIAMOND -> SPADE -> CLUB
	{
		
	}
};