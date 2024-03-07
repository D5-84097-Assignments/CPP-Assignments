#include<iostream>
using namespace std;

struct Date
{
    int day;
    int month;
    int year;

    void initDate()
    {
        day = 26;
        month = 11;
        year = 2008;
        cout<<"Date is:" << day << "-" << month << "-" << year << endl;

    }
    void printDateOnConsole()
    {
        cout<<"Date is:" << day << "-" << month << "-" << year << endl;
    }
    void acceptDateFromConsole()
    {
        cout<<"Enter day, month and year."<<endl;
        cin>> day >> month >> year;
    }
    bool isLeapYear()
    {
        if (year%4 == 0)
        {
            if(year%100 == 0)
            {
                if(year%400 ==0)
                    return 1;
                else    
                    return 0;
            }
            else
                return 1;
        }
        else 
            return 0;
    }
};

int main()
{
    int choice;
    struct Date d1;
    do
    {
        cout<<"Enter a choice: 0.Exit" << endl << "1.Initialize date automatically" << endl << "2.Print Date" << endl << "3.Accept Date" << endl << "4.To check if year is a leap year" << endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                d1.initDate();
                break;
            case 2:
                d1.printDateOnConsole();
                break;
            case 3:
                d1.acceptDateFromConsole();
                break;
            case 4:
                if (d1.isLeapYear() == 1)
                cout<<"Entered year is leap year"<<endl;
                else
                cout<<"Entered year is not leap year"<<endl;
                break;
        }
    } while (choice != 0);
    return 0;
}