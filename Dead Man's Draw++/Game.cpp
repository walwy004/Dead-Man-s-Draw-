#include "Game.h"
#include "Cards.h"
#include <iostream>
#include <algorithm>
#include <random>

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

// Shuffles the created deck of 54 cards
void Game::shuffleDeck()
{
	CardCollection shuffleDeck{ _deck.begin(), _deck.end() };
	std::shuffle(shuffleDeck.begin(), shuffleDeck.end(), std::mt19937{ std::random_device{}() });
	std::copy(shuffleDeck.begin(), shuffleDeck.end(), _deck.begin());
}

// Runs one full player turn. Returns true when turn ends - bust
bool Game::playTurn()
{
	Player* player = getCurrentPlayer();

	std::cout << "--- Round " << _roundNumber << ", Turn " << _turnNumber << " ---" << std::endl;
	std::cout << player->getName() << "'s turn." << std::endl;
	player->printBank();

	while (true) 
	{
		// End game if deck is empty
		if (_deck.empty()) {
			std::cout << "The deck is empty. Game over!" << std::endl;
			return true;
		}

		// Draw the top card
		Card* drawn = drawCard();
		std::cout << player->getName() << " draws a " << drawn->str() << std::endl;

		bool drawnCardBust = player->playCard(drawn, *this);

		if (drawnCardBust) {
			std::cout << "BUST! " << player->getName() << " loses all cards in play area." << std::endl;
			player->discardPlayArea(*this);
			return true;
		}
	}

	return true;
}

// Draws top card from the deck
Card* Game::drawCard()
{
	if (_deck.empty()) {
		return nullptr;
	}

	Card* topCard = _deck.back();
	_deck.pop_back();
	return topCard;
}

// Add card to top of discard pile
void Game::discardCard(Card* card)
{
	if (card) {
		_discardPile.push_back(card);
	}
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
