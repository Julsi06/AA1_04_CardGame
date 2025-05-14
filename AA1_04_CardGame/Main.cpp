#include "Game.h"
#include "Card.h"
#include "Suit.h"
#include "Player.h"

int main()
{
	srand(time(NULL));
	bool gameloop = true;
	int numPlayers;
	std::cout << "Enter the number of players: ";
	std::cin >> numPlayers;
	std::cout << std::endl;

	while (gameloop)
	{
		Game game();
	}
	

	// std::cout << "Initial hand: " << randomPlayers << std::endl;
	
	// Card card = game.GetNewCard();

	//game.DiscardCard(card);
	//game.PrintDiscarded();
}