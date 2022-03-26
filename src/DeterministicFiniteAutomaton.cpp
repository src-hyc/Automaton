#include "DeterministicFiniteAutomaton.hpp"

#include <string>

#include <stdexcept>

using namespace Automaton;

using std::basic_string;
using std::iterator;

using std::invalid_argument;

DeterministicFiniteAutomaton::DeterministicFiniteAutomaton(const unordered_set<const State *> &stateSet, const unordered_set<const Symbol *> &alphabet, const unordered_map<const State *, unordered_map<const Symbol *, const State *>> &transitionFunction, const State *initialState, const unordered_set<const State *> &acceptStateSet): stateSet(stateSet), alphabet(alphabet), transitionFunction(transitionFunction), acceptStateSet(acceptStateSet) {
	this->initialState = initialState;
	// check whether {@code initialState} is not {@code NULL}
	if (this->initialState == NULL) {
		throw invalid_argument("initialState is NULL");
	}
	// check whether {@code initialState} is in {@code stateSet}
	if (this->stateSet.find(initialState) == this->stateSet.end()) {
		throw invalid_argument("initialState is not in stateSet");
	}
	// check whether {@code stateSet} does not contain {@code NULL}
	if (this->stateSet.find(NULL) != this->stateSet.end()) {
		throw invalid_argument("stateSet contains NULL");
	}
	// check whether {@code alphabet} does not contain {@code NULL}
	if (this->alphabet.find(NULL) != this->alphabet.end()) {
		throw invalid_argument("alphabet contains NULL");
	}
	for (unordered_map<const State *, unordered_map<const Symbol *, const State *>>::const_iterator it = this->transitionFunction.begin(); it != this->transitionFunction.end(); it++) {
		// {@code state} is a key of {@code transitionFunction}
		const State *state = it->first;
		// check whether {@code state} is in {@code stateSet}
		if (this->stateSet.find(state) == this->stateSet.end()) {
			throw invalid_argument("unrecognized source state in transitionFunction");
		}
		// {@code symbolFunction} is a value of {@code transitionFunction}
		unordered_map<const Symbol *, const State *> symbolFunction = it->second;
		// check if {@code symbolFunction} is not empty
		if (symbolFunction.empty()) {
			throw invalid_argument("empty value in transitionFunction");
		}
		for (unordered_map<const Symbol *, const State *>::const_iterator symbolIterator = symbolFunction.begin(); symbolIterator != symbolFunction.end(); symbolIterator++) {
			// {@code symbol} is a key of {@code symbolFunction}
			const Symbol *symbol = symbolIterator->first;
			// check if {@code symbol} is in {@code alphabet}
			if (this->alphabet.find(symbol) == this->alphabet.end()) {
				throw invalid_argument("unrecognized symbol in transitionFunction");
			}
			// {@code targetState} is a value of {@code symbolFunction}
			const State *targetState = symbolIterator->second;
			// check if {@code targetState} is in {@code stateSet}
			if (this->stateSet.find(targetState) == this->stateSet.end()) {
				throw invalid_argument("unrecognized target state in transitionFunction");
			}
		}
	}
	// check whether states in {@code acceptStateSet} is not in {@code }
	for (unordered_set<const State *>::const_iterator it = this->acceptStateSet.begin(); it != this->acceptStateSet.end(); it++) {
		if (this->stateSet.find(*it) == this->stateSet.end()) {
			throw invalid_argument("acceptStateSet is not a subset of stateSet");
		}
	}
}

bool DeterministicFiniteAutomaton::accept(const basic_string<const Symbol *> &string) const noexcept {
	int length = string.length();
	// start from {@code initialState}
	const State *tokenState = this->initialState;
	for (int i = 0; i < length; i++) {
		// state transition
		if (this->transitionFunction.find(tokenState) != this->transitionFunction.end()) {
			unordered_map<const Symbol *, const State *> symbolFunction = this->transitionFunction.at(tokenState);
			const Symbol *symbol = string[i];
			if (symbolFunction.find(symbol) != symbolFunction.end()) {
				tokenState = symbolFunction.at(symbol);
			}
		}
	}
	// whether the final state is in {@code acceptStateSet}
	return this->acceptStateSet.find(tokenState) != this->acceptStateSet.end();
}
