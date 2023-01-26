
// CSCI 121 Project 05
// Author : Hyojin Park
// Date : 10-12-2020


#include <iostream>
using namespace std;


void testMenu();
// print out "Test Menu"

bool isValid(int year);
//postcondition: return true if given year is after 1582
bool isValid(int month, int year);
//postcondition: return true if specified month is between 1 and 12
bool isValid(int month, int day, int year);
//postcondition: return true if specified date is valid
bool isLeapYear(int year);
//postcondition: return true if given year is leap year
bool dayValid(int day);
//postcondition: return if specified number between 0 and 6

int getCenturyValue(int year);//follow book's instruction
int getYearValue(int year);//follow book's instruction
int getMonthValue(int month, int year);//follow book's instruction
int dayOfWeek(int month, int day, int year);//follow book's instruction

std::string dayOfWeek(int day);//follow book's instruction



int main()
{

    int choice;
    int day, month, year;
    
    do
    {

        testMenu();//dieplay menu by calling testMenu function
        cout << "Please choose from menu: ";
        cin >> choice;
        switch (choice)
        {
            case 1: //check if a given year is leap year
                cout << "Please enter a year: ";
                cin >> year;
                while(!isValid(year))//Check if it is a valid year
                {
                    cout << "This year is NOT valid. Please enter a year after 1582:\n";
                    cin >> year;
                }
                if(isLeapYear(year))
                    cout << "Year " << year << " is a leap year" << endl;
                else
                    cout << "Year " << year << " is NOT a leap year" << endl;
                
                break;
            
            case 2: // calculate the century value of a given year
                cout << "Please enter a year: ";
                cin >> year;
                 while(!isValid(year))//Check if it is a valid year
                 {
                     cout << "This year is NOT valid. Please enter a year after 1582:\n";
                     cin >> year;
                 }
                 cout << "The century value is: " << getCenturyValue(year) << endl;

                break;
                
            case 3: //calculate the year value if a given year
                cout << "Please enter a year: ";
                cin >> year;
                 while(!isValid(year))//Check if it is a valid year
                 {
                     cout << "This year is NOT valid. Please enter a year after 1582:\n";
                     cin >> year;
                 }
                cout << "The year value is: " << getYearValue(year) << endl;
                break;
                
            case 4: // calculate the month value of a given month in a given year
                cout << "Please enter a year and month: ";
                cin >> year >> month;
                while(!isValid(month, year))//Check if these are a valid year and month
                {
                    cout <<"This is NOT valid. Enter the number 1-12 for month, and after 1582 for year:\n";
                    cin >> year>> month;
                }
                cout << "The month value is: "<< getMonthValue(month, year) << endl;
                break;
                
            case 5: // calculate the day of week if a given date
                cout << "Please enter a year, a month, and a day: ";
                cin >> year >> month >> day;
                while(!isValid(month, day, year))
                    //Check if these are a valid ,month, day
                {
                    cout <<"This is NOT Valid day. Please enter carefully: \n";
                    cin >> year >> month >> day;
                }
                cout << "The day of the week is: " << dayOfWeek(month, day, year) << endl;
                break;
                
            case 6: //print out the name of a given day of week
                cout << "Please enter a day of week (0 for Sunday, 1 for Monday, etc): ";
                cin >> day;
                while(!dayValid(day))//Check if it is a valid day
                {
                   cout << "This is NOT valid day/n Please enter a day of week (0 for Sunday, 1 for Monday, etc): ";
                    cin >> day;
                }
                cout << "The name of the day the week is: " << dayOfWeek(day) << endl;
                break;
                
            case 7:
                cout << "Did you tested all functions yet ? if not, please return the program\n";
                break;
                
            default:
                cout << "wrong option. Please choose from menu\n";
                break;
        }

        
    } while (choice !=7);
    return 0;
    
    
}
                

void testMenu()
{
    cout << "*************************************\n"
 << "* Test Menu *\n"
 << "* 1. isLeapYear *\n"
 << "* 2. getCenturyValue *\n"
 << "* 3. getYearValue *\n"
 << "* 4. getMonthValue *\n"
 << "* 5. dayOfWeek(month, day, year) *\n"
 << "* 6. dayOfWeek(day) *\n"
 << "* 7. Quit *\n"
 << "*************************************"<< endl;
}

bool isLeapYear(int year)
{
    return((year%400==0)||(year%4==0)&&(100 !=0));
}
bool isValid(int year)
{
    return year >1582; //year is after 1582
}

bool dayValid(int day)
{
    return ((day >=0)&&(day<=6));
}

bool isValid(int month, int year)
{
    return ((month>=1) && (month<=12) && (year >1582));
    //month is between 1 and 12 , year is after 1582
}

bool isValid(int month, int day, int year)
{
    if(!isValid(month, year))// first check month and year
        return false;
    bool result = true;
    switch(month)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            result = ((day>=1) && (day<=31));
            break;
        case 4: case 6: case 9: case 11:
            result = ((day>=1)&&(day<=31));
            break;
        case 2:
            if(isLeapYear(year))
                result = ((day >=1)&&(day <=29));
            else
                result = ((day >=1)&&(day <=28));
            break;
    }
    return result;
}


int getCenturyValue(int year)
{
    return 2*(3-(year/100)%4);
}

int getYearValue(int year)
{
    return year%100 + year%100/4;
}

int getMonthValue(int month, int year)
{
    int result;
    switch(month)
    {
        case 1:
            if(isLeapYear(year))
                result = 6;
            else
                result = 0;
            break;
        case 2:
            if (isLeapYear(year))
                result = 2;
             else
                result = 3;
            break;
        case 3: case 11:
            result = 3;
            break;
        case 4: case 7:
            result = 6;
            break;
        case 5:
            result = 1;
            break;
        case 6:
            result = 4;
            break;
        case 8:
            result = 2;
            break;
        case 9: case 12:
            result = 5;
            break;
        default:// case 10:
            result = 0;
            break;
    }
    return result;
}

int dayOfWeek(int month, int day, int year)
{
 return ((getCenturyValue(year)+getMonthValue(month, year)+getYearValue(year))%7);
}
    
std::string dayOfWeek(int day)
{
    string date;
    switch(day)
    {
        case 0:
            date = "SUNDAY";
            break;
        case 1:
            date = "MONDAY";
            break;
        case 2:
            date = "TUESDAY";
            break;
        case 3:
            date = "WEDNESDAY";
            break;
        case 4:
            date = "THURDAY";
            break;
        case 5:
            date = "FRIDAY";
            break;
        case 6:
            date = "SATURDAY";
            break;
  }
    return date;
}




//*EXTRA CREDIT*
//*************************************
//* Test Menu *
//* 1. isLeapYear *
//* 2. getCenturyValue *
//* 3. getYearValue *
//* 4. getMonthValue *
//* 5. dayOfWeek(month, day, year) *
//* 6. dayOfWeek(day) *
//* 7. Quit *
//*************************************
//Please choose from menu: 1
//Please enter a year: 907
//This year is NOT valid. Please enter a year after 1582:
//2000
//Year 2000 is a leap year
//*************************************
//* Test Menu *
//* 1. isLeapYear *
//* 2. getCenturyValue *
//* 3. getYearValue *
//* 4. getMonthValue *
//* 5. dayOfWeek(month, day, year) *
//* 6. dayOfWeek(day) *
//* 7. Quit *
//*************************************
//Please choose from menu: 4
//Please enter a year and month: 2019 50
//This is NOT valid. Enter the number 1-12 for month, and after 1582 for year:
//2018 -8
//This is NOT valid. Enter the number 1-12 for month, and after 1582 for year:
//2018 04
//The month value is: 6
//*************************************
//* Test Menu *
//* 1. isLeapYear *
//* 2. getCenturyValue *
//* 3. getYearValue *
//* 4. getMonthValue *
//* 5. dayOfWeek(month, day, year) *
//* 6. dayOfWeek(day) *
//* 7. Quit *
//*************************************
//Please choose from menu: 5
//Please enter a year, a month, and a day: 356 10 07
//This is NOT Valid day. Please enter carefully:
//2019 14 9
//This is NOT Valid day. Please enter carefully:
//2020 10 12
//The day of the week is: 4


//====================================================================================

// * SAMPLE RUN *
//*************************************
//* Test Menu *
//* 1. isLeapYear *
//* 2. getCenturyValue *
//* 3. getYearValue *
//* 4. getMonthValue *
//* 5. dayOfWeek(month, day, year) *
//* 6. dayOfWeek(day) *
//* 7. Quit *
//*************************************
//Please choose from menu: 1
//Please enter a year: 1900
//Year 1900 is a leap year
//*************************************
//* Test Menu *
//* 1. isLeapYear *
//* 2. getCenturyValue *
//* 3. getYearValue *
//* 4. getMonthValue *
//* 5. dayOfWeek(month, day, year) *
//* 6. dayOfWeek(day) *
//* 7. Quit *
//*************************************
//Please choose from menu: 2
//Please enter a year: 2008
//The century value is: 6
//*************************************
//* Test Menu *
//* 1. isLeapYear *
//* 2. getCenturyValue *
//* 3. getYearValue *
//* 4. getMonthValue *
//* 5. dayOfWeek(month, day, year) *
//* 6. dayOfWeek(day) *
//* 7. Quit *
//*************************************
//Please choose from menu: 3
//Please enter a year: 2008
//The year value is: 10
//*************************************
//* Test Menu *
//* 1. isLeapYear *
//* 2. getCenturyValue *
//* 3. getYearValue *
//* 4. getMonthValue *
//* 5. dayOfWeek(month, day, year) *
//* 6. dayOfWeek(day) *
//* 7. Quit *
//*************************************
//Please choose from menu: 4
//Please enter a year and month: 2016 10
//The month value is: 0
//*************************************
//* Test Menu *
//* 1. isLeapYear *
//* 2. getCenturyValue *
//* 3. getYearValue *
//* 4. getMonthValue *
//* 5. dayOfWeek(month, day, year) *
//* 6. dayOfWeek(day) *
//* 7. Quit *
//*************************************
//Please choose from menu: 5
//Please enter a year, a month, and a day: 2016 10 12
//The day of the week is: 3
//*************************************
//* Test Menu *
//* 1. isLeapYear *
//* 2. getCenturyValue *
//* 3. getYearValue *
//* 4. getMonthValue *
//* 5. dayOfWeek(month, day, year) *
//* 6. dayOfWeek(day) *
//* 7. Quit *
//*************************************
//Please choose from menu: 6
//Please enter a day of week (0 for Sunday, 1 for Monday, etc): 3
//The name of the day the week is: WEDNESDAY
//*************************************
//* Test Menu *
//* 1. isLeapYear *
//* 2. getCenturyValue *
//* 3. getYearValue *
//* 4. getMonthValue *
//* 5. dayOfWeek(month, day, year) *
//* 6. dayOfWeek(day) *
//* 7. Quit *
//*************************************
//Please choose from menu: 7
//Did you tested all functions yet ? if not, please return the program
//Program ended with exit code: 0
