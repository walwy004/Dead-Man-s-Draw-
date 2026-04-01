#pragma once
#include <string>
#include <vector>

typedef std::vector<Card*> CardCollection;

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
	virtual ~Card();
	
	int getValue() const;
	const CardType& type() const;

	virtual std::string str() const = 0;
};

