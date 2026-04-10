#pragma once
#include <vector>
#include "Card.h"
#include "Player.h"

class Game
{
protected:
	std::vector<Player*> _players;
	CardCollection _deck;
	CardCollection _discardPile;
	int _currentPlayerIndex;
	int _roundNumber;
	int _turnNumber;

public:
	Game();
	~Game();

	void startGame();
	void createDeck();
	void shuffleDeck();
	bool playTurn();
	Card* drawCard();
	void discardCard(Card* card);
	Card* peekCard();
	void advanceTurn();
	void printFinalScore();

	Player* getCurrentPlayer();
	Player* getOtherPlayer();
	CardCollection& getDeck();
	CardCollection& getDiscardPile();
};
