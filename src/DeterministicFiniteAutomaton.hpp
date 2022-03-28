#ifndef DETERMINISTIC_FINITE_AUTOMATON_HPP
#define DETERMINISTIC_FINITE_AUTOMATON_HPP

#include "Symbol.hpp"
#include "VirtualAutomaton.hpp"
#include "DeterministicAutomaton.hpp"
#include "FiniteAutomaton.hpp"

#include <unordered_set>
#include <unordered_map>

using namespace Automaton;

using std::unordered_set;
using std::unordered_map;

namespace Automaton {
	/**
	 * A Deterministic Finite Automaton (DFA)
	 */
	template<typename StateType>
	class DeterministicFiniteAutomaton: public DeterministicAutomaton<StateType>, public FiniteAutomaton<StateType> {
		private:
			// accept states of the DFA, should be a subset of {@code stateSet}
			const unordered_set<StateType> acceptStateSet;

		public:
			/**
			 * Create a {@code DeterministicFiniteAutomaton} object.
			 *
			 * @param alphabet input symbols of the automaton
			 * @param initialState the initial state of the automaton
			 * @param transitionFunction the transition function
			 * @param stateSet states of the automaton
			 * @param acceptStateSet accept states of the automaton
			 */
			DeterministicFiniteAutomaton(const Alphabet &alphabet, const StateType &initialState, StateType (*transitionFunction)(StateType, const Symbol *), const unordered_set<StateType> &stateSet, const unordered_set<StateType> &acceptStateSet): VirtualAutomaton<StateType>(alphabet, initialState), FiniteAutomaton<StateType>(alphabet, initialState, stateSet), DeterministicAutomaton<StateType>(alphabet, initialState, transitionFunction), acceptStateSet(acceptStateSet) {
			}
			bool accept(const String &string) const noexcept {
				int length = string.length();
				StateType tokenState = this->initialState;
				for (int i = 0; i < length; i++) {
					tokenState = this->transitionFunction(tokenState, string[i]);
				}
				return this->acceptStateSet.find(tokenState) != this->acceptStateSet.end();
			}
	};
};

#endif /* DETERMINISTIC_FINITE_AUTOMATON_HPP */
