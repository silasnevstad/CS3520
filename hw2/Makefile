CC = g++
CFLAGS = -std=c++11

all: clean dice_rolling phishing maze

dice_rolling: rollingOfDice.cpp
	$(CC) $(CFLAGS) rollingOfDice.cpp -o dice_rolling

phishing: phishing.cpp
	$(CC) $(CFLAGS) phishing.cpp -o phishing

maze: maze.cpp
	$(CC) $(CFLAGS) maze.cpp -o maze

clean:
	rm -f dice_rolling
	rm -f phishing
	rm -f maze
