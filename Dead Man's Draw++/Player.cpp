#include "Player.h"

Player::Player(std::string& name)
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
	// TODO: insert return statement here
}

CardCollection& Player::getPlayArea()
{
	// TODO: insert return statement here
}

CardCollection& Player::getBank()
{
	// TODO: insert return statement here
}
