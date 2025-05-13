#include "Game.h"
#include "Card.h"
#include "Suit.h"
#include "Player.h"

int main()
{
	srand(time(NULL));

	int randomPlayers = 2 + rand() % 7;

	Game game(4);

	std::cout << "Initial hands: " << randomPlayers << std::endl;
	
	Card card = game.GetNewCard();

	game.DiscardCard(card);
	game.PrintDiscarded();
}