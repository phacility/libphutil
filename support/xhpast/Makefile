BISONFLAGS = --verbose -Wall
CPPFLAGS   = -fPIC -Wall
FLEXFLAGS  = -CFr

ifdef DEBUG
	BISONFLAGS += --debug
	CPPFLAGS   += -ggdb -DDEBUG
	FLEXFLAGS  += --debug
else
	CPPFLAGS  += -O3 -minline-all-stringops
endif

ifdef PROFILE
	CPPFLAGS += -pg
endif

ifdef STATIC
	CPPFLAGS += -static
endif

ifdef MSYSTEM
	CPPFLAGS += -static-libgcc -static-libstdc++
endif

ROOT = ../../src/parser/xhpast

.PHONY: all
all: xhpast

clean:
	rm -f xhpast parser.yacc.output libxhpast.a *.o

cleanall: clean
	rm -f scanner.lex.hpp scanner.lex.cpp parser.yacc.hpp parser.yacc.cpp
	rm -f node_names.hpp parser_nodes.php

.PHONY: install
install: xhpast
	cp xhpast $(ROOT)/bin/xhpast

.PHONY: parser scanner

parser: parser.yacc.hpp parser.yacc.cpp
scanner: scanner.lex.hpp scanner.lex.cpp

%.lex.hpp %.lex.cpp: %.l
ifndef SKIP_SCANNER
	flex $(FLEXFLAGS) --header-file=$*.lex.hpp --outfile=$*.lex.cpp $<
	@echo '/* @gen''er''ated */' >> $*.lex.hpp
	@echo '/* @gen''er''ated */' >> $*.lex.cpp
else
	touch $*.lex.hpp $*.lex.cpp
endif

%.yacc.hpp %.yacc.cpp: %.y
ifndef SKIP_PARSER
	bison $(BISONFLAGS) --defines=$*.yacc.hpp --output=$*.yacc.cpp $<
	@echo '/* @gen''er''ated */' >> $*.yacc.hpp
	@echo '/* @gen''er''ated */' >> $*.yacc.cpp
else
	touch $*.yacc.hpp $*.yacc.cpp
endif

%.o: %.cpp
	$(CXX) -c $(CPPFLAGS) -o $@ $<

node_names.hpp parser_nodes.php: generate_nodes.php
	php -f $<

parser.yacc.o: scanner.lex.hpp
scanner.lex.o: parser.yacc.hpp node_names.hpp scanner.lex.hpp

libxhpast.a: scanner.lex.o parser.yacc.o
	$(AR) -crs $@ $^

xhpast: xhpast.cpp libxhpast.a
	$(CXX) $(CPPFLAGS) -o $@ $^
