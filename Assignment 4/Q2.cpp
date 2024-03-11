#include<iostream>
using namespace std;

class Student
{
    private:
        string name;
        string gender;
        int roll_number;
        int marks1, marks2, marks3;
    public:
        Student(string name, string gender, int roll_number, int marks1,int marks2, int marks3)
        {
            this->name = name;
            this->gender = gender;
            this->roll_number = roll_number;
            this->marks1 = marks1;
            this->marks2 = marks2;
            this->marks3 = marks3;
        }
        void acceptStudentDetails()
        {
            cout<<"Enter student name, gender,roll no. and marks of 3 subjects."<< endl;
            cin>> name >> gender >> roll_number >> marks1 >> marks2 >> marks3;
        }
        void calculatePercentage()
        {
            int percentage = (marks1 + marks2 + marks3)/3;
            cout<< percentage;
        }
        void displayStudentDetails()
        {
            cout<< "Details of student are:"<< endl;
            cout<< "Name - " << name << endl;
            cout<< "Gender - "<< gender << endl;
            cout<< "Roll No. - "<< roll_number << endl;
            cout<< "Percentage - ";
            calculatePercentage();
            cout << "%" << endl;
        }
};

int main()
{
    // int count;
    // cout<<"Enter no. of students to be entered."<< endl;
    // cin>> count;
    Student *ptr = new Student[2]{Student("Amit","Male", 101, 60, 70, 80), Student("Sam","Female", 102, 70, 80, 90)};
    ptr->acceptStudentDetails();
    ptr->displayStudentDetails();
    (ptr+1)->displayStudentDetails();
    return 0;
}