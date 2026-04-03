#include "Game.h"

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
}

void Game::initialisePlayers()
{
}

void Game::createDeck()
{
}

void Game::shuffleDeck()
{
}

void Game::playTurn()
{
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
