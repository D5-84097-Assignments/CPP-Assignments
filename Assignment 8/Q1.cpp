#include<iostream>
using namespace std;

int calculateFactorial(int number)
{
    int fact =1;
    if (number < 0)
        throw -1;
    if (number == 0)
        return 1;
    fact = number * calculateFactorial(number-1);
    return fact;
}

int main()
{
    int number;
    int fact;
    try
    {
        cout<<"Enter a number:"<< endl;
        cin>> number;
        fact = calculateFactorial(number);
        cout<<"Factorial is ="<< fact<< endl;
    }
    catch(int e)
    {
        cout<<"Please Enter positive number"<<endl;
    }
    
    return 0;
}



// class Factorial
// {
// private:
//     int number;
//     int fact;
// public:
//     Factorial()
//     {
//         number = 0;
//         fact = 1;
//     }
//     Factorial(int number)
//     {
//         this->number = number;
//         this->fact = 1;
//     }
//     void setNumber(int number)
//     {
//         this->number = number;
//     }
//     int getNumber()
//     {
//         return number;
//     }
//     int calculateFactorial(int number)
//     {
//         if (number < 0)
//             throw -1;
//         if (number = 0)
//             return 1;
//         fact = number * calculateFactorial(number-1);
//         return fact;
//         // else 
//         //     return calculateFactorial(number);
//     }
//     // int calculateFactorial(int number)
//     // {
//     //     if (number = 0)
//     //         return 0;
//     //     fact = number * calculateFactorial(number-1);
//     //     return fact;
//     // }
//     // void display()
//     // {
//     //     cout<< "Factorial is ="<< fact << endl;
//     // }
// };


// int main1()
// {
//     int number;
//     cout<<"Enter a number:"<< endl;
//     cin>> number;
//     Factorial f;
//     try
//     {
//         cout<<"Factorial is: -"<< f.calculateFactorial(number)<< endl;
//     }
//     catch(int e)
//     {
//         cout<<"Please Enter positive number"<<endl;
//     }
//     //f.calculateFactorial(number);
//     //f.display();
    
//     return 0;
// }