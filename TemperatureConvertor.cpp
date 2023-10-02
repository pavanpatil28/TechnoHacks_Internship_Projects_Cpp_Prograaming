#include <iostream>
using namespace std;

class TemperatureConvertor
{
    public:
        double fahrenheitToCelsius(double fahrenheit);
        double celsiusToFahrenheit(double celsius);
};

double TemperatureConvertor :: fahrenheitToCelsius(double fahrenheit) 
{
    return (fahrenheit - 32) * 5.0 / 9.0;
}

double TemperatureConvertor :: celsiusToFahrenheit(double celsius) 
{
    return (celsius * 9.0 / 5.0) + 32;
}

int main() 
{
    TemperatureConvertor obj;
    double temperature;
    int choice;

    cout<<"\n\n \t\t ##### Welcome To Temperature Conversion Program ##### \n\n";

    while(1)
    {
        cout << "\n >>> Temperature Conversion Choices :- \n\n";
        cout << " 1] Fahrenheit to Celsius. \n";
        cout << " 2] Celsius to Fahrenheit. \n";
        cout << " 3] Exit Temperature Convertor. \n\n";
        cout << " >> Enter Your Choice :: ";
        cin >> choice;

        if(choice==3)
        {
            cout<<"\n ---> Temperature Convertor Exited Successfully !!! \n\n";
            break;
        }

        if (choice != 1 && choice != 2 && choice != 3) {
            cout << "\n ---> Invalid choice. Please select 1 or 2. !!! \n\n";
            continue;
        }

        if (choice == 1) 
        {
            cout << "\n >> Enter Temperature in Fahrenheit = ";
            cin >> temperature;
            cout << "\n --> Temperature in Celsius : " << obj.fahrenheitToCelsius(temperature) << " Degree Celsius. \n";
        } 

        else 
        {
            cout << "\n >> Enter Temperature in Celsius = ";
            cin >> temperature;
            cout << "\n --> Temperature in Fahrenheit : " << obj.celsiusToFahrenheit(temperature) << " Degree Fahrenheit. \n";
        }
    }

    return 0;
}
