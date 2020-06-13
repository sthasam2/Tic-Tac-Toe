#ifndef State_hpp
#define State_hpp
// #pragma once

namespace Stha
{
	class State
	{
	public:
		// Initialize the state
		virtual void Init() = 0;

		// # I/O

		//Handle Inputs
		virtual void HandleInput() = 0;

		/**
		 * @brief Update variables
		 * 
		 */
		virtual void Update(float dt) = 0;

		/**
		 * @brief Create Output (Draw Xs and Os)
		 * 
		 * @param : float dt
		 * 
		 * NOTE:
		 *  dt or delta-time is the amount of time that has passed since the game last updated. It is used to make sure that any calculations that have it in there are framerate independent. A time that you would use dt is if you are gradually moving an object in a direction (eg. a bullet). A time you wouldn't want to use dt is if you are moving an object to the right x distance on each click. If you used dt, it would multiply the 100 pixels you wanted to move the object by a very small number, which in turn would hardly move it.
		 * 
		*/
		virtual void Draw(float dt) = 0;

		// # Game Controls

		// Pause Game
		virtual void Pause() {}

		// Resume Game
		virtual void Resume() {}
	};
} // namespace Stha

#endif