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
    Player player1;
    Player player2;

    //CannonCard cannon = CannonCard(5);
    //std::cout << cannon.str() << std::endl;
    //cannon.play(game, player);

    game.startGame();
    std::cout << player1.getName() << std::endl;
    std::cout << player2.getName() << std::endl;

    return 0;
}
