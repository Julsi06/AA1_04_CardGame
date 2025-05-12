#pragma once
#include "Card.h"
#include <vector>
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
	bool GetOrderCards(const Card& card1, const Card& card2) // Returns the card either by suit priority or by value
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
		while (it != m_hand.end() && GetOrderCards(*it, card))
		{
			++it;
		}
		// Places said card at said position (in this case, at the end)
		m_hand.insert(it, card);
	}
	Card GetCard() const // Returns random card
	{
		if (!m_hand.empty())
		{
			// Generates a random position, and returns the cards in that position
			int randomCardIndex = rand() % m_hand.size();
			return m_hand[randomCardIndex];
		}
	}
	Card GetCard(const Suit& suit) // Returns the card with highest value of said suit
	{
		for (int i = 0;i < m_hand.size();i++)
		{
			if (m_hand[i].GetSuit() == suit)
				return m_hand[i];
		}
	}
	friend std::ostream operator<<(std::ostream& os, const Player& player) // Prints player's id and hand
	{
		
	}
	void SortCards() // Sorts cards in suits and from highest to lowest value
	// Suit Sort: HEART -> DIAMOND -> SPADE -> CLUB
	{
		// REMAINS
	}
};