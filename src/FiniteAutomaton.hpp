#ifndef FINITE_AUTOMATON_HPP
#define FINITE_AUTOMATON_HPP

#include "VirtualAutomaton.hpp"

#include <unordered_set>

using namespace Automaton;

using std::unordered_set;

namespace Automaton {
	/**
	 * A finite automaton
	 */
	template <typename StateType>
	class FiniteAutomaton: virtual public VirtualAutomaton<StateType> {
		protected:
			/*
			 * the set of states of the automaton
			 */
			unordered_set<StateType> stateSet;

			/**
			 * Create a finite automaton with an alphabet and a set of states
			 *
			 * @param alphabet the alphabet of the automaton
			 * @param stateSet the set of states of the automaton
			 */
			FiniteAutomaton(const Alphabet &alphabet, const unordered_set<StateType> &stateSet) noexcept: VirtualAutomaton<StateType>(alphabet), stateSet(stateSet) {
			}
	};
};

#endif /* FINITE_AUTOMATON_HPP */
