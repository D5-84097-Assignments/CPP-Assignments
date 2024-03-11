#include<iostream>
using namespace std;

class Stack
{
    private:
        int size;
        int top;
        int* arr;
        int number;
    public:
        // Stack()
        // {
        //     size = 5;
        //     top = -1;
        //     this->arr = new int[this->size];
        // }
        Stack(int size=5)
        {
            this->size = size;
            top = -1;
            this->arr = new int[this->size];
        }

        void push()
        {
            if (isFull() == true)
            {
                cout<<"Stack is full. Number cannot be pushed."<< endl;
            }
            else
            {
                cout<<"Enter the number to be Pushed"<< endl;
                cin>> number;
                ++top;
                arr[top] = number;
                cout<<"Number pushed"<< endl;
            }
        }

        void pop()
        {
            if (isEmpty() == true)
            {
                cout<<"Stack is already Empty. Cannot be Popped"<< endl;
            }
            else
            {
                top--;
                cout<<"Number popped successfully."<< endl;
            }
        }

        void peek() const
        {
            cout<<"Number on top is:"<< arr[top] << endl;
        }

        bool isEmpty() const
        {
            if (top == -1)
            {
                cout<<"Stack is Empty"<< endl;
                return true;
            }
            else
            {
                return false;
            }
        }

        bool isFull() const
        {
            if (top == size-1)
            {
                cout<<"Stack is full"<< endl;
                return true;
            }
            else
            {
                return false;
            }
        }

        void print()
        {
            cout<<"Numbers in the stack are: "<< endl;
            for(int i=top; i>=0; i--) 
            {
                cout << arr[i] << " , "<< endl;
            }
            cout<< endl;
        }

        ~Stack()
        {
            delete[] arr;
            arr = NULL;
        }
};

int main()
{
    int size, choice;
    Stack s1,s2(3);

    do
    {
        cout<<"Enter choice: 0.Exit     1.Push     2.Pop     3.Peek     4.Display Array"<< endl;
        cin>> choice;
        switch (choice)
        {
            case 0:
                break;
            case 1:
                s2.push();
                break;
            case 2:
                s2.pop();
                break;
            case 3:
                s2.peek();
                break;
            case 4:
                s2.print();
                break;
            default:
                cout<<"Enter correct choice."<< endl;
                break;
        }
    } while (choice != 0);
    
    return 0;
}