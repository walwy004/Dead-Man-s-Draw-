#pragma once
#include "Card.h"
#include <string>
#include <format>

class CannonCard : public Card
{
public:
	CannonCard(int value) : Card(value, CardType::Cannon) {}

	std::string str() const override {
		return std::format("Cannon({})", getValue());
	}
	void play(Game& game, Player& player) override;
};


class ChestCard : public Card
{
public:
	ChestCard(int value) : Card(value, CardType::Chest) {}

	std::string str() const override {
		return std::format("Chest({})", getValue());
	}
	void play(Game& game, Player& player) override;
	void willAddToBank(Game& game, Player& player) override;
};


class KeyCard : public Card
{
public:
	KeyCard(int value) : Card(value, CardType::Key) {}

	std::string str() const override {
		return std::format("Key({})", getValue());
	}
	void play(Game& game, Player& player) override;
};


class SwordCard : public Card
{
public:
	SwordCard(int value) : Card(value, CardType::Sword) {}

	std::string str() const override {
		return std::format("Sword({})", getValue());
	}
	void play(Game& game, Player& player) override;
};


class HookCard : public Card
{
public:
	HookCard(int value) : Card(value, CardType::Hook) {}

	std::string str() const override {
		return std::format("Hook({})", getValue());
	}
	void play(Game& game, Player& player) override;
};


class OracleCard : public Card
{
public:
	OracleCard(int value) : Card(value, CardType::Oracle) {}

	std::string str() const override {
		return std::format("Oracle({})", getValue());
	}
	void play(Game& game, Player& player) override;
};


class MapCard : public Card
{
public:
	MapCard(int value) : Card(value, CardType::Map) {}

	std::string str() const override {
		return std::format("Map({})", getValue());
	}
	void play(Game& game, Player& player) override;
};


class MermaidCard : public Card
{
public:
	MermaidCard(int value) : Card(value, CardType::Mermaid) {}

	std::string str() const override {
		return std::format("Mermaid({})", getValue());
	}
	void play(Game& game, Player& player) override;
};


class KrakenCard : public Card
{
public:
	KrakenCard(int value) : Card(value, CardType::Kraken) {}

	std::string str() const override {
		return std::format("Kraken({})", getValue());
	}
	void play(Game& game, Player& player) override;
};
