#include "Player.h"
#include <iostream>

std::string names[] = { "Sam", "Billy", "Jen", "Bob", "Sally", "Joe", "Sue",
"Sasha", "Tina", "Marge" };

Player::Player() :
	_name(names[rand() % 10])
{
}

Player::~Player()
{
}

// Returns true if the card causes a bust
bool Player::playCard(Card* card, Game& game)
{
	// Check for duplicate suit in play area
	for (Card* c : _playArea) {
		if (c->type() == card->type()) {
			_playArea.push_back(card);
			return true;
		}
	}

	// No bust - add to play area then execute ability
	_playArea.push_back(card);
	card->play(game, *this);
	return false;
}

bool Player::isBust()
{
	return false;
}

void Player::bankCard(Game& game)
{
}

// Discards all cards in the play area
void Player::discardPlayArea(Game& game)
{
	for (Card* c : _playArea) {
		game.discardCard(c);
	}
}

int Player::calculateScore()
{
	return 0;
}

void Player::printPlayArea()
{
	std::cout << _name << "'s Play Area:" << std::endl;
	for (Card* c : _playArea) {
		std::cout << "    " << c->str() << std::endl;
	}
}

void Player::printBank()
{
}

std::string& Player::getName()
{
	return _name;
}

CardCollection& Player::getPlayArea()
{
	return _playArea;
}

CardCollection& Player::getBank()
{
	return _bank;
}
