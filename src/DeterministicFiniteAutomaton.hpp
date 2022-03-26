#ifndef DETERMINISTIC_FINITE_AUTOMATON_HPP
#define DETERMINISTIC_FINITE_AUTOMATON_HPP

#include "Symbol.hpp"
#include "VirtualAutomaton.hpp"

#include <unordered_set>
#include <unordered_map>

using namespace Automaton;

using std::unordered_set;
using std::unordered_map;

namespace Automaton {
	/**
	 * A Deterministic Finite Automaton (DFA)
	 */
	class DeterministicFiniteAutomaton: public VirtualAutomaton {
		public:
			/**
			 * A state of a DFA
			 */
			class State;

		private:
			// states of the DFA
			const unordered_set<const State *> stateSet;
			/**
			 * the transition function of the DFA.
			 * for a key {@code state} of {@code transitionFunction}, {@code state} should be in {@code stateSet}, and {@code transitionFunction[state]} should not be empty.
			 * for a key {@code symbol} of {@code transitionFunction[state]}, {@code symbol} should be in {@code alphabet}, and {@code transitionFunction[state][symbol]} should be in {@code stateSet}.
			 * for {@code state} in {@code stateSet} and {@code symbol} in {@code alphabet}, when {@code state} is not a key of {@code transitionFunction} or {@code symbol} is not a key of {@code transitionFunction[state]}, {@code transitionFunction[state][symbol]} is considered to be {@code state}.
			 */
			const unordered_map<const State *, unordered_map<const Symbol *, const State *>> transitionFunction;
			// the initial state of the DFA, should be in {@code stateSet}
			const State *initialState;
			// accept states of the DFA, should be a subset of {@code stateSet}
			const unordered_set<const State *> acceptStateSet;

		public:
			class State {};
			/**
			 * Create a {@code DeterministicFiniteAutomaton} object.
			 *
			 * @param stateSet states of the automaton
			 * @param alphabet input symbols of the automaton
			 * @param transitionFunction the transition function
			 * @param initialState the initial state of the automaton
			 * @param acceptStateSet accept states of the automaton
			 * @throws invalid_argument when some constraints of the parameters are not fulfilled
			 */
			DeterministicFiniteAutomaton(const unordered_set<const State *> &stateSet, const Alphabet &alphabet, const unordered_map<const State *, unordered_map<const Symbol *, const State *>> &transitionFunction, const State *initialState, const unordered_set<const State *> &acceptStateSet);
			bool accept(const String &string) const noexcept;
	};
};

#endif /* DETERMINISTIC_FINITE_AUTOMATON_HPP */
