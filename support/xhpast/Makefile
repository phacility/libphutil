ifdef DEBUG
CPPFLAGS = -fPIC -ggdb -Wall -DDEBUG
else
CPPFLAGS = -fPIC -g -Wall -O3 -minline-all-stringops
endif

ifdef PROFILE
CPPFLAGS += -pg
endif

ROOT = ../../src/parser/xhpast

all: xhpast

clean:
	-rm xhpast parser.yacc.cpp scanner.lex.cpp scanner.lex.hpp parser.yacc.output parser.yacc.hpp libxhpast.a *.o 2>/dev/null

install: xhpast
	cp xhpast $(ROOT)/bin/xhpast

parser.yacc.cpp: parser.y
	bison --debug --verbose -d -o $@ $<

parser.yacc.hpp: parser.yacc.cpp

scanner.lex.cpp: scanner.l
	`which flex35 2>/dev/null || which flex 2>/dev/null` \
	  -C --header-file=scanner.lex.hpp -o $@ -d $<

scanner.lex.hpp: scanner.lex.cpp

node_names.hpp: generate_nodes.php
	php -f generate_nodes.php
	cp parser_nodes.php $(ROOT)/constants/

%.o: %.cpp
	$(CXX) -c $(CPPFLAGS) -o $@ $<

parser.yacc.o: scanner.lex.hpp

scanner.lex.o: parser.yacc.hpp node_names.hpp

libxhpast.a: astnode.o scanner.lex.o parser.yacc.o
	$(AR) -crs $@ $^

xhpast: xhpast.cpp libxhpast.a
	$(CXX) $(CPPFLAGS) -o $@ $^

.PHONY: all clean tags
