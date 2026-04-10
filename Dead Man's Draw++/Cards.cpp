#include "Cards.h"
#include "Game.h"
#include "Player.h"
#include <iostream>
#include <map>

// Return list of highest-value cards per suit from given collection
CardCollection topCardsPerSuit(CardCollection& cards) {
	std::map<Card::CardType, Card*> best;
	for (Card* c : cards) {
		Card::CardType t = c->type();
		if (best.find(t) == best.end() || best[t]->getValue() < c->getValue()) {
			best[t] = c;
		}
	}

	CardCollection result;
	for (auto& pair : best) {
		result.push_back(pair.second);
	}

	return result;
}

// Display a numbered menu and return the chosen index
int pickCard(CardCollection& options) {
	for (int i = 0; i < options.size(); i++) {
		std::cout << "    (" << (i + 1) << ") " << options[i]->str() << std::endl;
	}

	std::cout << "Which card do you pick? ";
	int choice = 0;
	std::cin >> choice;
	while (choice < 1 || choice > options.size()) {
		std::cout << "ERROR: Choose a number between these options:" << std::endl;
		for (int i = 0; i < options.size(); i++) {
			std::cout << "    (" << (i + 1) << ") " << options[i]->str() << std::endl;
		}

		std::cout << "Which card do you pick? ";
		std::cin >> choice;
	}

	return choice - 1;
}

// Remove and return the highest-value card of a given suit from a CardCollection
Card* removeTopOfSuit(CardCollection& collection, Card::CardType suit) {
	Card* best = nullptr;
	int bestIdx = -1;

	for (int i = 0; i < collection.size(); i++) {
		if (collection[i]->type() == suit) {
			if (best == nullptr || collection[i]->getValue() > best->getValue()) {
				best = collection[i];
				bestIdx = i;
			}
		}
	}

	if (bestIdx >= 0) {
		collection.erase(collection.begin() + bestIdx);
	}

	return best;
}

// Play a secondary card into the play area
static bool playSecondaryCard(Card* card, Game& game, Player& player)
{
	std::cout << player.getName() << " draws a " << card->str() << std::endl;
	bool bust = player.playCard(card, game);
	if (bust)
	{
		std::cout << "BUST! " << player.getName() << " loses all cards in play area." << std::endl;
		player.discardPlayArea(game);
		game.setTurnBusted();
	}
	return bust;
}

// Discard the top card (highest value) of any suit from opponents bank
void CannonCard::play(Game& game, Player& player)
{
	Player* opponent = game.getOtherPlayer();
	CardCollection& opBank = opponent->getBank();
	CardCollection options = topCardsPerSuit(opBank);

	if (options.empty()) {
		std::cout << "    No cards in other player's Bank. Play continues." << std::endl;
		return;
	}

	std::cout << "    Discard the top card of any suit from the other player's Bank to the Discard Pile:" << std::endl;
	int choice = pickCard(options);

	Card* removed = removeTopOfSuit(opBank, options[choice]->type());
	if (removed) {
		std::cout << "    Discarded " << removed->str() << " from " << opponent->getName() << "'s Bank." << std::endl;
		game.discardCard(removed);
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

// Steal the top card of any suit from the opponent's Bank into
// the current players play area
void SwordCard::play(Game& game, Player& player)
{
	Player* opponent = game.getOtherPlayer();
	CardCollection& opBank = opponent->getBank();
	CardCollection options = topCardsPerSuit(opBank);

	if (options.empty()) {
		std::cout << "    No cards in other player's Bank. Play continues." << std::endl;
		return;
	}

	std::cout << "    Steal the top card of any suit from the other player's Bank into your Play Area:" << std::endl;
	int choice = pickCard(options);

	Card* stolen = removeTopOfSuit(opBank, options[choice]->type());
	if (stolen) {
		playSecondaryCard(stolen, game, player);
	}
}

// Pull the top card of any suit from own bank into play area
// Then play that card's ability
void HookCard::play(Game& game, Player& player)
{
	CardCollection& bank = player.getBank();
	CardCollection options = topCardsPerSuit(bank);

	if (options.empty())
	{
		std::cout << "    No cards in your Bank. Play continues." << std::endl;
		return;
	}

	std::cout << "    Select a highest-value card from any of the suits in your Bank:" << std::endl;
	int choice = pickCard(options);

	Card* pulled = removeTopOfSuit(bank, options[choice]->type());
	if (pulled) {
		playSecondaryCard(pulled, game, player);
	}	
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

// Draw 3 cards from the discard pile, player must play one.
// Then play that card's ability
void MapCard::play(Game& game, Player& player)
{
	// Check how many are available before drawing
	int available = game.getDiscardPile().size();
	if (available == 0) {
		std::cout << "    No cards in the discard. Play continues." << std::endl;
		return;
	}

	int toDraw = std::min(3, available);
	CardCollection candidates;
	for (int i = 0; i < toDraw; i++) {
		Card* c = game.drawFromDiscardPile();
		if (c) {
			candidates.push_back(c);
		}
	}
	
	std::cout << "    Draw 3 cards from the discard and pick one to add to the play area:" << std::endl;
	int choice = pickCard(candidates);
	Card* chosen = candidates[choice];

	// Return unchosen cards to discard (preserve order by reversing)
	for (int i = candidates.size() - 1; i >= 0; --i) {
		if (i != choice) {
			game.discardCard(candidates[i]);
		}
	}

	playSecondaryCard(chosen, game, player);
}

void MermaidCard::play(Game& game, Player& player)
{
	std::cout << "    No effect but Mermaids are worth more." << std::endl;
}

void KrakenCard::play(Game& game, Player& player)
{
}
