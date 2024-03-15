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
        salary = 0.0;
    }
    Employee(int id,float salary)
    {
        this->id = id;
        this->salary = salary;
    }
    void setID(int id)
    {
        this->id = id;
    }
    int getID()
    {
        return id;
    }
    void setSalary(int salary)
    {
        this->salary = salary;
    }
    int getSalary()
    {
        return salary;
    }
    virtual void accept()
    {
        cout << "Enter Employee ID: "<< endl;
        cin >> id;
        cout << "Enter Salary:"<< endl;
        cin >> salary;
    }
    virtual void display()
    {
        cout << "ID: " << id << endl;
        cout << "Salary: " << salary << endl;
    }
    virtual ~Employee()
    {

    }
};

class Manager:virtual public Employee
{
private:
    float bonus;
protected:
    void accept_manager()
    {
        cout << "Enter Bonus: "<< endl;
        cin >> bonus;
    }
    void display_manager()
    {
        cout << "Bonus: " << bonus << endl;
    }
public:
    Manager()
    {
        bonus = 0.0;
    }
    Manager(int id,float salary,float bonus)
    {
        this->setID(id);
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
        this->accept_manager();
    }
    void display()
    {
        Employee::display();
        this->display_manager();
    }
    ~Manager(){}
};

class Salesman:virtual public Employee
{
private:
    float commission;
protected:
    void accept_salesman()
    {
        cout << "Enter Commission: "<< endl;
        cin >> commission;
    }
    void display_salesman()
    {
        cout << "Commission: " << commission << endl;
    }
public:
    Salesman()
    {
        commission = 0.0;
    }
    Salesman(int id, float salary,float commission)
    {
        this->setID(id);
        this->setSalary(salary);
        this->commission = commission;
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
        this->accept_salesman();
    }
    void display()
    {
        Employee::display();
        this->display_salesman();
    }
    ~Salesman(){}
};

class Salesmanger:public Manager,public Salesman
{
public:
    Salesmanger(){}
    Salesmanger(int id,float salary,float bonus,float comm)
    {
        this->setID(id);
        this->setSalary(salary);
        this->setBonus(bonus);
        this->setCommission(comm);
    }
    void accept()
    {
        Employee::accept();
        accept_manager();
        accept_salesman();
    }
    void display()
    {
        Employee::display();
        display_manager();
        display_salesman();
    }
};


int menu(int choice)
{
    cout << "0.EXIT." << endl;
    cout << "1.Accept Employee" << endl;
    cout << "2.Accept Manager" << endl;
    cout << "3.Accept Sale-Man" << endl;
    cout << "4.Accept SalesManagers" << endl;
    cout << "5.Display all employees" << endl;
    cout << "6.Display Manager" << endl;
    cout << "7.Display Sales-Man" << endl;
    cout << "8.Display SalesManger" << endl;
    cout << "9.Count of all employees with respect to designation." << endl;

    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}


int main()
{
    int choice, size, count = 0, mcount=0, scount=0, smcount=0;
    cout << "Enter Number of Employees:" << endl;
    cin >> size;
    Employee *eptr[size];

    while ((choice = menu(choice)) != 0)
    {
        switch (choice)
        {
            case 1:
                if (count < size)
                {
                    eptr[count] = new Employee();
                    eptr[count]->accept();
                    count++;
                }
                else
                    cout << "Employee Data is full." << endl;
                break;

            case 2:
                if (count < size)
                {
                    eptr[count] = new Manager();
                    eptr[count]->accept();
                    count++;
                    mcount++;
                }
                else
                    cout << "Manager data is full." << endl;
                break;

            case 3:
                if (count < size)
                {
                    eptr[count] = new Salesman();
                    eptr[count]->accept();
                    count++;
                    scount++ ;
                }
                else
                    cout << "Salesman data is full." << endl;
                break;

            case 4:
                if (count < size)
                {
                    eptr[count] = new Salesmanger();
                    eptr[count]->accept();
                    count++;
                    smcount++;
                }
                else
                    cout << "Sales Manager data is full." << endl;
                break;

            case 5:
                for (int i = 0; i < count;i++)
                {
                    if(typeid(*eptr[i]) == typeid(Employee))
                    {
                        eptr[i]->display();
                    }
                }
                break;

            case 6:
                for (int i = 0; i < count;i++)
                {
                    if(typeid(*eptr[i])==typeid(Manager))
                    {
                        eptr[i]->display();
                    }
                }
                break;

            case 7:
                for (int i = 0; i < count;i++)
                {
                    if(typeid(*eptr[i])==typeid(Salesman))
                    {
                        eptr[i]->display();
                    }
                }
                break;

            case 8:
                for (int i = 0; i < count;i++)
                {
                    if(typeid(*eptr[i])==typeid(Salesmanger))
                    {
                        eptr[i]->display();
                    }
                }
                break;
            case 9:
                cout << "Employee Count: " << count << endl;
                cout << "Manager Count: " << mcount << endl;
                cout << "Salesman Count: " << scount << endl;
                cout << "Sales-Manager Count: " << smcount << endl;
                break;
            default:
                cout << "Wrong choice." << endl;
                break;
        }
}

    for (int i = 0; i < count; i++)
    {
        eptr[i];
    }

    return 0;
}