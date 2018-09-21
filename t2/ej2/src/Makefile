IDIR =../include
CXX=g++
CXXFLAGS=-I$(IDIR) -g -std=c++17

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = file.hpp distribution.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o file.o distribution.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

program: $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ program

.PHONY: run

run: ./program
	./program ${ARGS}
