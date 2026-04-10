#pragma once
#include "Card.h"
#include "Game.h"

class Player
{
protected:
	std::string _name;
	CardCollection _playArea;
	CardCollection _bank;

public:
	Player();
	~Player() = default;

	bool playCard(Card* card, Game& game);
	bool isBust();
	void bankCards(Game& game);
	void discardPlayArea(Game& game);
	int calculateScore();
	void printPlayArea();
	void printBank();
	void printCollection(CardCollection& cards);
	void addToBank(Card* card);

	std::string& getName();
	CardCollection& getPlayArea();
	CardCollection& getBank();
};
