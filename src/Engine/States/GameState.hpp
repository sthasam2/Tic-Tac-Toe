#pragma once

#include <SFML/Graphics.hpp>
#include "../StateMachine/State.hpp"
#include "../Game/Game.hpp"
#include "../AI/AI.hpp"

namespace Stha
{
	class GameState : public State
	{
	public:
		GameState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		// INITIALIZER GRID
		void InitGridPieces();

		void CheckAndPlacePiece();
		void CheckHasPlayerWon(int player);
		void Check3PiecesForMatch(int x1, int y1, int x2, int y2, int x3, int y3, int pieceToCheck);

		GameDataRef _data; // game reference data

		sf::Sprite _background;		  // background
		sf::Sprite _pauseButton;	  // pause button
		sf::Sprite _gridSprite;		  // TictacToe Box
		sf::Sprite _gridPieces[3][3]; // Each TictacToe  sub grid box

		int _gridArray[3][3]; // position matrix for each box

		int turn;	   // turn tracker
		int gameState; // state of the game ie pause/ play/ player turn/ AI turn etc

		AI *ai;
	};
} // namespace Stha