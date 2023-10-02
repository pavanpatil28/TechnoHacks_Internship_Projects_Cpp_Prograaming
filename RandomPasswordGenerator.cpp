#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

string generateRandomPassword(int length)
{
    const string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*";
    const int numCharacters = characters.length();
    string password;

    srand(static_cast<unsigned int>(time(nullptr)));

    for (int i = 0; i < length; ++i)
    {
        int randomIndex = rand() % numCharacters;
        password += characters[randomIndex];
    }

    return password;
}

int main()
{
    int passwordLength;
    char choice='y';

    cout<<"\n\n\t\t #####    Welcome to Random Password Generator Program    ##### \n\n";

    while (choice=='y')
    {  
       
        cout << "\n >> Enter the Desired Password Length = ";
        cin >> passwordLength;

        if (passwordLength <= 0)
        {
            cout << " ---> Invalid Password Length. !!! " << endl;
            return 1;
        }

        string password = generateRandomPassword(passwordLength);

        cout << "\n --> Generated Password is : " << password << endl;

        cout << "\n >> Want to Generate Password Again type (y) to continue : ";
        cin>>choice;
    }

    cout<<"\n\n ---> Random Password Generator Program Exited Successfully !!! \n\n\n";

    return 0;
}
