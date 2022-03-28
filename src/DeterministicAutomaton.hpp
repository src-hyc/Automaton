#ifndef DETERMINISTIC_AUTOMATON_HPP
#define DETERMINISTIC_AUTOMATON_HPP

#include "VirtualAutomaton.hpp"
#include "Symbol.hpp"

#include <functional>

using namespace Automaton;

using std::function;

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
			function<StateType(StateType, const Symbol *)> transitionFunction;

			/**
			 * Create a deterministic automaton with an alphabet and a transition function
			 *
			 * @param alphabet the alphabet of the automaton
			 * @param initialState the initialState of the automaton
			 * @param transitionFunction the transition function of the automaton
			 */
			DeterministicAutomaton(const Alphabet &alphabet, const StateType &initialState, function<StateType(StateType, const Symbol *)> transitionFunction) noexcept: VirtualAutomaton<StateType>(alphabet, initialState), transitionFunction(transitionFunction) {
			}
	};
};

#endif /* DETERMINISTIC_AUTOMATON_HPP */
