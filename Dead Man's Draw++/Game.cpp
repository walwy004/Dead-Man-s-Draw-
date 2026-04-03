#include "Game.h"
#include "Cards.h"
#include <iostream>

Game::Game() :
	_players{ nullptr, nullptr },
	_currentPlayerIndex(0),
	_roundNumber(1),
	_turnNumber(1)
{
}

Game::~Game()
{
}

void Game::startGame()
{
	std::cout << "Starting Dead Man's Draw++" << std::endl;

	createDeck();
	shuffleDeck();

	_players[0] = new Player();
	_players[1] = new Player();

	bool gameOver = false;
	while (!gameOver) {
		gameOver = playTurn();
	}

	printFinalScore();
}

// Create a deck of 54 cards: 9 suits x 6 values each
void Game::createDeck()
{
	int cardValues[] = { 2, 3, 4, 5, 6, 7 };
	int mermaidCardValues[] = { 4, 5, 6, 7, 8, 9 };

	for (int value : cardValues) {
		_deck.push_back(new CannonCard(value));
		_deck.push_back(new ChestCard(value));
		_deck.push_back(new KeyCard(value));
		_deck.push_back(new SwordCard(value));
		_deck.push_back(new HookCard(value));
		_deck.push_back(new OracleCard(value));
		_deck.push_back(new MapCard(value));
		_deck.push_back(new KrakenCard(value));
	}

	for (int value : mermaidCardValues) {
		_deck.push_back(new MermaidCard(value));
	}
}

void Game::shuffleDeck()
{
}

bool Game::playTurn()
{
	return true;
}

Card* Game::drawCard()
{
	return nullptr;
}

void Game::switchPlayer()
{
}

void Game::endGame()
{
}

void Game::printFinalScore()
{
}

Player* Game::getCurrentPlayer()
{
	return _players[_currentPlayerIndex];
}

Player* Game::getOtherPlayer()
{
	return _players[1 - _currentPlayerIndex];
}

CardCollection& Game::getDeck()
{
	return _deck;
}

CardCollection& Game::getDiscardPile()
{
	return _discardPile;
}
