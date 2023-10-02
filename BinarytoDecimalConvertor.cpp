#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int BinarytoDecimal(string binaryinput)
{
    int decimaloutput = 0;

    for (int i = 0, j = binaryinput.length()-1 ; i < binaryinput.length() && j >= 0; i++, j--)
    {   
        decimaloutput += (binaryinput[j] - 48) * pow(2,i); 
    }

    return decimaloutput;
}

int main()
{
    string binaryinput;
    char choice='y';

    cout<<"\n\n\t\t #####    Welcome to Binary to Decimal Conversion  Program    ##### \n\n";

    while (choice=='y')
    {  
        bool flag = 0;

        cout<<"\n >> Enter the Binary No = ";
        cin>>binaryinput;

        for(int i=0; i < binaryinput.length() ; i++)
        {
            if(binaryinput[i] != '0' && binaryinput[i] != '1')
            {
                cout<<"\n\n ---> Enter a Valid Binary Number !!! \n\n";
                flag = 1;
            }
        }

        if (flag == 1)
        {
            flag = 0;
            continue;
        }
        
        cout << "\n --> Binary No : "<<binaryinput<<" to Decimal No is : " << BinarytoDecimal(binaryinput) << endl;    

        cout << "\n >> Want to Convert Again type (y) to continue : ";
        cin>>choice;
    }

    cout<<"\n\n ---> Random Binary to Decimal Conversion Program Exited Successfully !!! \n\n\n";

    return 0;
}
