#include<stdio.h>

struct Date
{
    int day;
    int month;
    int year;
};

void initDate(struct Date *ptrDate)
{
    ptrDate->day = 26;  
    ptrDate->month = 11; 
    ptrDate->year = 2008; 
    printf("Date is:%d-%d-%d\n", ptrDate->day, ptrDate->month, ptrDate->year);
}
void printDateOnConsole(struct Date *ptrDate)
{
    printf("Date is:%d-%d-%d\n", ptrDate->day, ptrDate->month, ptrDate->year);
}

void acceptDateFromConsole(struct Date *ptrDate)
{
    printf("Enter day, month and year.\n");
    scanf("%d%d%d", &ptrDate->day, &ptrDate->month, &ptrDate->year);
}

int main()
{
    struct Date d1;
    int choice;
    do 
    {
        printf("Enter a choice: 0.Exit \n 1.Initialization automatically \n 2.Print Date \n 3.Accept Date from user \n");
        scanf("%d", &choice);
    
        switch(choice)
        {
            case 1:
                initDate(&d1);
                break;
            case 2:
                printDateOnConsole(&d1);
                break;
            case 3:
                acceptDateFromConsole(&d1);
                break;
        }
    } while(choice != 0);
    return 0;
}