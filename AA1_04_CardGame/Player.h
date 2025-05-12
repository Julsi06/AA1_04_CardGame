#pragma once
#include "Card.h"
#include <vector>
class Player
{
	std::string m_id;
	std::vector<Card> m_hand; // Vector that contains the hand of cards each player has

	void InsertCard(Card card); // Inserts card in player's hand
	Card GetCard() const; // Returns random card
	Card GetCard(const Suit& suit); // Returns the card with highest value of said suit
	std::ostream operator<<(std::ostream& os); // Prints player's id and hand
	void SortCards(); // Sorts cards in suits and from highest to lowest value
					  // Suit Sort: HEART -> DIAMOND -> SPADE -> CLUB
};