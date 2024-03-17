#include <iostream>
using namespace std;

class InsufficientFunds
{
    int accountId;
    double balance;
    double withdrawAmnt;

public:
    InsufficientFunds(int accountId, double balance, double withdrawAmnt)
    {
        this->accountId = accountId;
        this->balance = balance;
        this->withdrawAmnt = withdrawAmnt;
    }
    void display()
    {
        cout << "Account " << accountId << " has insufficient funds" << endl;
        cout << "Balance: " << balance << " Withdraw amount: " << withdrawAmnt << endl;
    }
};

typedef enum account_type
{
    SAVING = 1,
    CURRENT,
    DMAT
} account_type;

class Account
{
    int id;
    account_type type;
    double balance;

public:
    Account()
    {
        id = 0;
        type = SAVING;
        balance = 0;
    }

    Account(int id, account_type type, double balance)
    {
        this->id = id;
        this->balance = balance;
        this->type = type;
    }

    // Setters
    void setId(int id)
    {
        this->id = id;
    }
    void setType(account_type type)
    {
        this->type = type;
    }

    // Getters
    int getId()
    {
        return id;
    }
    int getType()
    {
        return type;
    }
    int getBalance()
    {
        return balance;
    }

    // Accept
    void accept()
    {
    acceptacc:
        cout << "1. Savings \n2. Current \n3. DMAT" << endl;
        cout << "Enter account type: ";
        int num;
        cin >> num;
        switch (num)
        {
        case SAVING:
            type = SAVING;
            break;
        case CURRENT:
            type = CURRENT;
            break;
        case DMAT:
            type = DMAT;
            break;
        default:
            cout << "Invalid choice" << endl;
            goto acceptacc;
            break;
        }
    }

    // Display
    void display()
    {
        cout << "\nAccount id: " << id << endl;
        cout << "Account type: ";
        switch (type)
        {
        case SAVING:
            cout << "Saving" << endl;
            break;
        case CURRENT:
            cout << "Current" << endl;
            break;
        case DMAT:
            cout << "DMAT" << endl;
            break;
        default:
            break;
        }
        cout << "Balance: " << balance << endl;
    }

    // Deposit
    void deposit(int amount)
    {
        if (amount < 0)
            throw 0;
        balance += amount;
    }

    // Withdraw
    void withdraw(double amount)
    {
        if (amount < 0)
            throw 0;
        if (amount > balance)
            throw InsufficientFunds(id, balance, amount);
        balance -= amount;
    }
};

int menu()
{
    int choice;
    cout << "\n0. End Menu" << endl;
    cout << "1. Deposit" << endl;
    cout << "2. Withdraw" << endl;
    cout << "3. Display account details" << endl;
    cout << "4. Display balance" << endl;
    cout << "Enter a choice: ";
    cin >> choice;
    return choice;
}

int main()
{
    int choice;

    Account *accounts = new Account[5];
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter details for account no. " << i + 1 << endl;
        accounts[i].setId(i + 1);
        accounts[i].accept();
    }

    int index, amount;
    while (choice = menu())
    {

        try
        {
            if (choice >= 1 && choice <= 4)
            {
                cout << "\nEnter account id: ";
                cin >> index;
                if (index < 1 || index > 5)
                    throw 'c';
            }
            if (choice == 1 || choice == 2)
            {
                cout << "Enter amount: ";
                cin >> amount;
            }
            switch (choice)
            {
            case 1:
                accounts[index - 1].deposit(amount);
                break;
            case 2:
                accounts[index - 1].withdraw(amount);
                break;
            case 3:
                accounts[index - 1].display();
                break;
            case 4:
                cout << "\nBalance : " << accounts[index - 1].getBalance() << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
            }
        }
        catch (InsufficientFunds &e)
        {
            e.display();
        }
        catch (int e)
        {
            cout << "Amount cannot be negative" << endl;
        }
        catch (char e)
        {
            cout << "Account id dosent exist" << endl;
        }
    }
    cout << "... Thank you" << endl;
    delete[] accounts;

    return 0;
}