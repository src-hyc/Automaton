#ifndef DETERMINISTIC_FINITE_AUTOMATON_HPP
#define DETERMINISTIC_FINITE_AUTOMATON_HPP

#include <unordered_set>
#include <unordered_map>
#include <string>

using std::unordered_set;
using std::unordered_map;
using std::basic_string;

namespace Automaton {
	class DeterministicFiniteAutomaton {
		public:
			class State;
			class Symbol;

		private:
			const unordered_set<const State *> stateSet;
			const unordered_set<const Symbol *> alphabet;
			const unordered_map<const State *, unordered_map<const Symbol *, const State *>> transitionFunction;
			const State *initialState;
			const unordered_set<const State *> acceptStateSet;

		public:
			class State {};
			class Symbol {};
			DeterministicFiniteAutomaton(const unordered_set<const State *> &, const unordered_set<const Symbol *> &, const unordered_map<const State *, unordered_map<const Symbol *, const State *>> &, const State *, const unordered_set<const State *> &);
			bool accept(const basic_string<const Symbol *> &) const noexcept;
	};
};

#endif /* DETERMINISTIC_FINITE_AUTOMATON_HPP */
