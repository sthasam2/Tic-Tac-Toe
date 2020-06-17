# main.cpp
# Note: due to reference errors, all files were built and compiled
ALL="src/main.cpp src/DEFINITIONS.hpp src/Engine/AssetManager/AssetManager.hpp src/Engine/Game/Game.hpp src/Engine/InputManager/InputManager.hpp src/Engine/States/MainMenuState.hpp src/Engine/States/SplashState.hpp src/Engine/StateMachine/State.hpp src/Engine/StateMachine/StateMachine.hpp src/Engine/AssetManager/AssetManager.cpp src/Engine/Game/Game.cpp src/Engine/InputManager/InputManager.cpp src/Engine/States/MainMenuState.cpp src/Engine/States/SplashState.cpp src/Engine/StateMachine/StateMachine.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network"
printf "\nBuilding Project...\n"
g++ $ALL -o bin/main
printf "\nProject Built.\n"

# alias run_program=./bin/main.out
# printf "\nTYPE command 'run_program' to run the program.\n\n"
printf "\n[If no ERRORs detected]\nType command './bin/main' to run program\n"
