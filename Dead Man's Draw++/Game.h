#pragma once
#include <vector>
#include "Card.h"
#include "Player.h"

class Game
{
protected:
	static const int MAX_TURNS = 20;

	std::vector<Player*> _players;
	CardCollection _deck;
	CardCollection _discardPile;
	int _currentPlayerIndex;
	int _roundNumber;
	int _turnNumber;
	bool _turnBusted;

public:
	Game();
	~Game();

	void startGame();
	void createDeck();
	void shuffleDeck();
	bool playTurn();
	Card* drawCard();
	void discardCard(Card* card);
	Card* peekCard() const;
	Card* drawFromDiscardPile();
	void advanceTurn();
	void printFinalScore() const;
	void setTurnBusted();
	bool isTurnBusted() const;

	Player* getCurrentPlayer();
	Player* getOtherPlayer();
	CardCollection& getDeck();
	CardCollection& getDiscardPile();
};
