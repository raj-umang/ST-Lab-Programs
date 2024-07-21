#include<stdio.h>
int check(int day,int month) {
    if((month == 4 || month == 6 || month == 9 || month == 11) && (day == 31)) {
        return 1;
    }
    else {
        return 0;
    }
}

int isleap(int year) {
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    int day, month, year, tomm_day, tomm_month, tomm_year;
    char flag;
    do {
        flag = 'y';
        printf("\n Enter the day, month and year in the format dd mm yyyy ");
        scanf("%d %d %d", &day, &month, &year);
        tomm_month = month;
        tomm_year = year;
        if(day < 1 || day > 31) {
            printf("\n value of day not in range 1...31\n");
            flag = 'n';
        }
        if(month < 1 || month > 12) {
            printf("\n value of month not in range 1..12\n");
            flag = 'n';
        }
        else if(check(day,month)) {
            printf("\n value of day not in range 1...31\n");
            flag = 'n';
        }
        if (year < 1812 || year > 2013) {
            if(day == 31 && month == 12 && year == 1811) {
                flag = 'y';
            }
            else {
                printf("\n value of year not in range 1812..2013\n");
                flag = 'n';
            }
        }
        if(month == 2) {
            if(isleap(year) && day > 29) {
                printf("\n invalid input date for leap year\n");
                flag = 'n';
            }
            else if(!(isleap(year)) && day > 28) {
                printf("\n invalid input date for not a leap year\n");
                flag = 'n';
            }
        }
    }while(flag == 'n');

    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:   
            if(day < 31) {
                tomm_day = day + 1;
            }
            else {
                tomm_day = 1;
                tomm_month = month + 1;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if(day < 30) {
                tomm_day = day + 1;
            }
            else {
                tomm_day = 1;
                tomm_month = month + 1;
            }
            break;
        case 12:
            if(day < 31) {
                tomm_day = day + 1;
            }
            else {
                if(year == 2013) {
                    printf("value of next year is out of bound 1812..2013");
                    tomm_year = year + 1;
                    tomm_day = 1;
                    tomm_month = 1;
                }
                else {
                    tomm_year = year + 1;
                    tomm_day = 1;
                    tomm_month = 1;
                }
            }
            break;
        case 2:
            if(day < 28) {
                tomm_day = day + 1;
            }
            else if(isleap(year) && day == 28) {
                tomm_day = day + 1;
            }
            else if(day == 28 || day == 29) {
                tomm_day = 1;
                tomm_month = 3;
            }
            break;
    }
    printf("\n next day is %d %d %d\n",tomm_day, tomm_month, tomm_year);
    return 0;
}
