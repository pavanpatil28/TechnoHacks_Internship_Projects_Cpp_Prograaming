#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
 
    srand(time(0)); 
    int secretNumber = rand() % 100 + 1; // Generate a random number between 1 and 100
    int guess;
    int attempts = 0;

    cout<<"\n\n \t\t ##### Welcome to the Number Guessing Game ##### \n\n\n";
    cout<<" >>> Guess the Number between 1 and 100 :- \n";

    while(guess != secretNumber)
    {
        cout << "\n >> Enter Your Guess : ";
        cin >> guess;
        attempts++;

        if (guess < secretNumber) 
        {
            cout << "\n --> Too Low! Try a Higher Number.\n";
        } 
        
        if (guess > secretNumber) 
        {
            cout << "\n --> Too High! Try a Lower Number.\n";
        } 
    } 

    cout << "\n ---> Congratulations! You Guessed the Number " << secretNumber << " in " << attempts << " Attempts. \n\n";
 
    return 0;
}



