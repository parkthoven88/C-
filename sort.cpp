

// CSCI 121 Project 07
// Author : Hyojin Park
// Date : 11-05-2020



#include <iostream>
using namespace std;

void fill_array(int arr[], int size);
// pre-condition: The arr has actual size that is greater than or equal to size
// post-condition: arr[0], ..., arr[size-1] is filled from keyboard

void print_array(int arr[], int size);
// pre-condition: The arr has actual size that is greater than or equal to size
// post-condition: arr[0], ..., arr[size-1] is printed to screen with 5 elements per line

int linear_search(int arr[], int size, int key);
// pre-condition: arr has given size
// post-condition: The index of first occurrence of key in arr is returned. If the key cannot be found in arr, -1 is returned

void select_sort(int arr[], int size);
// pre-condition: arr has given size
// post-condition: the elements in arr are rearranged from least to largest

void insert_sort(int arr[], int size);
// pre-condition: arr has given size
// post-condition: the elements in arr are rearranged from least to largest

void bubble_sort(int arr[], int size);
// pre-condition: arr has given size
// post-condition: the elements in arr are rearranged from least to largest

void menu();
// post-condition: the menu is displayed for choose


int main() {
    int choice;
    int a[9];
    do{
     menu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
            {
                fill_array(a, 9);
                cout << "Enter the key you want to search: ";
                int key;
                cin >> key;
                int index = linear_search(a, 9, key);
                if(index == -1)
                cout << "The key " << key << " is not in array\n";
                else
                cout << "The key " << key << " is #" << (index + 1) << " element in array\n";
                break;
            }
            case 2:
            {
               fill_array(a, 9);
               select_sort(a, 9);
               cout << "After sort, the array is:\n";
               print_array(a, 9);
               break;
            }
            case 3:
            {
                fill_array(a, 9);
                insert_sort(a, 9);
                cout << "After sort, the array is:\n";
                print_array(a, 9);
                break;
            }
            case 4:
            {
              fill_array(a, 9);
                bubble_sort(a, 9);
                cout << "After sort, the array is:\n";
                print_array(a, 9);
                break;
            }
            case 5:
            {
                cout << "Thank you for using the array functions\n";
                break;
            }
            default:
            {
                cout << "Wrong choice. Please choose from menu: ";
                break;
            }
        }
    }while(choice != 5);
    return 0;
    }


void fill_array(int arr[], int size)
{
    cout << "Enter "<<size<<" integer: ";
    for(int i=0; i<size; i++)
        cin >> arr[i]; // Input with element in the array from keyboard
}


// function to print an array of size
void print_array(int arr[], int size)
{
    for(int i=0; i<size; i++){
        cout << arr[i]<<"\t";
        if(i%5==4)           // print to screen with 5 elements per line
            cout << endl;}
    cout << endl;
}

int linear_search(int arr[], int size, int key)
// Linearly search x in arr[].  If i is present then return its

{
    for(int i =0; i<size; i++)
    {
        if(arr[i]==key)
            return i;
    }
    return -1; // location,  otherwise return -1
}

// function to sort an array using selection sort
void select_sort(int arr[], int size)
{
    for(int j=0; j<size-1; j++)
    {
        int indexOfSmallest =j; //assume arr[j] is the smallest
        //find the smallest element from this position to the end of the array
        
        // One by one move boundary of unsorted subarray
        for(int i = j+1; i<size; i++)
        {
            if(arr[i]< arr[indexOfSmallest])
            {
                indexOfSmallest=i;
                
            }
        }
        //swap it with the element at the position
        int temp = arr[j];
        arr[j] = arr[indexOfSmallest];
        arr[indexOfSmallest]=temp;
    }
}


// Function to sort an array using insertion sort
void insert_sort(int arr[], int size)
{
    int i, key, j;
      for (i = 1; i < size; i++)
      {
          key = arr[i];
          j = i - 1;
          /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
          
          while (j >= 0 && arr[j] > key)
          {
              arr[j + 1] = arr[j];
              j = j - 1;
          }
          arr[j + 1] = key;
      }
}


// A function to implement bubble sort
void bubble_sort(int arr[], int size)
{
    for(int i= size-1; i>0; i--)
        // Last i elements are already in place
        for(int j=0; j<i; j++)
            if(arr[j]>arr[j+1])
            {
                //swap it with the element at the position
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
            
}



void menu()
{
        cout << "\n\t************************************************";
        cout << "\n\t*                Menu                          *";
        cout << "\n\t*        1. Test Linear Search                 *";
        cout << "\n\t*        2. Test Select Sort                   *";
        cout << "\n\t*        3. Test Insert Sort                   *";
        cout << "\n\t*        4. Test Bubble Sort                   *";
        cout << "\n\t*        5. Quit                               *";
        cout << "\n\t************************************************";
        cout << endl;
}




/*  ************************************************
    *                Menu                          *
    *        1. Test Linear Search                 *
    *        2. Test Select Sort                   *
    *        3. Test Insert Sort                   *
    *        4. Test Bubble Sort                   *
    *        5. Quit                               *
    ************************************************
Enter your choice: 1
Enter 9 integer: 3 4 5 2 1  7 6 8 9
Enter the key you want to search: 9
The key 9 is #9 element in array

    ************************************************
    *                Menu                          *
    *        1. Test Linear Search                 *
    *        2. Test Select Sort                   *
    *        3. Test Insert Sort                   *
    *        4. Test Bubble Sort                   *
    *        5. Quit                               *
    ************************************************
Enter your choice: 2
Enter 9 integer: 4 5 3 1 2 8 6 9 7
After sort, the array is:
1    2    3    4    5
6    7    8    9

    ************************************************
    *                Menu                          *
    *        1. Test Linear Search                 *
    *        2. Test Select Sort                   *
    *        3. Test Insert Sort                   *
    *        4. Test Bubble Sort                   *
    *        5. Quit                               *
    ************************************************
Enter your choice: 3
Enter 9 integer: 1 4 3 2 6 5 9 8 7
After sort, the array is:
1    2    3    4    5
6    7    8    9

    ************************************************
    *                Menu                          *
    *        1. Test Linear Search                 *
    *        2. Test Select Sort                   *
    *        3. Test Insert Sort                   *
    *        4. Test Bubble Sort                   *
    *        5. Quit                               *
    ************************************************
Enter your choice: 4
Enter 9 integer: 2 4 6 8 1 3 5 7 9
After sort, the array is:
1    2    3    4    5
6    7    8    9

    ************************************************
    *                Menu                          *
    *        1. Test Linear Search                 *
    *        2. Test Select Sort                   *
    *        3. Test Insert Sort                   *
    *        4. Test Bubble Sort                   *
    *        5. Quit                               *
    ************************************************
Enter your choice: 5
Thank you for using the array functions
Program ended with exit code: 0  */
