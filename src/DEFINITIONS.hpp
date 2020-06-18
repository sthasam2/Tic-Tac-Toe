// Note: File paths are relative to g++ execution directory ie if yot compile from TicTacToe folder, the filepath must be relative to TicTacToe
#pragma once

// GAME WINDOW
#define APP_NAME "Tic-Tac-Toe"
#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 680
#define FPS 1.0f / 10.0f

// SPLASH STATE
#define SPLASH_SCREEN_TIMEOUT 3
#define SPLASH_SCREEN_BACKGROUND_FILEPATH "assets/res/Splash Background.png"

// MAIN MENU STATE
#define MAIN_MENU_BACKGROUND_FILEPATH "assets/res/Main Menu Background.png"
#define MAIN_MENU_TITLE_FILEPATH "assets/res/Game Title.png"
#define MAIN_MENU_PLAY_BUTTON "assets/res/Play Button.png"
#define MAIN_MENU_PLAY_BUTTON_OUTER "assets/res/Play Button Outer.png"

// GAME STATE
#define GAME_BACKGROUND_FILEPATH "assets/res/Main Menu Background.png"
#define PAUSE_BUTTON "assets/res/Pause Button.png"

// PAUSE STATE
#define PAUSE_BACKGROUND_FILEPATH "assets/res/Main Menu Background.png"
#define RESUME_BUTTON "assets/res/Resume Button.png"
#define HOME_BUTTON "assets/res/Home Button.png"

// GAMEOVER STATE
#define RETRY_BUTTON "assets/res/Retry Button.png"

// GAME LOGIC
#define X_PIECE_FILEPATH "assets/res/X.png"
#define O_PIECE_FILEPATH "assets/res/O.png"
#define X_WINNING_PIECE_FILEPATH "assets/res/X Win.png"
#define O_WINNING_PIECE_FILEPATH "assets/res/O Win.png"

#define X_PIECE 8
#define O_PIECE 0
#define EMPTY_PIECE -1
#define PLAYER_PIECE X_PIECE
#define AI_PIECE O_PIECE

#define STATE_PLAYING 98
#define STATE_PAUSED 97
#define STATE_WON 96
#define STATE_LOSE 95
#define STATE_PLACING_PIECE 94
#define STATE_AI_PLAYING 93
#define STATE_DRAW 92