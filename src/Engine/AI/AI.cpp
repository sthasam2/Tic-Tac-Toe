#include "AI.hpp"
#include "../../DEFINITIONS.hpp"

#include <iostream>

using namespace std;

namespace Stha
{
	AI::AI(int playerPiece, GameDataRef data)
	{
		this->_data = data;
		this->playerPiece = playerPiece;

		// DETERMINE AI PIECE
		if (O_PIECE == playerPiece)
			aiPiece = X_PIECE;
		else
			aiPiece = O_PIECE;

		// ALL POSSIBLE MOVES
		checkMatchVector.push_back({0, 2, 1, 2, 2, 2});
		checkMatchVector.push_back({0, 2, 0, 1, 0, 0});
		checkMatchVector.push_back({0, 2, 1, 1, 2, 0});
		checkMatchVector.push_back({2, 2, 1, 2, 0, 2});
		checkMatchVector.push_back({2, 2, 2, 1, 2, 0});
		checkMatchVector.push_back({2, 2, 1, 1, 0, 0});
		checkMatchVector.push_back({0, 0, 0, 1, 0, 2});
		checkMatchVector.push_back({0, 0, 1, 0, 2, 0});
		checkMatchVector.push_back({0, 0, 1, 1, 2, 2});
		checkMatchVector.push_back({2, 0, 2, 1, 2, 2});
		checkMatchVector.push_back({2, 0, 1, 0, 0, 0});
		checkMatchVector.push_back({2, 0, 1, 1, 0, 2});
		checkMatchVector.push_back({0, 1, 1, 1, 2, 1});
		checkMatchVector.push_back({1, 2, 1, 1, 1, 0});
		checkMatchVector.push_back({2, 1, 1, 1, 0, 1});
		checkMatchVector.push_back({1, 0, 1, 1, 1, 2});
		checkMatchVector.push_back({0, 1, 2, 1, 1, 1});
		checkMatchVector.push_back({1, 2, 1, 0, 1, 1});
		checkMatchVector.push_back({0, 2, 2, 0, 1, 1});
		checkMatchVector.push_back({2, 2, 0, 0, 1, 1});
		checkMatchVector.push_back({0, 2, 2, 2, 1, 2});
		checkMatchVector.push_back({0, 0, 2, 0, 1, 0});
		checkMatchVector.push_back({0, 2, 0, 0, 0, 1});
		checkMatchVector.push_back({2, 2, 2, 0, 2, 1});
	}

	/**
	 * AI makes decision and places pieces
	 * 
	 * @param gridArray memory reference to 3x3 array representation of game
	 * @param gridPieces sprite reference to visual representation of game board for placing piece textures
	 * @param gameState memory reference to the game state 
	 * 
	 * Note: AI decision making hierarchy-
	 * 1. Go for the win
	 * 2. Block Player from winning
	 * 3. Place at Center
	 * 4. Place at Corner
	 * 5. Place anywhere else
	 */
	void AI::PlacePiece(int (*gridArray)[3][3], sf::Sprite gridPieces[3][3], int *gameState)
	{
		try
		{
			// CHECK CONDITION WHERE THE AI CAN WIN IE 2 POSITION GOOD THIRD POSITION DETERMINE AND GO FOR WIN
			for (int i = 0; i < checkMatchVector.size(); i++)
			{
				CheckSection(checkMatchVector[i][0], checkMatchVector[i][1], checkMatchVector[i][2], checkMatchVector[i][3], checkMatchVector[i][4], checkMatchVector[i][5], AI_PIECE, gridArray, gridPieces);
			}

			// CHECK CONDITON FOR PLAYER ABOUT TO WIN AND BLOCK
			for (int i = 0; i < checkMatchVector.size(); i++)
			{
				CheckSection(checkMatchVector[i][0], checkMatchVector[i][1], checkMatchVector[i][2], checkMatchVector[i][3], checkMatchVector[i][4], checkMatchVector[i][5], PLAYER_PIECE, gridArray, gridPieces);
			}

			// CHECK CENTER EMPTY
			CheckIfPieceIsEmpty(1, 1, gridArray, gridPieces);
			// CHECK CORNER PIECES
			CheckIfPieceIsEmpty(0, 2, gridArray, gridPieces);
			CheckIfPieceIsEmpty(2, 2, gridArray, gridPieces);
			CheckIfPieceIsEmpty(0, 0, gridArray, gridPieces);
			CheckIfPieceIsEmpty(2, 0, gridArray, gridPieces);

			// CHECK OTHER PIECES
			CheckIfPieceIsEmpty(1, 2, gridArray, gridPieces);
			CheckIfPieceIsEmpty(0, 1, gridArray, gridPieces);
			CheckIfPieceIsEmpty(2, 1, gridArray, gridPieces);
			CheckIfPieceIsEmpty(1, 0, gridArray, gridPieces);
		}
		catch (int error)
		{
		}

		// CONTINUE STATE AFTER AI TURN
		*gameState = STATE_PLAYING;
	}

	/**
	 * [PRIVATE]
	 * AI decision making for WIN and BLOCKING WIN status
	 * 
	 * @param x1 first piece placement x coor
	 * @param y1 first piece placement y coor
	 * @param x2 second piece placement x coor
	 * @param y2 second piece placement y coor
	 * @param X possible placement for the third piece x coor
	 * @param Y possible placement for the third piece y coor
	 * @param pieceToCheck check for either X (Player- for blocking WIN) or O (AI - for going for the WIN) 
	 * @param gridArray memory reference to 3x3 array representation of game
	 * @param gridPieces sprite reference to visual representation of game board for placing piece textures
	 */
	void AI::CheckSection(int x1, int y1, int x2, int y2, int X, int Y, int pieceToCheck, int (*gridArray)[3][3], sf::Sprite gridPieces[3][3])
	{
		// Check matching for two pieces
		if ((*gridArray)[x1][y1] == pieceToCheck && (*gridArray)[x2][y2] == pieceToCheck)
		{
			// CHECK IF PIECE IS POPULATED OR NOT
			if (EMPTY_PIECE == (*gridArray)[X][Y])
			{
				(*gridArray)[X][Y] = AI_PIECE;											// PLACING AI PIECE IN ARRAY
				gridPieces[X][Y].setTexture(this->_data->assets.GetTexture("O Piece")); // PLACING AI PIECE IN VISUAL SPRITE
				gridPieces[X][Y].setColor(sf::Color(255, 255, 255, 255));				// DISPLAYING PIECE IN FULL OPACITY

				throw - 1; // Throwing negative error type 1st
			}
		}
	}

	/**
	 * [PRIVATE]
	 * AI decision making for NON WIN states ie Piece placement in empty spots
	 * 
	 * @param X check X coor (matrix rep) for vacany to place piece
	 * @param Y check Y coor (matrix rep) for vacany to place piece
	 * @param gridArray memory reference to 3x3 array representation of game
	 * @param gridPieces sprite reference to visual representation of game board for placing piece textures
	 * 
	 * Chronology for placements: Center, Corner, Other
	 */
	void AI::CheckIfPieceIsEmpty(int X, int Y, int (*gridArray)[3][3], sf::Sprite gridPieces[3][3])
	{
		if (EMPTY_PIECE == (*gridArray)[X][Y])
		{
			// IF SPACE AVAILABLE THE AI PIECE IS PLACED
			(*gridArray)[X][Y] = AI_PIECE;											// PLACE PIECE IN ARRAY REP
			gridPieces[X][Y].setTexture(this->_data->assets.GetTexture("O Piece")); // PLACE PIECE IN VISUAL REP

			gridPieces[X][Y].setColor(sf::Color(255, 255, 255, 255)); // DISPLAYING PIECE IN FULL OPACITY

			throw - 2; // Throwing negative error type 2nd
		}
	}
} // namespace Stha