
// Author : Hyojin Park
// Date : 12-01-2020


#include <iostream>

using namespace std;

int sum(int n);
// Recursive verson to calculate the sum of
// 1 + 2+ .... +n

// option 2:
int str_length(char s[]);
// Recursive version of strlen in C strings.
// It returns the length of the string a[].
// (the null character, '\0', is not counted in the length)


int main() {
    char answer;
    
    do{
        int n;
        cout << "Enter a positive integer : ";
        cin >> n;
        cout << "The sum of 1+2+...+" << n << " is: " << sum(n) <<endl<<endl;
        
        char s[80];
        cout << "Enter a sentence: ";

        cin.clear(); //to get rid of the error flag
        cin.ignore(10000,'\n');//skips to the next newline
        
        cin.getline(s,80);

        cout <<"It contains "<< str_length(s) << " chars, including white spaces"<<endl<<endl;

        //ask the user if she or he wants to continue
        cout << "Do you want to have another run? Y/N :";
        cin >> answer;
        cout << endl;
    }
    while((answer =='Y')||(answer == 'y'));
   

    return 0;
}

int sum(int n)
{
    if(n != 0)
        return n + sum(n - 1);
    return 0;
}

int str_length(char s[])
{

    if (s[0] == '\0')
        return 0;
     return 1+ str_length(s+1);
}




/*Sample Run
 

 Enter a positive integer : 10
 The sum of 1+2+...+10 is: 55

 Enter a sentence: Hello world!
 It contains 12 chars, including white spaces

 Do you want to have another run? Y/N :Y


 Enter a positive integer : 100
 The sum of 1+2+...+100 is: 5050

 Enter a sentence: I love programming!
 It contains 19 chars, including white spaces

 Do you want to have another run? Y/N :n

 Program ended with exit code: 0   */
