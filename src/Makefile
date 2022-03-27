CXXFLAGS= --std=c++17 -O2 -Wall -Wextra
AR= ar rcu
RANLIB= ranlib

AUTOMATON_A= libautomaton.a

AUTOMATON_O= DeterministicFiniteAutomaton.o

default: $(AUTOMATON_A)

$(AUTOMATON_A): $(AUTOMATON_O)
	$(AR) $@ $?
	$(RANLIB) $@

DeterministicFiniteAutomaton.o: DeterministicFiniteAutomaton.cpp Symbol.hpp VirtualAutomaton.hpp

clean:
	rm -rf $(AUTOMATON_A) $(AUTOMATON_O)

.PHONY: default clean
