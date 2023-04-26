CC = g++
CFLAGS = -std=c++11

all: clean struct practice1 practice2 charptr matrix3d dynamic3d

struct: struct.cpp
	$(CC) $(CFLAGS) struct.cpp -o struct

practice1: practice_1.cpp
	$(CC) $(CFLAGS) practice_1.cpp -o practice_1

practice2: practice_2.cpp
	$(CC) $(CFLAGS) practice_2.cpp -o practice_2

charptr: charptr.cpp
	$(CC) $(CFLAGS) charptr.cpp -o charptr

matrix3d: 3dmatrix.cpp
	$(CC) $(CFLAGS) 3dmatrix.cpp -o 3dmatrix

dynamic3d: 3d_dynamic.cpp
	$(CC) $(CFLAGS) 3d_dynamic.cpp -o dynamic3d

clean:
	rm -f struct
	rm -f practice_1
	rm -f practice_2
	rm -f charptr
	rm -f 3dmatrix
	rm -f dynamic3d
