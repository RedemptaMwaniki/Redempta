#include <stdio.h>

int main() {
    int month, year, daysInMonth, startingDay;

    // Get input from user
    printf("Enter month (1-12): ");
    scanf("%d", &month);
    printf("Enter year: ");
    scanf("%d", &year);

    // Determine the number of days in the month
    if (month == 2) {
    	//checks if the year is a leap year
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            daysInMonth = 29;
        } else {
            daysInMonth = 28;
        }
    //ensures the rest of the months have 30 or 31 days
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        daysInMonth = 30;
    } else {
        daysInMonth = 31;
    }

    // Determine the starting day of the month
    int startingDayOfWeek = 1;
    int totalDays = 0;
    int y;
    for (y = 1; y < year; y++) {
        if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
            totalDays += 366;
        } else {
            totalDays += 365;
        }
    }
    int m;
    for (m = 1; m < month; m++) {
        if (m == 2) {
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                totalDays += 29;
            } else {
                totalDays += 28;
            }
        } else if (m == 4 || m == 6 || m == 9 || m == 11) {
            totalDays += 30;
        } else {
            totalDays += 31;
        }
    }
    startingDay = (startingDayOfWeek + totalDays % 7) % 7;

    // Print the calendar header
    printf("\n   Month: %d, Year: %d\n", month, year);
    printf(" Sun Mon Tue Wed Thu Fri Sat\n");

    // Print the calendar
    int i;
    for (i = 0; i < startingDay; i++) {
        printf("    ");
    }
    int z;
    for (z = 1; z <= daysInMonth; z++) {
        if (z < 10) {
            printf("   %d", z);
        } else {
            printf("  %d", z);
        }
        if ((z + startingDay) % 7 == 0 || z == daysInMonth) {
            printf("\n");
        }
    }

    return 0;
}


