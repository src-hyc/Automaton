#include "DeterministicFiniteAutomaton.hpp"

#include <string>

#include <stdexcept>

using namespace Automaton;

using std::basic_string;
using std::iterator;

using std::invalid_argument;

DeterministicFiniteAutomaton::DeterministicFiniteAutomaton(const unordered_set<const State *> &stateSet, const unordered_set<const Symbol *> &alphabet, const unordered_map<const State *, unordered_map<const Symbol *, const State *>> &transitionFunction, const State *initialState, const unordered_set<const State *> &acceptStateSet): stateSet(stateSet), alphabet(alphabet), transitionFunction(transitionFunction), acceptStateSet(acceptStateSet) {
	this->initialState = initialState;
	if (this->initialState == NULL) {
		throw invalid_argument("initialState is NULL");
	}
	if (this->stateSet.find(initialState) == this->stateSet.end()) {
		throw invalid_argument("initialState is not in stateSet");
	}
	if (this->stateSet.find(NULL) != this->stateSet.end()) {
		throw invalid_argument("stateSet contains NULL");
	}
	if (this->alphabet.find(NULL) != this->alphabet.end()) {
		throw invalid_argument("alphabet contains NULL");
	}
	for (unordered_map<const State *, unordered_map<const Symbol *, const State *>>::const_iterator it = this->transitionFunction.begin(); it != this->transitionFunction.end(); it++) {
		const State *state = it->first;
		if (this->stateSet.find(state) == this->stateSet.end()) {
			throw invalid_argument("unrecognized state in transitionFunction");
		}
		unordered_map<const Symbol *, const State *> symbolFunction = it->second;
		if (symbolFunction.empty()) {
			throw invalid_argument("empty value in transitionFunction");
		}
		for (unordered_map<const Symbol *, const State *>::const_iterator symbolIterator = symbolFunction.begin(); symbolIterator != symbolFunction.end(); symbolIterator++) {
			const Symbol *symbol = symbolIterator->first;
			if (this->alphabet.find(symbol) == this->alphabet.end()) {
				throw invalid_argument("unrecognized symbol in transitionFunction");
			}
			const State *targetState = symbolIterator->second;
			if (this->stateSet.find(targetState) == this->stateSet.end()) {
				throw invalid_argument("unrecognized state in transitionFunction");
			}
		}
	}
	for (unordered_set<const State *>::const_iterator it = this->acceptStateSet.begin(); it != this->acceptStateSet.end(); it++) {
		if (this->stateSet.find(*it) == this->stateSet.end()) {
			throw invalid_argument("acceptStateSet is not a subset of stateSet");
		}
	}
}

bool DeterministicFiniteAutomaton::accept(const basic_string<const Symbol *> &string) const noexcept {
	int length = string.length();
	const State *tokenState = this->initialState;
	for (int i = 0; i < length; i++) {
		if (this->transitionFunction.find(tokenState) != this->transitionFunction.end()) {
			unordered_map<const Symbol *, const State *> symbolFunction = this->transitionFunction.at(tokenState);
			const Symbol *symbol = string[i];
			if (symbolFunction.find(symbol) != symbolFunction.end()) {
				tokenState = symbolFunction.at(symbol);
			}
		}
	}
	return this->acceptStateSet.find(tokenState) != this->acceptStateSet.end();
}
