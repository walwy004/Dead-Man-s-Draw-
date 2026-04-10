#include "Player.h"
#include <iostream>
#include <map>

std::string names[] = { "Sam", "Billy", "Jen", "Bob", "Sally", "Joe", "Sue",
"Sasha", "Tina", "Marge" };

Player::Player() :
	_name(names[rand() % 10])
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

// Moves cards from a players play area to the bank
void Player::bankCards(Game& game)
{
	int count = _playArea.size();

	// Call willAddToBank on each original play area card
	for (int i = 0; i < count; ++i)
	{
		_playArea[i]->willAddToBank(game, *this);
	}

	// Move all play area cards (including any bonus cards appended above) to bank
	for (Card* c : _playArea) {
		_bank.push_back(c);
	}
	_playArea.clear();

	printBank();
}

// Discards all cards in the play area
void Player::discardPlayArea(Game& game)
{
	for (Card* c : _playArea) {
		game.discardCard(c);
	}
	_playArea.clear();
}

int Player::calculateScore()
{
	std::map<Card::CardType, int> scoredCards;
	for (Card* c : _bank) {
		Card::CardType t = c->type();
		if (scoredCards.find(t) == scoredCards.end() || scoredCards[t] < c->getValue()) {
			scoredCards[t] = c->getValue();
		}
	}

	int total = 0;
	for (auto& pair : scoredCards) {
		total += pair.second;
	}

	return total;
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
	std::cout << _name << "'s Bank:\n";
	for (Card* c : _bank) {
		std::cout << "    " << c->str() << std::endl;
	}
	std::cout << "| Score: " << calculateScore() << std::endl;
}

void Player::addToBank(Card* card)
{
	_bank.push_back(card);
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
