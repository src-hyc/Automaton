#ifndef SYMBOL_HPP
#define SYMBOL_HPP

#include <unordered_set>
#include <string>

using std::unordered_set;
using std::basic_string;

namespace Automaton {
	/**
	 * An input symbol of an automaton
	 */
	class Symbol {};

	// The alphabet of an automaton
	typedef unordered_set<const Symbol *> Alphabet;
	// A string of {@code Symbol}
	typedef basic_string<const Symbol *> String;
};

#endif /* SYMBOL_HPP */
