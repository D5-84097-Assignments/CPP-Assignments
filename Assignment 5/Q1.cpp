#include<iostream>
using namespace std;

class Date
{
    private:
        int day;
        int month;
        int year;
    public:
        Date()
        {
            day = 01;
            month = 01;
            year = 2001;
        }
        Date(int day, int month, int year)
        {
            this->day = day;
            this->month = month;
            this->year = year;
        }
        int getDay()
        {
            return day;
        }
        int getMonth()
        {
            return month;
        }
        int getYear()
        {
            return year;
        }
        void setDay(int day)
        {
            this->day = day;
        }
        void setMonth(int month)
        {
            this->month = month;
        }
        void setYear(int year)
        {
            this->year = year;
        }
        void acceptDate()
        {
            cout<<"Enter date, month and year."<< endl;
            cin>> day >> month >> year;
        }
        void displayDate()
        {
            cout<<"Date is: " << day << "/" << month << "/" << year << endl;
        }
        bool isLeapYear()
        {
            if ((year%4 == 0 && year%100 != 0) || (year%400 == 0))
                return true;
            else    
                return false;
        }

};

class Person
{
    private:
        string name;
        string address;
        Date birthDate;
    public:
        Person()
        {
            name = "Amit";
            address = "Pune";
            birthDate = Date();
        }
        Person(string name, string address, int day, int month, int year)
        {
            this->name = name;
            this->address = address;
            this->birthDate = Date(day, month, year);
        }
        string getName()
        {
            return name;
        }
        string getAddress()
        {
            return address;
        }
        Date getBirthDate()
        {
            return birthDate;
        }
        void setName(string name)
        {
            this->name = name;
        }
        void setAddress(string address)
        {
            this->address = address;
        }
        void setBirthDate(int day, int month, int year)
        {
            birthDate.setDay(day);
            birthDate.setMonth(month);
            birthDate.setYear(year);
        }
        void acceptPerson ()
        {
            cout<<"Enter Name, Address, Birth date"<< endl;
            cin>> name >> address;
            birthDate.acceptDate();
        }
        void displayPerson()
        {
            cout<< "Name - "<< name << endl;
            cout << "Address - "<< address << endl;
            cout<< "Birth ";
            birthDate.displayDate();
        }
};

class Employee : public Person
{
    private:
        int id;
        float salary;
        string department;
        Date doj;
    public:
        Employee()
        {
            id = 100;
            salary = 10000;
            department = "Mech";
            doj = Date();
        }
        Employee(int id, float salary, string department, int day, int month, int year)
        {
            this->id = id;
            this->salary = salary;
            this->department = department;
            this->doj = Date(day, month, year);
        }
        int getId()
        {
            return id;
        }
        float getSalary()
        {
            return salary;
        }
        string getDepartment()
        {
            return department;
        }
        Date getDateOfJoining()
        {
            return doj;
        }
        void setId(int id)
        {
            this->id = id;
        }
        void setSalary(float salary)
        {
            this->salary = salary;
        }
        void setDepartment(string department)
        {
            this->department = department;
        }
        void setDateOfJoining(int day, int month, int year)
        {
            doj.setDay(day);
            doj.setMonth(day);
            doj.setYear(year);
        }
        void acceptEmployee()
        {
            cout<<"Enter Employee Id, salary, department and Date of joining"<< endl;
            cin >> id >> salary >> department;
            doj.acceptDate();
        }
        void displayEmployee()
        {
            cout<< "Id - " << id << endl;
            cout<< "Salary - " << salary << endl;
            cout<< "Department - " << department << endl;
            cout<< "Joining ";
            doj.displayDate();
        }

};

int main()
{
    Person p;
    p.displayPerson();

    Person p1("Rakesh", "Banglore", 30, 3, 2023);
    p1.displayPerson();

    Employee e1;
    e1.displayEmployee();

    Employee e2(1001, 20000, "IT", 14, 7, 2024);
    e2.displayEmployee();
    
    return 0;
}