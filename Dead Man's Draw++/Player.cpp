#include "Player.h"

Player::Player(std::string name) :
	_name(name)
{
}

Player::~Player()
{
}

bool Player::playCard(Card* card, Game& game)
{
	return false;
}

void Player::addToPlayArea(Card* card)
{
}

bool Player::isBust()
{
	return false;
}

void Player::bankCard(Game& game)
{
}

void Player::discardPlayArea(CardCollection& discardPile)
{
}

int Player::calculateScore()
{
	return 0;
}

void Player::printPlayArea()
{
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
