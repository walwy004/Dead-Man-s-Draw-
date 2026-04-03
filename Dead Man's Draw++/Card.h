#pragma once
#include <string>
#include <vector>

class Game;
class Player;

class Card
{
public:
	enum CardType {
		Cannon, Chest, Key, Anchor, Sword, Hook, Oracle, Map, Mermaid, Kraken
	};

protected:
	int _value;
	CardType _type;

public:
	Card(int value, CardType type);
	virtual ~Card() = default;
	
	virtual std::string str() const = 0;
	virtual void play(Game& game, Player& player) = 0;
	virtual void willAddToBank(Game& game, Player& player) {};

	const CardType& type() const;
	int getValue() const;
};

typedef std::vector<Card*> CardCollection;
