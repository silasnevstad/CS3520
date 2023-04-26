IDIR =../include
CC=g++
CFLAGS= -I$(IDIR) -g -std=c++11 -O0

ODIR=.

LIBS=-lncurses

_DEPS = 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = compoundInterest.o findAndReplace.o statisticsFromAParagraph.o file1.o file2.o file3.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

compoundInterest: $(ODIR)/compoundInterest.o
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

findAndReplace: $(ODIR)/findAndReplace.o
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

statisticsFromAParagraph: $(ODIR)/statisticsFromAParagraph.o
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

file1: $(ODIR)/file1.o
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

file2: $(ODIR)/file2.o
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

file3: $(ODIR)/file3.o
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

all: compoundInterest findAndReplace statisticsFromAParagraph file1 file2 file3

.PHONY: clean

clean:
	rm -f *~ core $(INCDIR)/*~ 
	rm -f compoundInterest findAndReplace statisticsFromAParagraph
	rm -f file1 file2 file3
	rm -f *.o
