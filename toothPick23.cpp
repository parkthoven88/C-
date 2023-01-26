
// Author : Hyojin Park
// Date : 09-14-2020
//This is my "23" tooth pick!


#include <iostream>

using namespace std;

int main(){
    char ans;
    
do{ //this do while loop is for allowing the user to start over
    int uPick;
    int cPick=0;
    int total = 23;

        cout << "Let's play a game of \"23\"!"<< endl;
        cout << "Enter the number of sticks you wish to pick:";
        cin >> uPick; // ask user how many sticks user will pick
   
    do{
    
      if((uPick ==1)||(uPick ==2)||(uPick ==3)){  //legal numers
                total -= uPick;
        
          if (total <4) // total value is 3
          {
            if((total==0)&&(uPick==3)) //case 1;When user picks 3 sticks
                {
                cout << "You picked "<<uPick<<" stick."<<total<<" left"<<endl;
                cout << "You picked the last stick."<<endl;
                cout << "Sorry, the computer beat you!"<<endl;
               
                
                }
              
                else if ((total ==1)&&(uPick ==2)) //case 2;When user picks 2 sticks
                 {
                    cout << "You picked "<<uPick<<" stick. "<<total<<" left"<<endl;
                    cPick= 1;
                    total =0;;
                    cout << "Computer picked "<< cPick<<" sticks. "<<total<< " left"<<endl;
                    cout << "Computer picked the last stick."<<endl;
                    cout << "Congratuation! You win!"<<endl;
                  }
              
                else if((total ==0)&&(uPick ==1))
                    //case3_2; When user picks the remaining 1
                  {
                    cout << "You picked "<<uPick<<" stick. "<<total<<" left"<<endl;
                    cout << "You picked the last stick."<<endl;
                    cout << "Sorry, the computer beat you!"<<endl;
               
                   }
            
                else
                     {  //case 3_1; When user picks 1 stick
                    cout << "You picked "<<uPick<<" stick. "<<total<<" left"<<endl;
                    cPick = 1;
                    total -= cPick;
                    cout << "Computer picked "<< cPick<<" sticks. "<<total<< " left"<<endl;
                    cout << "Yout turn. Enter the number of sticks you wish to pick:";
                    cin >> uPick;
                      }
                
            
           }
          else
          { //Until the total value falls below four.
            cout << "You picked "<<uPick<<" stick. "<<total<<" left"<<endl;
            cPick = 4-uPick;
            total -= cPick;
            cout << "Computer picked "<< cPick<<" sticks. "<<total<< " left"<<endl;
            cout << "Your turn. Enter the number of sticks you wish to pick:";
            cin >> uPick;
          }

            

        }
        else
        {   //while the user picks illegal numer, ask  user to reenter
                cout << "Wrong number of sticks. Please pick 1, 2, or 3 sticks:";
                cin >> uPick;
        }
    
    
     }
      while(total>0);
        //ask if user what to do another game
        cout << "Do you want to play anoyher game?<Y/N>:";
        cin >> ans;

    }
    while ((ans =='y')||(ans =='Y'));
     cout << "Good bye! Have a great day!"<<endl;
    
    
    return 0;
}



// Let's play a game of "23"!
// Enter the number of sticks you wish to pick:2
// You picked 2 stick. 21 left
// Computer picked 2 sticks. 19 left
// Your turn. Enter the number of sticks you wish to pick:3
// You picked 3 stick. 16 left
// Computer picked 1 sticks. 15 left
// Your turn. Enter the number of sticks you wish to pick:4
// Wrong number of sticks. Please pick 1, 2, or 3 sticks:0
// Wrong number of sticks. Please pick 1, 2, or 3 sticks:2
// You picked 2 stick. 13 left
// Computer picked 2 sticks. 11 left
// Your turn. Enter the number of sticks you wish to pick:3
// You picked 3 stick. 8 left
// Computer picked 1 sticks. 7 left
// Your turn. Enter the number of sticks you wish to pick:2
// You picked 2 stick. 5 left
// Computer picked 2 sticks. 3 left
// Your turn. Enter the number of sticks you wish to pick:1
// You picked 1 stick. 2 left
// Computer picked 1 sticks. 1 left
// Yout turn. Enter the number of sticks you wish to pick:1
// You picked 1 stick. 0 left
// You picked the last stick.
// Sorry, the computer beat you!
// Do you want to play anoyher game?<Y/N>:y
// Let's play a game of "23"!
// Enter the number of sticks you wish to pick:1
// You picked 1 stick. 22 left
// Computer picked 3 sticks. 19 left
// Your turn. Enter the number of sticks you wish to pick:
// .................
