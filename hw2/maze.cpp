#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

class MazeGenerator {
    public:
        std::vector<std::vector<char>> generateMaze(int size) {
            std::vector<std::vector<char>> maze(size, std::vector<char>(size, '#')); // initialize maze with all walls
            srand(time(NULL)); 
            int start = rand() % (size - 2) + 1; // choose a random starting points
            int end = rand() % (size - 2) + 1;
            for (int i = 1; i < size - 1; i++) { // create a random maze
                for (int j = 1; j < size - 1; j++) {
                    if (i != start || j != 0 || i != end || j != size - 1) { // don't overwrite the start and end points
                        if (rand() % 2 == 0) {
                            maze[i][j] = '.';
                        }
                    }
                }
            }
            maze[start][0] = '.';
            maze[end][size - 1] = '.';

            // attemp to make good maze
            // dig a path from start to end avoiding the border
            // int i = start;
            // int j = 0;
            // while (i != end || j != size - 1) {
            //     if (i == end) {
            //         j++;
            //     } else if (j == size - 1) {
            //         i++;
            //     } else {
            //         if (rand() % 2 == 0) {
            //             j++;
            //         } else {
            //             i++;
            //         }
            //     }
            //     if (i < 0 || i >= size || j < 0 || j >= size) {
            //         break;
            //     }
            //     maze[i][j] = '.';
            // }

            return maze;
        }

        void printMaze(std::vector<std::vector<char>> maze) {
            int size = maze.size();
            for (int i = 0; i < size; i++) { // loop through the maze and print it
                for (int j = 0; j < size; j++) {
                    std::cout << maze[i][j] << " ";
                }
                std::cout << std::endl;
            }
        }
};

int main() {
    int size;
    std::cout << "Enter the size of the maze: ";
    std::cin >> size;
    while (size < 3) {
        std::cout << "Error: Size must be at least 3. Enter the size of the maze: ";
        std::cin >> size;
    }
    MazeGenerator mg;
    std::vector<std::vector<char>> maze = mg.generateMaze(size);
    mg.printMaze(maze);
    return 0;
}