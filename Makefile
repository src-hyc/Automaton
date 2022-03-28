INSTALL_TOP= /usr/local
INSTALL_INC= $(INSTALL_TOP)/include

INSTALL= install -p
INSTALL_DATA= $(INSTALL) -m 0644

MKDIR= mkdir -p
RM= rm -f

TO_INC= Symbol.hpp State.hpp VirtualAutomaton.hpp FiniteAutomaton.hpp DeterministicAutomaton.hpp DeterministicFiniteAutomaton.hpp

default clean:
	@cd src && $(MAKE) $@

install:
	$(MKDIR) $(INSTALL_INC) $(INSTALL_LIB)
	cd src && $(INSTALL_DATA) $(TO_INC) $(INSTALL_INC)

uninstall:
	cd $(INSTALL_INC) && $(RM) $(TO_INC)

.PHONY: default clean install uninstall
