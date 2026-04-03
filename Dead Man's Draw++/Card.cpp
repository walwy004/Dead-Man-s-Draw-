#include "Card.h"
#include <vector>

Card::Card(int value, CardType type) :
	_value(value), _type(type)
{
}

const Card::CardType& Card::type() const
{
	return _type;
}

int Card::getValue() const
{
	return _value;
}