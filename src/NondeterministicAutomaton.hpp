#ifndef NONDETERMINISTIC_AUTOMATON_HPP
#define NONDETERMINISTIC_AUTOMATON_HPP

#include "VirtualAutomaton.hpp"
#include "Symbol.hpp"

#include <functional>

using namespace Automaton;

using std::function;

namespace Automaton {
	/**
	 * A nondeterministic automaton
	 */
	template <typename StateType>
	class NondeterministicAutomaton: virtual public VirtualAutomaton<StateType> {
		protected:
			/*
			 * the transition function of the automaton
			 */
			function<StateType(StateType, const Symbol *)> transitionFunction;

			/**
			 * Create a nondeterministic automaton with an alphabet and a transition function
			 *
			 * @param alphabet the alphabet of the automaton
			 * @param initialState the initialState of the automaton
			 * @param transitionFunction the transition function of the automaton
			 */
			NondeterministicAutomaton(const Alphabet &alphabet, const StateType &initialState, function<unordered_set<StateType>(StateType, const Symbol *)> transitionFunction) noexcept: VirtualAutomaton<StateType>(alphabet, initialState), transitionFunction(transitionFunction) {
			}
	};
};

#endif /* NONDETERMINISTIC_AUTOMATON_HPP */
