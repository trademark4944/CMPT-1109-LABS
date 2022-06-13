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

/*int calculateWeekDayStart(int prevStartDay) {
	int newStartDay = 31, hold;

	newStartDay += prevStartDay;
	hold = newStartDay % 7;
	newStartDay /= 7;
	newStartDay + hold;

	return newStartDay;
}*/

void printDates(int weekDayStart, string month, int dayMax) {
	int dayCount = 1;
	int calendarDates[6][7];

	for (int rows = 0; rows < 6; rows++) {
		for (int cols = 0; cols < 7; cols++) {
			if (rows == 0 && cols < weekDayStart) {
				calendarDates[rows][cols] = 0;
			}
			else {
				calendarDates[rows][cols] = dayCount;
				dayCount++;
			}
			if (dayCount > dayMax) {
				break;
			}
		}
		if (dayCount > dayMax) {
			break;
		}
	}

	cout << endl << month << endl << endl;
	cout << "SUN \t MON  \t  TUE \t WED \t THU \t FRI \t SAT" << endl;

	dayCount = 1;
	for (int rows = 0; rows < 6; rows++) {
		for (int cols = 0; cols < 7; cols++) {
			if (calendarDates[rows][cols] == 0) {
				cout << " ";
			}
			else {
				cout << calendarDates[rows][cols];
				dayCount++;
			}
			cout << '\t' << " ";
			if (dayCount > dayMax) {
				break;
			}
		}
		if (dayCount > dayMax){
			break;
		}
		cout << endl;
	}
	cout << endl;
}


//array[rows][cols]
void generateMonth(int monthLength, int monthcount, int weekDayStart, bool isLeapYear) {
	string month;
	int dayMax = 0;
	switch (monthcount) {
	case 1:
		month = "January";
		dayMax = 31;
		break;
	case 2:
		month = "Febuary";
		if (isLeapYear == true) {
			dayMax = 29;
		}
		else {
			dayMax = 28;
		}
		break;
	case 3:
		month = "March";
		dayMax = 31;
		break;
	case 4:
		month = "April";
		dayMax = 30;
		break;
	case 5:
		month = "May";
		dayMax = 31;
		break;
	case 6:
		month = "June";
		dayMax = 30;
		break;
	case 7:
		month = "July";
		dayMax = 31;
		break;
	case 8:
		month = "August";
		dayMax = 31;
		break;
	case 9:
		month = "September";
		dayMax = 30;
		break;
	case 10:
		month = "October";
		dayMax = 31;
		break;
	case 11:
		month = "November";
		dayMax = 30;
		break;
	case 12:
		month = "Decemeber";
		dayMax = 31;
		break;
	}
	printDates(weekDayStart, month, dayMax);
}

int main() {
	int year, weekDayStart, monthLength = 1, dayMax;
	bool leapYear, idiotProofing = true;

	cout << "Enter the year for which you wish to generate the calendar: ";
	cin >> year;

	while (idiotProofing == true) {
		cout << "------------------------------------------------------------" << endl;
		cout << "0. Sunday" << endl << "1. Monday" << endl << "2. Tuesday" << endl << "3. Wednesday" << endl << "4. Thursday" << endl << "5. Friday" << endl << "6. Saturday" << endl;
		cout << "------------------------------------------------------------" << endl;
		cout << "Enter the day of the week that January first is on: ";
		cin >> weekDayStart;
		cout << "------------------------------------------------------------" << endl;

		if (weekDayStart > 7 || weekDayStart < 0) {
			cout << "ERROR: Invalid Input" << endl;
		}
		else {
			idiotProofing = false;
		}
	}

	leapYear = checkLeapYear(year);

	cout << "Calendar for " << year << endl;
	
	for (int i = 1; i <= 12; i++) {
		generateMonth(monthLength, i, weekDayStart, leapYear);
	}

	return 0;
}
