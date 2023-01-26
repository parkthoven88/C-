
// Author : Hyojin Park
// Date : 09-28-2020
//This is "The temperature of earth at a depth"

#include <iostream>
using namespace std;


// prints out information to tell the user what this program does.
void print_introduction();
/*display the conclusion that what is the temperature in both Celsius and Fahrenheit at depth of the earth*/
void print_conclusion(double depth);
//computes and returns the clesius temperature at a depth measured in kilometers.
double celsius_at_depth(double depth)
{
        return(depth*10+20);
}
// converts a Celsius temperature celsius to Fahrenheit.
double celsius_to_fahrenheit (double celsius)
{
    return(celsius*1.8+32);
}

int main() {
    double depth;
    char answer;
    
 print_introduction();
    
    // begin do while loop
    do
    {

        // ask user to enter depth
        cout <<"Enter a depth in KM:";
        cin >> depth;
        print_conclusion(depth);
        cout << "Would you like to do it again?(Y/N):";
        cin >> answer;
        }
        
    // ask if user want to do it again.
    while ((answer == 'Y')||(answer == 'y'));
    return 0;
}

void print_introduction()
{
    cout <<"Hello! The program will tell you the temperature of the earth at any depth.\n";
}

void print_conclusion(double depth)
{
    double celsius = celsius_at_depth(depth);
    double fahrenheit = celsius_to_fahrenheit(celsius);
    
    cout << "The temperature of the earth at a depth of "
    << depth << " KM is " << celsius << " in Celsius, and "<< fahrenheit << " in Fahrenheit.\n";

}

// Sample run
//Hello! The program will tell you the temperature of the earth at any depth.
//Enter a depth in KM:10
//The temperature of the earth at a depth of 10 KM is 120 in Celsius, and 248 in Fahrenheit.
//Would you like to do it again?(Y/N):y
//Enter a depth in KM:20
//The temperature of the earth at a depth of 20 KM is 220 in Celsius, and 428 in Fahrenheit.
//Would you like to do it again?(Y/N):n
//Program ended with exit code: 0
