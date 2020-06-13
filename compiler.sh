# hello.cpp

# g++ -c hello.cpp
# g++ hello.o -o bin/hello -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
# ./bin/hello

# main.cpp
# Note: due to reference errors, all files were built and compiled
ALL="main.cpp Engine/Game/Game.hpp Engine/Assets/AssetManager.hpp Engine/Input/InputManager.hpp Engine/StateMachine/State.hpp Engine/StateMachine/StateMachine.hpp States/SplashState.hpp Engine/Game/Game.cpp Engine/Assets/AssetManager.cpp Engine/Input/InputManager.cpp Engine/StateMachine/StateMachine.cpp States/SplashState.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network"
g++ $ALL -o bin/main.out

alias run_program="./bin/main.out"
printf "\nTYPE command 'run_program' to run the program.\n\n"
