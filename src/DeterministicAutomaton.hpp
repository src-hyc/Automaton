#ifndef DETERMINISTIC_AUTOMATON_HPP
#define DETERMINISTIC_AUTOMATON_HPP

#include "VirtualAutomaton.hpp"

using namespace Automaton;

namespace Automaton {
	/**
	 * A deterministic automaton
	 */
	template <typename StateType>
	class DeterministicAutomaton: virtual public VirtualAutomaton<StateType> {
		protected:
			/*
			 * the transition function of the automaton
			 */
			StateType transitionFunction(StateType state);

			/**
			 * Create a deterministic automaton with an alphabet and a transition function
			 *
			 * @param alphabet the alphabet of the automaton
			 * @param transitionFunction the transition function of the automaton
			 */
			DeterministicAutomaton(const Alphabet &alphabet, StateType transitionFunction(StateType)) noexcept: VirtualAutomaton<StateType>(alphabet) {
				this->transitionFunction = transitionFunction;
			}
	};
};

#endif /* DETERMINISTIC_AUTOMATON_HPP */
