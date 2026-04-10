#include "Cards.h"
#include "Game.h"
#include "Player.h"
#include <iostream>

// Discard the top card (highest value) of any suit from opponents bank
void CannonCard::play(Game& game, Player& player)
{
	Player* opponent = game.getOtherPlayer();
	CardCollection& opBank = opponent->getBank();

	if (opBank.empty()) {
		std::cout << "    No cards in other player's Bank. Play continues." << std::endl;
		return;
	}
}

void ChestCard::play(Game& game, Player& player)
{
}

void ChestCard::willAddToBank(Game& game, Player& player)
{
}

void KeyCard::play(Game& game, Player& player)
{
}

void KeyCard::willAddToBank(Game& game, Player& player)
{
}

void SwordCard::play(Game& game, Player& player)
{
}

void HookCard::play(Game& game, Player& player)
{
}

void OracleCard::play(Game& game, Player& player)
{
	Card* topCard = game.peekCard();
	if (topCard) {
		std::cout << "    The Oracle sees a " << topCard->str() << std::endl;
	}
	else {
		std::cout << "    The Oracle sees nothing (deck is empty)." << std::endl;
	}
}

void MapCard::play(Game& game, Player& player)
{
}

void MermaidCard::play(Game& game, Player& player)
{
	std::cout << "    No effect but Mermaids are worth more." << std::endl;
}

void KrakenCard::play(Game& game, Player& player)
{
}
