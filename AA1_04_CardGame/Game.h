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
	int m_numPlayers; // From 2 to 8
	std::vector<Player> m_players; // Vector that stores information about players
	mutable std::queue<Card> m_deck; // Queue that stores information about playable cards
	std::stack<Card> m_discarded; // Stack that stores information about played cards
	static Suit GetRandomSuit()
	{
		return static_cast<Suit>(rand() % 4);
	}
	static int GetRandomValue()
	{
		return 1 + rand() % 13;
	}
public:
	Game(int numPlayers) // Assigns random names to each player, initializes the deck, and gives 10 cards away to the players, 1 by 1
	{
		if (numPlayers < 2 || numPlayers > 8)
			return;
		m_numPlayers = numPlayers;

		Suit newSuit = GetRandomSuit();
		int newValue = GetRandomValue();

		for (int i = 0;i < 6;++i)
		{
			// Adds card into the deck
			m_deck.push(Card(newSuit, newValue));
		}

		for (int numberCards = 0;numberCards < 10;++numberCards)
		{
			// Assigns 1 card to each player 10 times = 10 cards assigned 1 by 1
			for (int j = 0;j < m_players.size(); ++j)
			{
				m_players[j].InsertCard(GetNewCard());
			}
		}
		
	}
	Card GetNewCard() const // Returns the deck's first card, deleting it from the deck
	{
		if (m_deck.empty()) throw std::runtime_error("Deck is empty");
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
		if (m_discarded.empty()) std::cout << "No discarded cards" << std::endl;
		std::cout << "Last card discarded:" << std::endl;
		// Gets the information of the last discarded card
		Card lastDiscardedCard = m_discarded.top();
		int cardValue = lastDiscardedCard.GetValue();
		std::cout << "Value: " << cardValue << ", Suit: ";
		Suit cardSuit = lastDiscardedCard.GetSuit();
		switch (cardSuit)
		{
		case Suit::HEART: std::cout << "HEART";
		case Suit::DIAMOND: std::cout << "DIAMOND";
		case Suit::SPADE: std::cout << "SPADE";
		case Suit::CLUB: std::cout << "CLUB";
		default: std::cout << "UNKNOWN";
		}
	}
};
