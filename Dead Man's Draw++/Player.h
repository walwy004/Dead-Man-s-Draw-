#pragma once
#include <string>
#include <vector>
#include "Card.h"
#include "Game.h"

class Player
{
protected:
	std::string _name;
	CardCollection _playArea;
	CardCollection _bank;

public:
	Player(std::string& name);
	~Player();

	bool playCard(Card* card, Game& game);
	void addToPlayArea(Card* card);
	bool isBust();
	void bankCard(Game& game);
	void discardPlayArea(CardCollection& discardPile);
	int calculateScore();
	void printPlayArea();
	void printBank();

	std::string& getName();
	CardCollection& getPlayArea();
	CardCollection& getBank();
};

