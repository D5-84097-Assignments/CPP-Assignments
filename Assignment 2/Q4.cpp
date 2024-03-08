#include<iostream>
using namespace std;

class Address
{
    private:
        string building;
        string street;
        string city;
        int pin;
    public:
        Address()
        {
            building ="Sunflower tower";
            street = "S.V.Road";
            city = "Pune";
            pin = 000001;
        }
        Address(string building, string street, string city, int pin)
        {
            this->building = building;
            this->street = street;
            this->city = city;
            this->pin = pin;
        }
        void accept()
        {
            cout<<"Enter building, street, city and pin of an address." << endl;
            cin>> building >> street >> city >> pin;
        }
        void display()
        {
            cout<<"Address is:" << endl << "Building- " << building << endl << "Street- " << street << endl << "City- " << city << endl << "Pin- " << pin <<endl;
        }
        // string get_building()
        // {
        //     return building;
        // }
        // string get_street()
        // {
        //     return street;
        // }
        // string get_city()
        // {
        //     return city;
        // }
        // int get_pin()
        // {
        //     return pin;
        // }
        // void set_building(string building)
        // {
        //     this->building = building;
        // }
        // void set_street(string street) 
        // {
        //     this->street = street;
        // }
        // void set_city(string city)
        // {
        //     this->city = city;
        // }
        // void set_pin(int pin)
        // {
        //     this->pin = pin;
        // }
};

int main()
{
    Address a1;
    a1.display();
    

    Address a2("Building No. 22","S.B.Road","Pune",414002);
    a2.display();
    
    return 0;
}