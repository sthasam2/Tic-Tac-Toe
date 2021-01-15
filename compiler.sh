# main.cpp
# Note: due to reference errors, all files were built and compiled
ALL="src/main.cpp src/DEFINITIONS.hpp src/Engine/AI/AI.hpp src/Engine/AssetManager/AssetManager.hpp src/Engine/Game/Game.hpp src/Engine/InputManager/InputManager.hpp src/Engine/States/GameOverState.hpp src/Engine/States/GameState.hpp src/Engine/States/MainMenuState.hpp src/Engine/States/PauseState.hpp src/Engine/States/SplashState.hpp src/Engine/StateMachine/State.hpp src/Engine/StateMachine/StateMachine.hpp src/Engine/AI/AI.cpp src/Engine/AssetManager/AssetManager.cpp src/Engine/Game/Game.cpp src/Engine/InputManager/InputManager.cpp src/Engine/States/GameOverState.cpp src/Engine/States/GameState.cpp src/Engine/States/MainMenuState.cpp src/Engine/States/PauseState.cpp src/Engine/States/SplashState.cpp src/Engine/StateMachine/StateMachine.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network"
printf "\nBuilding Project...\n"
g++ $ALL -o bin/main

alias run = ./bin/main
# printf "\nTYPE command 'run_program' to run the program.\n\n"
printf "\nIf no ERRORs detected, Project built succesfully!\n\nType command './bin/main' to run program\n"

