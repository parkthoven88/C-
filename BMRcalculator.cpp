// CSCI 121 Project 02
// Author : Hyojin Park
// Date : 09-02-2020
//This is my BMR calculator

/*The program uses Harris Benedict's equation to calculate how much calories users need in a day without exercise. */

#include <iostream>
#include <string>
using namespace std;

int main()
{
    // declare variable
    char choice;
    
    do//this do while loop is for allowing the user to start over
    {
        char gender; //could be F, f, M, and m
        double weight, height, age, bmr=0, bar=0;
        string gender1, gender2;
    
        cout << "Welcome to my BMR calculator.\n";
        // ask user to enter gender
        cout << "Gender (M or F):";
        cin  >> gender;
        //while the gender is not correct, ask  user to reenter
        while ((gender !='F')&&(gender !='f')&&(gender !='M')&&(gender !='m'))
        {
            cout << "Wrong gender input. Please enter again. Gender (M or F):";
            cin >> gender;
        }
                // ask user to enter weight, height, and age
                cout << "Weight(in pound):";
                cin >> weight;
                cout << "Height(in inches):";
                cin >> height;
                cout << "Age(in years):";
                cin >> age;
        
            if((gender =='F')||(gender == 'f'))
            {
                bmr = 655+(4.3*weight)+(4.7*height)-(4.7*age);
                bar = bmr/230;
                gender1 = "She";
                gender2 = "her";
            }
                else if((gender == 'M')||(gender == 'm'))
                {
                    bmr = 66+(6.3*weight)+(12.9*height)-(6.8*age);
                    bar = bmr/230;
                    gender1 ="He";
                    gender2 ="his";
                }

        cout << gender1 << " needs " << bmr << " calories to maintain " <<gender2
             << " weight.\n";
        cout << "That is about " << bar << " chocolate bar's calories.\n";
        
        //ask if user what to do abother calculation
        cout << "Do you want to do another calculation?(Y/N):";
        cin >> choice;
    }while( choice == 'Y' || choice == 'y');
            cout << "Thanks for using my BMR calculator. Good bye!\n";
    
return 0;
}

//Code output:



//Welcome to my BMR calculator.
//Gender (M or F):g
//Wrong gender input. Please enter again. Gender (M or F):f
//Weight(in pound):140
//Height(in inches):66
//Age(in years):40
/*She needs 1379.2 calories to maintain her weight.
That is about 5.99652 chocolate bar's calories.*/
//Do you want to do another calculation?(Y/N):Y
//Welcome to my BMR calculator.
//Gender (M or F):N
//Wrong gender input. Please enter again. Gender (M or F):M
//Weight(in pound):140
//Height(in inches):66
//Age(in years):40
/*He needs 1527.4 calories to maintain his weight.
That is about 6.64087 chocolate bar's calories.*/
//Do you want to do another calculation?(Y/N):n
//Thanks for using my BMR calculator. Good bye!
//Program ended with exit code: 0
