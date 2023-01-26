
// Author : Hyojin Park
// Date : 11-18-2020

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;
void get_scores(vector<int> &v);
//precondition : get integer scores from keyboard and store in v.
/*postcondition : we assume that the user will input scores in range of 0 to 100, inclusive. User enter a negative number to stop the input and end the function */

void print_stats(vector<int> &v);
//precondition : get integer scores from keyboard and store in v.
/*postcondition : print out the stats of data that are stored in v includes: max, min, total number of data, and the average */

bool is_palindrome(string &sentence);
// precondition : get a sentence from keyboard and store in sentance
/* postcondition : return true if the sentence is a palindrome;
                   otherwise false */

int main()
{
    // Solve First problem
    char answer;
    do{
    vector<int> scores;
    get_scores(scores);
    print_stats(scores);
        cout << "\nDo you want to try another set of scores? Y/N: ";
        cin>> answer;
    }while((answer == 'Y')||(answer =='y'));

    // Solve second problem

    string sentence;
    do{
    cout <<"\nEnter a sentence: ";
    getchar(); //get rid of character in input buffer
    getline(cin, sentence);
    if(is_palindrome(sentence))
        cout << "\"" << sentence << "\" is a palindrome\n";
    else
        cout << "\"" << sentence << "\" is not a palindrome\n";
        
        cout << "\nDo you want to try another sentence? Y/N: ";
        cin >> answer;
    }while((answer == 'Y')||(answer =='y'));
    
    
    return 0;
}

void get_scores(vector<int> &v)
{
    int score;
    cout << "\nEnter scores, enter -1 to stop: " << endl;
    do{
        cin >> score;
        if(score>=0)
            v.push_back(score); // add the scores in v
    }while(score >=0);

}

void print_stats(vector<int> &v)
{
    int max = -1, min = 101, total = 0;
   size_t size= v.size(); // how many elements in v
    for(size_t i=0; i<size; i++)
    {
        if(v[i]<min)
            min = v[i]; //get a minimum
        if(v[i]>max)
            max = v[i]; // get a maximum
        total += v[i]; // get a total
    }
    if(size == 0)
        cout << "There is no scores."<<endl;
    else{
        cout << "There are total " << size << " scores" <<endl;
        cout << "The highest score is: " << max <<endl;
        cout << "The lowest score is: " << min << endl;
        cout << "The average score is: " <<1.0*total/size <<endl;}
          // Multiplying by 1.0 means to show decimal places
}

bool is_palindrome(string &sentence)
{
    int left = 0; // left index of chracters in sentence
    int right =(int)sentence.length()-1;
    // right index of characters in sentence
    while(left < right){
        while(!isalpha(sentence[left])){ //skip non English letters
            left++;
            if(left==right) return true;
        }
        while(!isalpha(sentence[right])){ //skip non English letters
            right--;
            if(right==left) return true;
        }
        if(tolower(sentence[left]) != tolower(sentence[right]))
            //compare if two letters are not a palindrome
            return false;
        left++;
        right--;
    }
    return true;
}

/* Sample Run

 Enter scores, enter -1 to stop:
 87
 98
 65
 78
 88
 93
 -1
 There are total 6 scores
 The highest score is: 98
 The lowest score is: 65
 The average score is: 84.8333

 Do you want to try another set of scores? Y/N: y

 Enter scores, enter -1 to stop:
 -1
 There is no scores.

 Do you want to try another set of scores? Y/N: n

 Enter a sentence: A nut for a jar of tuna
 "A nut for a jar of tuna" is a palindrome

 Do you want to try another sentence? Y/N: y

 Enter a sentence: Hello world
 "Hello world" is not a palindrome

 Do you want to try another sentence? Y/N: n
 Program ended with exit code: 0       */
