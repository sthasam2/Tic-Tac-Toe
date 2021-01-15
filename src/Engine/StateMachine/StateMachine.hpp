// #ifndef StateMachine_hpp
// #define StateMachine_hpp

#pragma once

#include <memory>
#include <stack>

#include "State.hpp"

namespace Stha
{
	// custom type definition
	typedef std::unique_ptr<State> StateRef;

	/**
     * For handling the States
     * 
     * @function: AddState(StateRef newState, bool isReplacing = true)
     * @function: RemoveState()
     * @function: void ProcessStateChanges()
    */
	class StateMachine
	{
	public:
		StateMachine(){};  //constructor
		~StateMachine(){}; //destructor

		void AddState(StateRef newState, bool isReplacing = true);
		void RemoveState();
		void ProcessStateChanges();

		StateRef &GetActiveState();

	private:
		std::stack<StateRef> _states; //stack of all the states
		StateRef _newState;			  //latest state

		// Track state processes

		bool _isRemoving;  // check if removal
		bool _isAdding;	   // check if addition
		bool _isReplacing; // check if replacement
	};
} // namespace Stha

// #endif