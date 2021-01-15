#pragma once

#include <sstream>
#include "GameState.hpp"
#include "MainMenuState.hpp"
#include "PauseState.hpp"
#include "GameOverState.hpp"
#include "../../DEFINITIONS.hpp"

#include <iostream>

namespace Stha
{
	/**
	 *  GAMESTATE CONSTRUCTOR POINTS TO GAMEDATA OBJECT
	 */
	GameState::GameState(GameDataRef data) : _data(data)
	{
	}

	/** 
	 * Initialize Game State
	 */
	void GameState::Init()
	{
		// GAME STATES - PLAYING
		gameState = STATE_PLAYING;
		turn = PLAYER_PIECE;

		// INITIALIZE AI OBJECT
		this->ai = new AI(turn, this->_data);

		// LOADING TEXTURE
		this->_data->assets.LoadTexture("Pause Button", PAUSE_BUTTON);
		this->_data->assets.LoadTexture("Grid Sprite", GRID_SPRITE_FILEPATH);
		this->_data->assets.LoadTexture("X Piece", X_PIECE_FILEPATH);
		this->_data->assets.LoadTexture("O Piece", O_PIECE_FILEPATH);
		this->_data->assets.LoadTexture("X Winning Piece", X_WINNING_PIECE_FILEPATH);
		this->_data->assets.LoadTexture("O Winning Piece", O_WINNING_PIECE_FILEPATH);

		// SETTING TEXTURES
		_background.setTexture(this->_data->assets.GetTexture("Background"));
		_pauseButton.setTexture(this->_data->assets.GetTexture("Pause Button"));
		_gridSprite.setTexture(this->_data->assets.GetTexture("Grid Sprite"));

		// POSITIONING ASSETS
		// VALUES
		float pauseX = (this->_data->window.getSize().x - _pauseButton.getLocalBounds().width);
		float pauseY = _pauseButton.getPosition().y;
		float gridX = ((SCREEN_WIDTH / 2) - (_gridSprite.getGlobalBounds().width / 2));
		float gridY = ((SCREEN_HEIGHT / 2) - (_gridSprite.getGlobalBounds().height / 2));
		// SET POSITION
		_pauseButton.setPosition(pauseX, pauseY);
		_gridSprite.setPosition(gridX, gridY);

		//INITIALIZE GRID
		InitGridPieces();
		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				_gridArray[x][y] = EMPTY_PIECE; // make each box an empty piece
			}
		}
	}

	/**
	 *  Gamestate Input Handler
	 */
	void GameState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			// CHECK WINDOW CLOSE EVENT
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			// CHECK GAME PAUSE PRESS EVENT
			if (this->_data->input.IsSpriteClicked(this->_pauseButton, sf::Mouse::Left, this->_data->window))
			{
				// PAUSE
				this->_data->machine.AddState(StateRef(new PauseState(_data)), false); // false because we are only pausing so we need to return back on resume

				// this->_data->machine.AddState(StateRef(new GameOverState(_data)), false);
			}
			else if (this->_data->input.IsSpriteClicked(this->_gridSprite, sf::Mouse::Left, this->_data->window))
			{
				// GRID CLICK EVENT
				this->CheckAndPlacePiece();
			}
		}
	}

	/**
	 * Update variable
	 * 
	 * @param dt - updater delta
	 */
	void GameState::Update(float dt)
	{
	}

	/**
	 * Draw all assets and states on screen
	 * 
	 * @param : float dt
	*/
	void GameState::Draw(float dt)
	{
		// CLEAR SCREEN
		this->_data->window.clear(sf::Color::Magenta);
		// DRAW
		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_pauseButton);
		this->_data->window.draw(this->_gridSprite);

		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				this->_data->window.draw(this->_gridPieces[x][y]);
			}
		}

		// DISPLAY
		this->_data->window.display();
	}

	/**
	 * [PRIVATE] Initializing the Grid Sprite
	 */
	void GameState::InitGridPieces()
	{
		// Get the size of X O sprite
		sf::Vector2u tempSpriteSize = this->_data->assets.GetTexture("X Piece").getSize();

		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				// SET BOX TEXTURE
				_gridPieces[x][y].setTexture(this->_data->assets.GetTexture("X Piece"));
				// POSITION BOX PIECES
				//(starts from the left most x coor of grid, adds grids to each subsequent column using multiples of each X O sprite width, subtracts 7 to center the box.
				// Note: 7 is hardcoded from hit and trial because of the way its designed..) and similarly for Y coor
				_gridPieces[x][y].setPosition(_gridSprite.getPosition().x + (tempSpriteSize.x * x) - 7, _gridSprite.getPosition().y + (tempSpriteSize.y * y) - 7);
				// SET PIECE OPACITY
				// since boxes are made using reference to an actual game piece opacity is made 0
				_gridPieces[x][y].setColor(sf::Color(255, 255, 255, 0));
			}
		}
	}

	/**
	 * [PRIVATE] Place Pieces according to turn in both array and visual sprite representation of the Game board
	 */
	void GameState::CheckAndPlacePiece()
	{
		// GET MOUSE CLICK POSITION
		sf::Vector2i touchPoint = this->_data->input.GetMousePosition(this->_data->window);
		// ALLOCATING GRID SIZE
		sf::FloatRect gridSize = _gridSprite.getGlobalBounds();
		// GET THE GAP SIZE ON EITHER SIDE OF THE GAME GRID
		sf::Vector2f gapOutsideOfGrid = sf::Vector2f((SCREEN_WIDTH - gridSize.width) / 2, (SCREEN_HEIGHT - gridSize.height) / 2);
		// GET THE CLICK POSITION INSIDE THE GRID
		sf::Vector2f gridLocalTouchPos = sf::Vector2f((touchPoint.x - gapOutsideOfGrid.x), (touchPoint.y - gapOutsideOfGrid.y));
		// SMALL BOX SIZE - SECTIONING THE GRID TO 3X3 BOXES
		sf::Vector2f gridSectionSize = sf::Vector2f(gridSize.width / 3, gridSize.height / 3);

		int column, row;

		// CHECK WHICH COL AND ROW THE USER HAS CLICKED
		// COLUMN
		if (gridLocalTouchPos.x < gridSectionSize.x)
			column = 1;
		else if (gridLocalTouchPos.x < gridSectionSize.x * 2)
			column = 2;
		else if (gridLocalTouchPos.x < gridSize.width)
			column = 3;
		// ROW
		if (gridLocalTouchPos.y < gridSectionSize.y)
			row = 1;
		else if (gridLocalTouchPos.y < gridSectionSize.y * 2)
			row = 2;
		else if (gridLocalTouchPos.y < gridSize.height)
			row = 3;

		// GAME LOGIC - PLACING Xs & OS
		if (_gridArray[column - 1][row - 1] == EMPTY_PIECE)
		{
			// SET PIECE INTO ARRAY REPRESENTATION OF GRID BOARD
			_gridArray[column - 1][row - 1] = turn;

			// SET PIECE INTO VISUAL SPRITE REPRESENTATION OF GRID BOARD
			if (PLAYER_PIECE == turn)
			{
				_gridPieces[column - 1][row - 1].setTexture(this->_data->assets.GetTexture("X Piece")); // PLACE X
				this->CheckHasPlayerWon(turn);															// CHECK WIN. WHILE CHECKING WIN, IF PLAYER HAS NOT WON AI GETS A TURN

				// turn = AI_PIECE;			// SWITCHING TURNS. USE THIS FOR MANUAL MULTIPLAYER MODE
			}
			// USE THIS FOR MULTIPLAYER MODE
			// else if (AI_PIECE == turn)
			// {
			// 	_gridPieces[column - 1][row - 1].setTexture(this->_data->assets.GetTexture("O Piece")); // PLACE O
			// 	this->CheckHasPlayerWon(turn);															// CHECK WIN
			// 	turn = PLAYER_PIECE;																	// SWITCHING TURNS
			// }

			_gridPieces[column - 1][row - 1].setColor(sf::Color(255, 255, 255, 255)); // SET OPACITY 100% FOR THE PIECE
		}
	}

	/**
	 *  [PRIVATE] Check all combination for winning the game for a given player
	 * 
	 * @param player inherits from @func CheckAndPlacePiece local int 'turn'; turn corresponds to whichever player's piece ie X (PLAYER) or O (AI) 
	 */
	void GameState::CheckHasPlayerWon(int player)
	{
		// 00 10 20
		// 01 11 21
		// 02 12 22
		Check3PiecesForMatch(0, 0, 1, 0, 2, 0, player); // FIRST ROW
		Check3PiecesForMatch(0, 1, 1, 1, 2, 1, player); // SECOND ROW
		Check3PiecesForMatch(0, 2, 1, 2, 2, 2, player); // THIRD ROW
		Check3PiecesForMatch(0, 0, 0, 1, 0, 2, player); // FIRST COLUMN
		Check3PiecesForMatch(1, 0, 1, 1, 1, 2, player); // SECOND COLUMN
		Check3PiecesForMatch(2, 0, 2, 1, 2, 2, player); // THIRD COLUMN
		Check3PiecesForMatch(0, 0, 1, 1, 2, 2, player); // LEADING DIAGNAL
		Check3PiecesForMatch(0, 2, 1, 1, 2, 0, player); // NON-LEADING DIAGNAL

		if (STATE_WON != gameState)
		{
			// CHANGE THE STATE TO AI PLAYING
			gameState = STATE_AI_PLAYING;

			// AI PLACE PIECE
			ai->PlacePiece(&_gridArray, _gridPieces, &gameState);

			// AFTER PLACING PIECE CHECK WIN CONDITION
			Check3PiecesForMatch(0, 0, 1, 0, 2, 0, AI_PIECE);
			Check3PiecesForMatch(0, 1, 1, 1, 2, 1, AI_PIECE);
			Check3PiecesForMatch(0, 2, 1, 2, 2, 2, AI_PIECE);
			Check3PiecesForMatch(0, 0, 0, 1, 0, 2, AI_PIECE);
			Check3PiecesForMatch(1, 0, 1, 1, 1, 2, AI_PIECE);
			Check3PiecesForMatch(2, 0, 2, 1, 2, 2, AI_PIECE);
			Check3PiecesForMatch(0, 0, 1, 1, 2, 2, AI_PIECE);
			Check3PiecesForMatch(0, 2, 1, 1, 2, 0, AI_PIECE);
		}

		int emptyNum = 9; // NUMBER OF EmPTY BOXES

		// CHECKING EMPTY PIECES
		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				if (EMPTY_PIECE != _gridArray[x][y])
					emptyNum--;
			}
		}

		// CHECK GAME DRAW
		if (emptyNum == 0 && (STATE_WON != gameState) && (STATE_LOSE != gameState))
		{
			gameState = STATE_DRAW;
		}

		// CHECK GAME OVER
		if (STATE_DRAW == gameState || STATE_WON == gameState || STATE_LOSE == gameState)
		{
			// NOTE: gameState = GAME OVER
		}
	}

	/**
	 * [PRIVATE] 
	 * Commpare winning and game board combinations. 
	 * Change textures of winning combinations.
	 * And thus creates corresponding states 
	 * 
	 * @param x1 first piece x
	 * @param y1 first piece y
	 * @param x2 second piece x
	 * @param y2 second piece y
	 * @param x3 third piece x
	 * @param y3 third piece y
	 * @param pieceToCheck the actual piece to check ie X or O. Inherits from @func CheckPlayerHasWon int parameter player
	 */
	void GameState::Check3PiecesForMatch(int x1, int y1, int x2, int y2, int x3, int y3, int pieceToCheck)
	{
		// CHECKS COMBINATION FOR WINNING
		if (pieceToCheck == _gridArray[x1][y1] && pieceToCheck == _gridArray[x2][y2] && pieceToCheck == _gridArray[x3][y3])
		{
			std::string winningPieceStr;

			if (O_PIECE == pieceToCheck)
				winningPieceStr = "O Winning Piece";
			else
				winningPieceStr = "X Winning Piece";

			// SET WINNING PIECE TEXTURES
			_gridPieces[x1][y1].setTexture(this->_data->assets.GetTexture(winningPieceStr));
			_gridPieces[x2][y2].setTexture(this->_data->assets.GetTexture(winningPieceStr));
			_gridPieces[x3][y3].setTexture(this->_data->assets.GetTexture(winningPieceStr));

			// SET GAME OUTCOME STATES
			if (PLAYER_PIECE == pieceToCheck)
			{
				gameState = STATE_WON;
			}
			else
			{
				gameState = STATE_LOSE;
			}
		}
	}

} // namespace Stha