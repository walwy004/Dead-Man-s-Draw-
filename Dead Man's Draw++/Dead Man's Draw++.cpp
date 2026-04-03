#include <iostream>
#include "game_title.h"
#include "Cards.h"
#include "Game.h"
#include "Player.h"

int main()
{
    // Seed once at the start of the program using current time
    srand(static_cast<unsigned int>(time(nullptr)));

    // std::cout << GAME_TITLE << std::endl;

    Game game;
    game.startGame();

    return 0;
}
