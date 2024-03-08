#include<iostream>
using namespace std;

class tollbooth
{
    private:
        unsigned int no_of_cars;
        float cash_total;
        unsigned int paying_car_count;
        unsigned int non_paying_car_count;
    public:
        tollbooth()
        {
            no_of_cars = 0;
            cash_total = 0.0;
            paying_car_count = 0;
            non_paying_car_count = 0;
        }
        void payingCar()
        {
            paying_car_count++;
            cash_total += 0.50;
        }
        void nopayCar()
        {
            non_paying_car_count++;
        }
        void printOnConsole()
        {
            no_of_cars = paying_car_count + non_paying_car_count;
            cout<<"Total no. of cars passed by tollbooth are:" << no_of_cars << endl;
            cout<<"Total no. of paying cars are:" << paying_car_count << endl;
            cout<<"Total no. of non-paying cars are:" << non_paying_car_count << endl;
            cout << "Total cash collected - " << cash_total << endl;
        }
};
int main()
{
    int choice;
    bool car_choice;
    tollbooth t1;
    do
    {
        cout<<"Press: 0.For exit 1.Add car 2.Print data" << endl;
        cin>>choice;
        switch (choice)
        {
            case 1:
                cout<<"Does car paid toll? 1.Yes / 0.No" << endl;
                cin>>car_choice;
                if (car_choice == 1)
                {
                    t1.payingCar();
                }
                else
                    t1.nopayCar();
                break;
            case 2:
                t1.printOnConsole();
                break;
        }
    } while (choice!=0);
    return 0;
}