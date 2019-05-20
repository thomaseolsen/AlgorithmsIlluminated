IDIR =../include
LDIR =../lib
ODIR=obj

CC=g++
CFLAGS=-g -std=c++17
OCFLAGS=-g -lobjc -lgnustep-base -fconstant-string-class=NSConstantString

# C++ Dependencies and Objects
_MERGESORT_DEPS =
MERGESORT_DEPS = $(patsubst %,$(IDIR)/%,$(_MERGESORT_DEPS))

_MERGESORT_OBJ = mergeSort.o
MERGESORT_OBJ = $(patsubst %,$(ODIR)/%,$(_MERGESORT_OBJ))

# Compile C++ objects
$(ODIR)/%.o: %.cpp $(MERGESORT_DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# Make commands
all: mergeSort

mergeSort: $(MERGESORT_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean all

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
	rm -f mergeSort
