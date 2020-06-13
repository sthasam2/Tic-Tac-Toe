// #include <iostream>

// #include "Engine/Assets/AssetManager.hpp"
// #include "Engine/Input/InputManager.hpp"
// #include "Engine/State Machine/State.hpp"
// #include "Engine/State Machine/StateMachine.hpp"
// #include "Engine/Game/Game.cpp"
// #include "State/SplashState.hpp"

#include "Engine/Game/Game.hpp"
#include "DEFINITIONS.hpp"

using namespace Stha;

int main()
{
    Stha::Game(SCREEN_WIDTH, SCREEN_HEIGHT, APP_NAME);

    return EXIT_SUCCESS;
}