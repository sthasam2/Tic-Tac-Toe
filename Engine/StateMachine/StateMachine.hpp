#ifndef StateMachine_hpp
#define StateMachine_hpp

// #pragma once

#include <memory>
#include <stack>

#include "State.hpp"

namespace Stha
{
	// custom type definition
	typedef std::unique_ptr<State> StateRef;

	/**
     * StateMachine
     * 
     * @brief For handling the States
     * 
     * @functions:
     * AddState(StateRef newState, bool isReplacing = true)
     * RemoveState()
     * void ProcessStateChanges()
    */
	class StateMachine
	{
	public:
		//constructor
		StateMachine(){};
		//destructor
		~StateMachine(){};

		//Add new state by replacing previous state
		void AddState(StateRef newState, bool isReplacing = true);
		// Removes the top state
		void RemoveState();
		// Runs in a loop of each state - EVENT LOOP
		void ProcessStateChanges();

		// Points to currently active state
		StateRef &GetActiveState();

	private:
		//stack of all the states
		std::stack<StateRef> _states;
		//latest state
		StateRef _newState;

		// Track state processes

		// check removal
		bool _isRemoving;
		//check aadition
		bool _isAdding;
		// check replacement
		bool _isReplacing;
	};
} // namespace Stha

#endif