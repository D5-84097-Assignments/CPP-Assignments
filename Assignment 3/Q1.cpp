#include<iostream>
using namespace std;

class Time
{
    private:
        int hour;
        int minute;
        int second;
    public:
        Time()
        {
            hour = 0;
            minute = 0;
            second = 0;
        }
        Time(int hour, int minute, int second)
        {
            this->hour = hour;
            this->minute = minute;
            this->second = second;
        }
        int getHour()
        {
            return hour;
        }
        int getMinute()
        {
            return minute;
        }
        int getSecond()
        {
            return second;
        }
        void printTime()
        {
            cout<<"Time is - "<< getHour() << " : " << getMinute() << " : " << getSecond() << endl;
        }
        void setHour(int hour)
        {
            this->hour = hour;
        }
        void setMinute(int minute)
        {
            this->minute = minute;
        }
        void setSecond(int second)
        {
            this->second = second;
        }
};


int main()
{
    Time *ptr = new Time[2]{Time(), Time(12,15,18)};

    ptr[0].printTime();

    ptr[0].setHour(10);
    ptr[0].setMinute(10);
    ptr[0].setSecond(10);
    ptr[0].printTime();

    ptr[1].printTime();

    ptr[1].setHour(20);
    ptr[1].setMinute(20);
    ptr[1].setSecond(20);
    ptr[1].printTime();

    delete[] ptr;
    ptr = NULL;

    return 0;
}