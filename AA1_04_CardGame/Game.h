#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include "Player.h"
#include "Card.h"
class Game
{
	std::vector<Player> players; // Vector that stores information about players
	std::queue<Card> deck; // Queue that stores information about playable cards
	std::stack<Card> pile; // Stack that stores information about played cards

	Game(int numPlayers); // Assigns random names to each player
	Card GetNewCard() const; // Returns the deck's first card, deleting it from the deck
	void DiscardCard(const Card& card); // Discarded cards go to discarded card pile
	void PrintDiscarded() const; // Prints the last discarded card
};
