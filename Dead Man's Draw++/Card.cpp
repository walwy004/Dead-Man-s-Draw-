#include "Card.h"

Card::Card(int value, CardType type) :
	_value(value), _type(type)
{
}

Card::~Card()
{
}

int Card::getValue() const
{
	return _value;
}

Card::CardType Card::type() const
{
	return CardType();
}

