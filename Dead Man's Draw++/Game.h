#pragma once
#include <vector>
#include "Card.h"

class Player;

class Game
{
protected:
	std::vector<Player> players;
	std::vector<Card> deck;
	std::vector<Card> discardPile;
	int _currentPlayerIndex;
	int _roundNumber;
	int _turnNumber;

public:
	Game();
	~Game();

	void startGame();
	void initialisePlayers();
	void createDeck();
	void shuffleDeck();
	void playTurn();
	Card* drawCard();
	void switchPlayer();
	void endGame();
	void printFinalScore();

	Player& getCurrentPlayer();
	Player& getOtherPlayer();
	CardCollection& getDeck();
	CardCollection& getDiscardPile();
};

