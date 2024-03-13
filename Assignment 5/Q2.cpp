#include<iostream>
using namespace std;

class Product
{
    private:
        int id;
        string title;
    protected:
        int price;
        int discounted_price;
    public:
        virtual void acceptProduct()
        {
            cout<<"Enter Id"<< endl;
            cin>> id;
            cout<<"Enter Title"<< endl;
            cin>> title;
            cout<<"Enter Price"<< endl;
            cin>> price;
        }
        virtual void displayProduct()
        {
            cout<<"Details are:"<< endl;
            cout<<"Id - "<< id << endl;
            cout<<"Title - "<< title << endl;
        }
        virtual int calculateDiscount()=0;
};

class Book : public Product
{
    private:
        string author;
    public:
        Book()
        {
            author = "";
        }
        void acceptProduct()
        {
            Product::acceptProduct();
            cout<<"Enter Author name:"<<endl;
            cin>> author;
        }
        void displayProduct()
        {
            Product::displayProduct();
            cout<<"Author - "<< author << endl;
        }
        int calculateDiscount()
        {
            discounted_price = 0.9* price;
            return discounted_price;
        }
};

class Tape: public Product
{
    private:
        string artist;
    public:
        Tape()
        {
            artist = "";
        }
        void acceptProduct()
        {
            Product::acceptProduct();
            cout<<"Enter Artist"<< endl;
            cin>> artist;
        }
        void displayProduct()
        {
            Product::displayProduct();
            cout<< "Artist - "<< artist << endl;
        }
        int calculateDiscount()
        {
            discounted_price = 0.95* price;
            return discounted_price;
        }
};

int main()
{
    int choice, size, count = 0, bill = 0;
    cout<<"Enter size of an array"<< endl;
    cin>> size;

    Product *product[size];
    while (choice != 0)
    {
        cout<<"Enter choice: 0.Exit            1.Enter Book details       2.Enter Tape details"<<endl;
        cout<<"              3.Display Books   4..Display Tapes           5.Display all Products"<<endl;
        cout<<"              6.Calculate Bill"<< endl;
        cin>>choice;
        switch(choice)
        {
            case 0:
                cout<<"Thank You...!"<<endl;
                break;
            case 1:
                if (count < size)
                {
                product[count] = new Book();
                product[count]->acceptProduct();
                count++;
                }
                else    
                    cout<<"Array is Full"<< endl;
                break;
            case 2:
                if (count < size)
                {
                product[count] = new Tape();
                product[count]->acceptProduct();
                count++;
                }
                else    
                    cout<<"Array is Full"<< endl;
                break;
            case 3:
                for(int i=0; i < count; i++)
                {
                    if((typeid(*product[i])) == (typeid(Book)))
                    {
                        product[i]->displayProduct();
                    }
                }
                break;
            case 4:
                for(int i=0; i < count; i++)
                {
                    if((typeid(*product[i]))==(typeid(Tape)))
                    {
                        product[i]->displayProduct();
                    }
                }
                break;
            case 5:
                for(int i=0; i<count; i++)
                {
                    product[i]->displayProduct();
                }
                break;
            case 6:
                for(int i=0; i< count; i++)
                {
                    if((typeid(*product[i])) == (typeid(Book)))
                    {
                        bill = bill + product[i]->calculateDiscount();
                    }
                    else
                    {
                        bill = bill + product[i]->calculateDiscount();
                    }
                }
                cout<<"Your bill is:"<< bill << endl;
                break;
            default:
                cout<<"Enter correct choice"<<endl;
        }
    }
    
    for(int i=0; i<count; i++)
    {
        delete product[i];
        product[i] = NULL;
    }

    return 0;
}