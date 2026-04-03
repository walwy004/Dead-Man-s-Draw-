#include "Game.h"
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

void Game::createDeck()
{
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
