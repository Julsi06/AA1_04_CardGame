#pragma once
#include "Card.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

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
	bool CompareCards(const Card& card1, const Card& card2) const // Returns the card either by suit priority or by highest value
	{
		if (GetSuitRank(card1.GetSuit()) != GetSuitRank(card2.GetSuit()))
			return GetSuitRank(card1.GetSuit()) > GetSuitRank(card2.GetSuit());
		return card1.GetValue() > card2.GetValue();
	}
public:
	Player(const std::string& id = "Player") : m_id(id) {} // Constructor: initializes the player's id
	
	void InsertCard(const Card& card) // Inserts card in player's hand
	{
		// it is incremented until the position is end()
		auto it = m_hand.begin();
		while (it != m_hand.end() && CompareCards(*it, card))
		{
			++it;
		}
		// Places said card at said position (in this case, at the end)
		m_hand.insert(it, card);
	}
	Card GetRandomCard() const // Returns random card
	{
		if (m_hand.empty()) throw std::runtime_error("Hand is empty");
		int index = rand() % m_hand.size();
		return m_hand[index];
	}
	Card GetCardBySuit(Suit suit) // Returns the card with highest value of said suit
	{
		// Goes through each element of the vector
		for (const auto& card : m_hand)
			if (card.GetSuit() == suit)
				return card;
		throw std::runtime_error("No card with that suit");
	}
	void SortCards()
	{
		std::sort(m_hand.begin(), m_hand.end(),
			[&](const Card& a, const Card& b) { return CompareCards(a, b); });
	}

	friend std::ostream& operator<<(std::ostream& os, const Player& player)
	{
		os << player.m_id << "'s hand:\n";
		for (const auto& card : player.m_hand)
			os << "  " << card << '\n';
		return os;
	}
};