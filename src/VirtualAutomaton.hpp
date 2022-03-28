#ifndef VIRTUAL_AUTOMATON_HPP
#define VIRTUAL_AUTOMATON_HPP

#include "State.hpp"
#include "Symbol.hpp"

using namespace Automaton;

namespace Automaton {
	/**
	 * A virtual automaton
	 */
	template <typename StateType>
	class VirtualAutomaton {
		protected:
			// the alphabet of the automaton
			const Alphabet alphabet;
			const StateType initialState;

			/**
			 * Create an automaton with an alphabet
			 *
			 * @param alphabet the alphabet of the automaton
			 */
			VirtualAutomaton(const Alphabet &alphabet, const StateType &initialState) noexcept: alphabet(alphabet), initialState(initialState) {
			}

		public:
			/**
			 * Check whether the automaton accepts a string
			 *
			 * @param string the string to be checked
			 * @return true if the automaton accepts the string, false otherwise
			 */
			virtual bool accept(const String &string) const = 0;
	};
};

#endif /* VIRTUAL_AUTOMATON_HPP */
