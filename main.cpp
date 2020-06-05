#include <iostream>

#include "Engine/Game/Game.hpp"
#include "DEFINITIONS.hpp"

int main()
{
    Stha::Game(SCREEN_WIDTH, SCREEN_HEIGHT, "TicTacToe");

    return EXIT_SUCCESS;
}