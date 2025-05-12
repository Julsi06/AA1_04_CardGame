#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include "Player.h"
#include "Card.h"
class Game
{
private:
	int m_numPlayers = 2 + rand() % 7;
	std::vector<Player> m_players; // Vector that stores information about players
	static std::queue<Card> m_deck; // Queue that stores information about playable cards
	std::stack<Card> m_discarded; // Stack that stores information about played cards
public:
	Game() // Assigns random names to each player, initializes the deck, and gives 10 cards away to the players, 1 by 1
	{
		// Initializing the deck
		for (int suit = 0;suit < 4;suit++)
		{
			for (int value = 1;value <= 13;value++)
			{
				m_deck.push(Card(static_cast<Suit>(suit), value));
			}
		}

		// REMAINS
	}
	Card GetNewCard() const // Returns the deck's first card, deleting it from the deck
	{
		Card cardToDelete = m_deck.front();
		m_deck.pop();
		return cardToDelete;
	}
	void DiscardCard(const Card& card) // Discarded cards go to discarded card pile
	{
		m_discarded.push(card);
	}
	void PrintDiscarded() const // Prints the last discarded card
	{
		// Gets the information of the last discarded card
		Card lastDiscardedCard = m_discarded.top();
		int cardValue = lastDiscardedCard.GetValue();
		std::string cardSuit;
		switch (lastDiscardedCard.GetSuit())
		{
		case Suit::HEART: cardSuit = "HEART";
		case Suit::DIAMOND: cardSuit = "DIAMOND";
		case Suit::SPADE: cardSuit = "SPADE";
		case Suit::CLUB: cardSuit = "CLUB";
		default: cardSuit = "UNKNOWN";
		}

		std::cout << "Last card discarded: Suit: " << cardSuit << ", Value: " << cardValue << std::endl;
	}
};
