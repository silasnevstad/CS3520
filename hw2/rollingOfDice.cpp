#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int NUM_ROLLS = 36000; // Number of times to roll the dice
const int NUM_SIDES = 6; // Number of sides on each die

int main() {
  int tally[NUM_SIDES * 2 + 1] = {0};  // Initialize all elements to 0
  srand(time(NULL));  // Seed the random number generator

  // Roll the dice 36,000 times
  for (int i = 0; i < NUM_ROLLS; i++) {
    int roll1 = rand() % NUM_SIDES + 1;
    int roll2 = rand() % NUM_SIDES + 1;
    int sum = roll1 + roll2;
    tally[sum]++;
  }

  // Print the results in a tabular format
  cout << "Sum of dice rolls: Tally\tPercentage" << endl;
  for (int i = 2; i <= NUM_SIDES * 2; i++) {
    cout << i << ":\t\t" << tally[i] << "\t\t" << 100.0 * tally[i] / NUM_ROLLS << "%" << endl;
  }

  return 0;
}
