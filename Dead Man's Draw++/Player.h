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
	void bankCards(Game& game);
	void discardPlayArea(Game& game);
	int calculateScore() const;
	void printPlayArea() const;
	void printBank() const;
	void printCollection(const CardCollection& cards) const;
	void addToBank(Card* card);

	std::string& getName();
	CardCollection& getPlayArea();
	CardCollection& getBank();
};
