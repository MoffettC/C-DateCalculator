#include <stdio.h>
#include <stdlib.h>

int displayMenu();

void getCalendarDate(int *calendarDay, int *calendarMonth, int *calendarYear);
void getJulianDate(int *julianDay, int *julianYear);
int toJulian(int calendarDay, int calendarMonth, int calendarYear);
void toCalendar(int julianDay, int julianYear, int *calendarDay, int *calendarMonth, int *calendarYear);
void daysBetweenDates(int *calendarDay, int *calendarMonth, int *calendarYear, int *calendarDay2, int *calendarMonth2,
	int *calendarYear2);
int isLeapYear(int year);

int main(void) {

	int choice;
	int calendarDay = 0, calendarMonth = 0, calendarYear = 0;
	int calendarDay2 = 0, calendarMonth2 = 0, calendarYear2 = 0;
	int julianDay = 0, julianYear = 0;
	int julianDate = 0, jDays = 0;


	while (1) {
		choice = displayMenu();
		if (choice == 1) {
			getCalendarDate(&calendarDay, &calendarMonth, &calendarYear);
			jDays = toJulian(calendarDay, calendarMonth, calendarYear);
			printf("\n(%d,     %d) Julian Date\n\n", jDays, calendarYear);
		}

		else if (choice == 2) {
			getJulianDate(&julianDay, &julianYear);
			toCalendar(julianDay, julianYear, &calendarDay, &calendarMonth, &calendarYear);
			printf("\n(%d/%d/%d) Calendar Date\n\n", calendarMonth, calendarDay, calendarYear);
		}

		else {
			printf("Please enter the starting calendar date:\n");
			getCalendarDate(&calendarDay, &calendarMonth, &calendarYear);
			printf("Please enter the ending calendar date:\n");
			getCalendarDate(&calendarDay2, &calendarMonth2, &calendarYear2);
			daysBetweenDates(&calendarDay, &calendarMonth, &calendarYear, &calendarDay2, &calendarMonth2, &calendarYear2);
		}
	}

	getchar(); getchar();
	return 0;
}

int displayMenu() {
	int chooseright = 0;
	int choice = -1;

	printf("\nDate Selection Menu\n\n");
	printf("1. Convert calendar date to Julian date\n");
	printf("2. Convert Julian date into calendar date\n");
	printf("3. Compute days between two calendar dates\n");
	printf("4. Exit program\n\n");

	do {

		printf("Please choose an option> ");
		scanf_s("%d", &choice);

		if (choice == 1) {
			chooseright = 1;
		}
		else if (choice == 2) {
			chooseright = 1;
		}
		else if (choice == 3) {
			chooseright = 1;
		}
		else if (choice == 4) {
			chooseright = 1;
			exit(1);
		}
		else {
			printf("Please enter a valid choice\n");
			chooseright = 0;
		}


	} while (chooseright == 0);

	return choice;

}

void getCalendarDate(int *calendarDay, int *calendarMonth, int *calendarYear) {
	printf("Enter the month> ");
	scanf_s("%d", calendarMonth);
	printf("Enter the day> ");
	scanf_s("%d", calendarDay);
	printf("Enter the year> ");
	scanf_s("%d", calendarYear);
}

int toJulian(int calendarDay, int calendarMonth, int calendarYear) {
	int leapCheck, days = 0;


	days = calendarDay;

	calendarMonth--;
	if (calendarMonth == 1) {
		days += 31;
	}
	if (calendarMonth == 2) {
		days += 59;
	}
	if (calendarMonth == 3) {
		days += 90;
	}
	if (calendarMonth == 4) {
		days += 120;
	}
	if (calendarMonth == 5) {
		days += 151;
	}
	if (calendarMonth == 6) {
		days += 181;
	}
	if (calendarMonth == 7) {
		days += 212;
	}
	if (calendarMonth == 8) {
		days += 243;
	}
	if (calendarMonth == 9) {
		days += 273;
	}
	if (calendarMonth == 10) {
		days += 304;
	}
	if (calendarMonth == 11) {
		days += 334;
	}


	if (calendarDay != 29) {
		leapCheck = isLeapYear(calendarYear);
		days += leapCheck;
	}

	return (days);
}

int isLeapYear(int year) {
	return ((!(year % 4) && year % 100) || !(year % 400));
}

void getJulianDate(int *julianDay, int *julianYear) {
	printf("Enter the day> ");
	scanf_s("%d", julianDay);
	printf("Enter the year> ");
	scanf_s("%d", julianYear);
}

void toCalendar(int julianDay, int julianYear, int *calendarDay, int *calendarMonth, int *calendarYear) {
	int leapCheck;

	*calendarYear = julianYear;

	leapCheck = isLeapYear(julianYear);


	if (julianDay <= 31) {
		*calendarDay = julianDay;
		*calendarMonth = 1;
	}
	else if ((31 < julianDay) && (julianDay <= 59)) {
		*calendarDay = julianDay - 31;
		*calendarMonth = 2;
	}
	else if ((julianDay == 60) && (leapCheck == 1)) {
		*calendarDay = julianDay - 31;
		*calendarMonth = 2;
	}
	else if ((59 < julianDay) && (julianDay <= 90)) {
		*calendarDay = julianDay - 59;
		*calendarMonth = 3;
	}
	else if ((90 < julianDay) && (julianDay <= 120)) {
		*calendarDay = julianDay - 90;
		*calendarMonth = 4;
	}
	else if ((120 < julianDay) && (julianDay <= 151)) {
		*calendarDay = julianDay - 120;
		*calendarMonth = 5;
	}
	else if ((151 <julianDay) && (julianDay <= 181)) {
		*calendarDay = julianDay - 151;
		*calendarMonth = 6;
	}
	else if ((181 < julianDay) && (julianDay <= 212)) {
		*calendarDay = julianDay - 181;
		*calendarMonth = 7;
	}
	else if ((212 < julianDay) && (julianDay <= 243)) {
		*calendarDay = julianDay - 212;
		*calendarMonth = 8;
	}
	else if ((243 < julianDay) && (julianDay <= 273)) {
		*calendarDay = julianDay - 243;
		*calendarMonth = 9;
	}
	else if ((273 < julianDay) && (julianDay <= 304)) {
		*calendarDay = julianDay - 273;
		*calendarMonth = 10;
	}
	else if ((304 < julianDay) && (julianDay <= 334)) {
		*calendarDay = julianDay - 304;
		*calendarMonth = 11;
	}
	else {
		*calendarDay = julianDay - 334;
		*calendarMonth = 12;
	}

}


void daysBetweenDates(int *calendarDay, int *calendarMonth, int *calendarYear, int *calendarDay2, int *calendarMonth2, int *calendarYear2) {
	int temp;
	int days = 0, addDays = 0;
	int i, leapCheck = 0;
	int startDay = 0, startMonth = 0, startYear = 0;
	int endDay = 0, endMonth = 0, endYear = 0;

	startDay = *calendarDay;
	startMonth = *calendarMonth;
	startYear = *calendarYear;

	endDay = *calendarDay2;
	endMonth = *calendarMonth2;
	endYear = *calendarYear2;

	//Computing if person switched dates
	if (startYear > endYear) {
		temp = endYear;
		endYear = startYear;
		startYear = temp;

		temp = endMonth;
		endMonth = startMonth;
		startMonth = temp;

		temp = endDay;
		endDay = startDay;
		startDay = temp;
	}

	if (startYear == endYear) {
		if (startMonth > endMonth) {
			temp = endMonth;
			endMonth = startMonth;
			startMonth = temp;

			temp = endDay;
			endDay = startDay;
			startDay = temp;
		}
		if (startMonth == endMonth) {
			if (startDay > endDay) {
				temp = endDay;
				endDay = startDay;
				startDay = temp;
			}
		}
	}

	//Day computation
	for (i = (startYear + 1); i < endYear; i++) {

		leapCheck = isLeapYear(i);
		if (leapCheck == 1) {
			days += 1;
		}

		days += 365;
	}


	toJulian(endDay, endMonth, endYear, &endDay, &endYear);
	days += endDay;

	toJulian(startDay, startMonth, startYear, &startDay, &startYear);
	days += (365 - startDay);


	printf("\n\nTotal Amount of Days: %d\n\n", days);

}