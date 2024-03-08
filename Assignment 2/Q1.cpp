#include<iostream>
using namespace std;

class Box
{
    private:
        float length;
        float width;
        float height;
        float volume;
    public:
        Box()
        {
            length = 1;
            width = 1;
            height = 1;
        }
        Box(float length, float width, float height)
        {
            this->length = length;  
            this->width = width;
            this->height = height;
        }
        void getDimensions()
        {
            cout<<"Enter length, width and height of box." << endl;
            cin>> length >> width >> height;
        }
        void calculateVolume()
        {
            volume = length * width * height;
            cout<<"Volume of a box is: " << volume << endl;
        }
};

int main()
{
    int choice;
    Box b1;
    Box b2(4,5,6);
    do
    {
        cout<<"Enter choice:" << endl << "1.Print dimensions automatically" << endl << "2.Enter dimensions" << endl << "3.Calculate volume" << endl;
        cin>> choice;
        switch (choice)
        {
            case 1:
                b1.calculateVolume();
                break;
            case 2:
                b1.getDimensions();
                break;
            case 3:
                b1.calculateVolume();
                b2.calculateVolume();
                break;
        }
    } while (choice != 0);
    return 0;
}