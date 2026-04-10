#include "Game.h"
#include "Cards.h"
#include <iostream>
#include <algorithm>
#include <random>

Game::Game() :
	_players{ nullptr, nullptr },
	_currentPlayerIndex(0),
	_roundNumber(1),
	_turnNumber(1),
	_turnBusted(false)
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

// Runs one full player turn. Returns false when turn ends - bust
bool Game::playTurn()
{
	Player* player = getCurrentPlayer();
	_turnBusted = false;

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
			advanceTurn();
			return false;
		}

		// _turnBusted is set by card abilities (Kraken/Sword/Hook/Map) when
		// a secondary card busts, the play area is already cleared.
		if (_turnBusted) {
			advanceTurn();
			return false;
		}

		// Show play area and ask whether to draw again
		player->printPlayArea();

		// Ask to draw again
		std::string input;
		std::cout << "\nDraw again? (y/n): ";
		std::cin >> input;

		// If player wishes to bank
		if (input != "y") {
			player->bankCards(*this);
			advanceTurn();
			return false;
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

// Look at top card from the deck
Card* Game::peekCard()
{
	if (_deck.empty()) {
		return nullptr;
	}

	return _deck.back();
}

// Increase turn and round counters and switches current player
void Game::advanceTurn()
{
	_turnNumber++;
	// Round increments after every 2 turns (one per player)
	if (_turnNumber % 2 == 1) {
		_roundNumber++;
	}

	_currentPlayerIndex = 1 - _currentPlayerIndex;
}

void Game::printFinalScore()
{
	std::cout << "--- Game Over ---\n";

	_players[0]->printBank();
	_players[1]->printBank();

	int s0 = _players[0]->calculateScore();
	int s1 = _players[1]->calculateScore();

	if (s0 > s1)
		std::cout << _players[0]->getName() << " wins!\n";
	else if (s1 > s0)
		std::cout << _players[1]->getName() << " wins!\n";
	else
		std::cout << "It's a tie!\n";
}

// Card abilities call this when a secondary card causes a bust mid-ability
void Game::setTurnBusted()
{
	_turnBusted = true;
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
