#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0)); 
    int choice;

    cout<<"\n\n \t\t ##### Welcome to Rock, Paper, Scissors ##### \n\n\n";

    while(1)
    {
        cout<<" >>> Choose One :- \n\n 1] Rock. \t 2] Paper. \n 3] Scissors. \t 4] Exit Game. \n\n >> Enter Your Choice :: ";
        cin >> choice;

        if(choice==4)
        {
            cout<<"\n ---> Game Exited Successfully !!! \n\n";
            break;
        }

        if (choice < 1 || choice > 4) 
        {
            cout << "\n ---> Invalid Choice. Please Choose 1 Rock, 2 Paper, or 3 Scissors. \n\n";
            continue;
        }

        int random_choice = rand() % 3 + 1; // Generate a random choice for the computer

        cout << "\n >> Computer Choose ";

        switch (random_choice) {
            case 1:
                cout << "Rock.\n\n";
                break;
            case 2:
                cout << "Paper.\n\n";
                break;
            case 3:
                cout << "Scissors.\n\n";
                break;
        }

        cout << " >> You Choose ";

        switch (choice) 
        {
            case 1:
                cout << "Rock.\n\n";
                break;
            case 2:
                cout << "Paper.\n\n";
                break;
            case 3:
                cout << "Scissors.\n\n";
                break;
        }

        if (choice == random_choice) 
        {
            cout << " ---> It's a Tie !!! \n\n";
        }

        else if ((choice == 1 && random_choice == 3) || (choice == 2 && random_choice == 1) || (choice == 3 && random_choice == 2)) 
        {
            cout << " ---> You Win !!! \n\n";
        }

        else 
        {
            cout << " ---> Computer Wins !!! \n\n";
        }
    }    

    return 0;
}