#pragma once
#include <string>

class Card
{
public:
	enum CardType {
		Cannon, Chest, Key, Anchor, Sword, Hook, Oracle, Map, Mermaid, Kraken
	};

private:
	int _value;
	CardType _type;

public:
	Card(int value, CardType type);
	virtual ~Card();
	
	int getValue() const;
	CardType type() const;

	virtual std::string str() const = 0;
};

