IDIR =../include
LDIR =../lib
ODIR=obj

CC=g++
CFLAGS=-g -std=c++17
OCFLAGS=-g -lobjc -lgnustep-base -fconstant-string-class=NSConstantString

# C++ Dependencies and Objects
_INTMULT_DEPS =
INTMULT_DEPS = $(patsubst %,$(IDIR)/%,$(_INTMULT_DEPS))

_INTMULT_OBJ = intMult.o
INTMULT_OBJ = $(patsubst %,$(ODIR)/%,$(_INTMULT_OBJ))

# Compile C++ objects
$(ODIR)/%.o: %.cpp $(INTMULT_DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# Make commands
all: intMult

intMult: $(INTMULT_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean all

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
	rm -f intMult
