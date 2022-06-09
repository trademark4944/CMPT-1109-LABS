#include <iostream>
#include <string>
using namespace std;

bool checkLeapYear(int year) {

	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0) {
				return true;
			}
			return false;
		}
		return true;
	}
	else {
		return false;
	}
}

void printDates(int weekDayStart, string month) {
	int dayCount = 1;
	int calendarDates[5][7];

	for (int rows = 0; rows < 5; rows++) {
		for (int cols = 0; cols < 7; cols++) {
			if (rows == 0 && cols < weekDayStart) {
				calendarDates[rows][cols] = 0;
			}
			else { 
                                 calendarDates[rows][cols] = dayCount;
                                 dayCount++;
			         if (dayCount > 31) {
				     break;
				 }
			}
		}
		if (dayCount > 31) {
			break;
		}
	}

	dayCount = 1;
	cout << month << endl << endl;
	cout << "SUN \t MON  \t  TUE \t WED \t THU \t FRI \t SAT" << endl;

	for (int rows = 0; rows < 5; rows++) {
		for (int cols = 0; cols < 7; cols++) {
                        if (calenderDates[rows][cols] == 0) {
				cout << " ";
                        }
			else {
				cout << calendarDates[rows][cols];
				dayCount++;
			}
			cout << '\t' << " ";
			
			if (dayCount > 31) {
				break;
			}
		}
		cout << endl;
		if (dayCount > 31) {
			break;
		}
	}
}


//array[rows][cols]
void generateMonth(int monthLength, int monthcount, int weekDayStart) {
	string month;
	if (monthcount == 1) {
		month = "January";
		printDates(weekDayStart, month);
	}
}

int main() {
	int year, januaryFirst, monthLength = 1, monthCount = 1;
	bool leapYear, idiotProofing = true;

	cout << "Enter the year for which you wish to generate the calendar: ";
	cin >> year;
	
	while (idiotProofing == true) {
		cout << "------------------------------------------------------------" << endl;
		cout << "0. Sunday" << endl << "1. Monday" << endl << "2. Tuesday" << endl << "3. Wednesday" << endl << "4. Thursday" << endl << "5. Friday" << endl << "6. Saturday" << endl;
		cout << "------------------------------------------------------------" << endl;
		cout << "Enter the day of the week that January first is on: ";
		cin >> januaryFirst;
		cout << "------------------------------------------------------------" << endl;

		if (januaryFirst > 7 || januaryFirst < 1) {
			cout << "ERROR: Invalid Input" << endl;
		}
		else {
			idiotProofing = false;
		}
	}

	leapYear = checkLeapYear(year);
	
	cout << "Calendar for " << year << endl << endl;

	generateMonth(monthLength, monthCount, januaryFirst);

	/*
	for (int monthCount = 1; monthCount <= 12; monthCount++) {
		if (monthCount == (1 || 3 || 5 || 7 || 8 || 10 || 12)) {
			monthLength == 31;
		}
		else if (monthCount == 2) {
			if (leapYear == true) {
				monthLength = 29;
			}
			else if (leapYear == false) {
				monthLength = 28;
			}
		}
		else {
			monthLength = 30;
		}

		generateMonth(monthLength, monthCount);
	} */

	return 0;
}
