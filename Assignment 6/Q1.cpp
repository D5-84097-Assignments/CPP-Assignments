#include<iostream>
using namespace std;

class Employee
{
    private:
        int id;
        float salary;
    public:
        Employee()
        {
            id = 0;
            salary = 0; 
        }
        Employee(int id, float salary)
        {
            this->id = id;
            this->salary = salary;
        }
        void setId(int id)
        {
            this->id = id;
        }
        void setSalary(float salary)
        {
            this->salary = salary;
        }
        int getId()
        {
            return id;
        }
        float getSalary()
        {
            return salary;
        }
        virtual void accept()
        {
            cout<<"Enter Id -"<< endl;
            cin>> id;
            cout<<"Enter Salary -"<< endl;
            cin>> salary;
        }
        virtual void display()
        {
            cout<<"Id - "<< id << endl;
            cout<<"Salary - "<< salary << endl;
        }
        virtual ~Employee()
        {

        }
};

class Manager: virtual public Employee
{
    private:
        float bonus;
    public:
        Manager()
        {
            bonus = 0; 
        }
        Manager(int id, float salary, float bonus)
        {
            this->setId(id);
            this->setSalary(salary);
            this->bonus = bonus;
        }
        void setBonus(float bonus)
        {
            this->bonus = bonus;
        }
        float getBonus()
        {
            return bonus;
        }
        void accept()
        {
            Employee::accept();
            this->acceptManagar();
            
        }
        void acceptManagar()
        {
            cout<<"Enter Bonus -"<< endl;
            cin>> bonus;
        }
        void display()
        {
            Employee::display();
            this->displayManager();
            //cout<<"Salary after bonus - "<< salary + bonus << endl;
        }
        void displayManager()
        {
            cout<<"Bonus - "<< bonus << endl;
            //cout<<"Salary after bonus - "<< salary + bonus << endl;
        }
};

class Salesman: virtual public Employee
{
    private:
        float commission;
    public:
        Salesman()
        {
            commission = 0; 
        }
        Salesman(int id, float salary, float commision)
        {
            this->setId(id);
            this->setSalary(salary);
            this->commission = commision;
        }
        void setCommission(float commission)
        {
            this->commission = commission;
        }
        float getCommission()
        {
            return commission;
        }
        void accept()
        {
            Employee::accept();
            this->acceptSalesman();
            
        }
        void acceptSalesman()
        {
            cout<<"Enter Commission -"<< endl;
            cin>> commission;
        }
        void display()
        {
            Employee::display();
            this->displaySalesman();
            //cout<<"Salary after commission - "<< salary + commission << endl;
        }
        void displaySalesman()
        {
            cout<<"Commission - "<< commission << endl;
            //cout<<"Salary after commission - "<< salary + commission << endl;
        }
};

class SalesManager: public Manager, public Salesman
{
    public:
        SalesManager(){}
        SalesManager(int id, float salary, float bonus, float commission)
        {
            this->setId(id);
            this->setSalary(salary);
            this->setBonus(bonus);
            this->setCommission(commission);
        }
        void accept()
        {
            // Employee::accept();
            // acceptManagar();
            // acceptSalesman();
            accept();
            setCommission(50.50);
        }
        void display()
        {
            display();
            cout<<"Commission - "<< getCommission()<< endl;
        }
};

int main()
{
    // Manager *manager = new SalesManager();
    // SalesManager *sales_manager = dynamic_cast<sales_manager *>(Manager);
    SalesManager e;
    e.accept();
    e.display();
    

    

    return 0;
}