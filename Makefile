INSTALL_TOP= /usr/local
INSTALL_INC= $(INSTALL_TOP)/include
INSTALL_LIB= $(INSTALL_TOP)/lib

INSTALL= install -p
INSTALL_DATA= $(INSTALL) -m 0644

MKDIR= mkdir -p
RM= rm -f

TO_INC= *.hpp
TO_LIB= libautomaton.a

default clean:
	@cd src && $(MAKE) $@

install:
	$(MKDIR) $(INSTALL_INC) $(INSTALL_LIB)
	cd src && $(INSTALL_DATA) $(TO_INC) $(INSTALL_INC)
	cd src && $(INSTALL_DATA) $(TO_LIB) $(INSTALL_LIB)

uninstall:
	cd $(INSTALL_INC) && $(RM) $(TO_INC)
	cd $(INSTALL_LIB) && $(RM) $(TO_LIB)

.PHONY: default clean install uninstall
