#include <iostream>
#include "game_title.h"
#include "Cards.h"
#include "Game.h"
#include "Player.h"

int main()
{
    // std::cout << GAME_TITLE << std::endl;

    Game game;
    Player player = Player("Test");

    CannonCard cannon = CannonCard(5);
    std::cout << cannon.str() << std::endl;
    cannon.play(game, player);

    return 0;
}
