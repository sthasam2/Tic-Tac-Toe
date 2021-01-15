#pragma once

#include "StateMachine.hpp"

namespace Stha
{
	/**
	 * Add new state by replacing previous state
	 * 
	 * @param newState	-	 a new State
	 * @param isReplacing 	- specifies whether it replaces previous state
	 */
	void StateMachine::AddState(StateRef newState, bool isReplacing)
	{
		this->_isAdding = true;
		this->_isReplacing = isReplacing;

		this->_newState = std::move(newState);
	}

	/**
	 *  Removes the top state
	*/
	void StateMachine::RemoveState()
	{
		this->_isRemoving = true;
	}

	/**
	 *  Runs in a loop of each gane state - EVENT LOOP
	*/
	void StateMachine::ProcessStateChanges()
	{
		// REMOVAL
		if (this->_isRemoving && !this->_states.empty())
		{
			this->_states.pop();

			if (this->_states.empty())
			{
				this->_states.top()->Resume();
			}
		}

		this->_isRemoving = false;

		// ADDITION
		if (this->_isAdding)
		{
			if (!this->_states.empty())
			{
				if (this->_isReplacing)
				{
					this->_states.pop();
				}
				else
				{
					this->_states.top()->Pause();
				}
			}
			// REPLACEMENT
			this->_states.push(std::move(this->_newState));
			this->_states.top()->Init();
			this->_isAdding = false;
		}
	}

	/**
	 * Points to currently active state
	*/
	StateRef &StateMachine::GetActiveState()
	{
		return this->_states.top();
	}
} // namespace Stha
