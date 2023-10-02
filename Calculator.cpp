#include<iostream>
using namespace std;

class Calculator
{
    // private:
    // /* data */

    public:
        float Addition(float x, float y);
        float Subtraction(float x, float y);
        float Multiplication(float x, float y);
        float Division(float x, float y);
};

float Calculator::Addition(float x, float y)
{
    return (x+y);  //returning the sum of two numbers.
}

float Calculator::Subtraction(float x, float y)
{
    return (x-y);  //returning the subtraction of two numbers.
}

float Calculator::Multiplication(float x, float y)
{
    return (x*y);  //returning the multiplication of two numbers.
}

float Calculator::Division(float x, float y)
{
    return (x/y);  //returning the division of two numbers.
}

int main()
{
    Calculator obj;
    int choice;
    float num1, num2;

    cout<<"\n\n\t\t #####    Calculator    ##### \n\n";
 
    while (true)
    {
        cout<<"\n # Basic Operations :- \n\n";
        cout<<" 1] Addition. \t\t 2] Subtraction. \n 3] Multiplication. \t 4] Division. \n 5] Exit Calculator. \n";
        cout<<"\n >> Enter the Operation No to be Performed :: ";
        cin>>choice;

        if(choice == 5)
        {
            cout<<"\n\n ---> Calculator Exited Successfully !!! \n\n\n";
            break;
            // Exit the loop;
        }

        cout<<"\n >> Enter No 1 = ";
        cin>>num1;
        cout<<"\n >> Enter No 2 = ";
        cin>>num2;

        switch (choice)
        {
            case 1:
                cout<<"\n --> Addition : "<<obj.Addition(num1, num2)<<endl<<endl;
                break;

            case 2:
                cout<<"\n --> Subtraction : "<<obj.Subtraction(num1, num2)<<endl<<endl;
                break;
            case 3:
                cout<<"\n --> Multipication : "<<obj.Multiplication(num1, num2)<<endl<<endl;
                break;
            case 4:
                cout<<"\n --> Division : "<<obj.Division(num1, num2)<<endl<<endl;
                break;
            
            default:
                break;
        }
    }
    

    return 0;
}