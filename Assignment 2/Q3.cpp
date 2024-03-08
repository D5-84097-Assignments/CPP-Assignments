#include<iostream>
using namespace std;

namespace NStudent
{
    class Student
    {
        private:
            int roll_no;
            string name;
            int marks;
        public:
            void initStudent()
            {
                roll_no = 69;
                name = "Amit";
                marks = 96;
                cout<<"Details of student are:" << endl << "Roll No. -" << roll_no << endl << "Name -" << name << endl << "Marks -" << marks << endl;
            }
            void printStudentOnConsole()
            {
                cout<<"Details of student are:" << endl << "Roll No. -" << roll_no << endl << "Name -" << name << endl << "Marks -" << marks << endl;
            }
            void acceptStudentFromConsole()
            {
                cout<<"Enter Roll No., Name and Marks of a student:"<<endl;
                cin>> roll_no >> name >> marks;
            }
    };
}
int main()
{
    int choice;
    NStudent::Student s1;
    do
    {
        cout<<"Please select: 0.Exit" << endl << "1.Initializing automatically" << endl << "2.Print student details" << endl << "3.Fill students details" << endl;
        cin>> choice;
        switch (choice)
        {
            case 1:
                s1.initStudent();
                break;
            case 2:
                s1.printStudentOnConsole();
                break;
            case 3:
                s1.acceptStudentFromConsole();
                break;
        }
    } while (choice != 0);
    return 0;    
}