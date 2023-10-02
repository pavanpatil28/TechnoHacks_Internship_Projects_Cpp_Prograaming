#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0)); 

    cout<<"\n\n \t\t ##### Welcome to the Dice Rolling Simulator ##### \n\n\n";

    int dice1 = rand() % 6 + 1; // Generate a random number between 1 and 6 for the first die
    int dice2 = rand() % 6 + 1; // Generate a random number between 1 and 6 for the second die

    cout << " --> You Rolled :- \n\n \t >> Dice 1 = " << dice1 << "\n \t >> Dice 2 = " << dice2 << "\n";
    cout << "\n --> Total is = " << dice1 + dice2 << "\n\n";

    return 0;
}
