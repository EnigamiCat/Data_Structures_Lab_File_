#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // Maximum size of the array

void print(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}

int main()
{
    int arr[MAX_SIZE];
    int size = 0;
    int k;
    char ch = 'y';

    while (ch == 'Y' || ch == 'y')

    {

        cout << "Enter 1 for inserting and 2 for deleting : ";
        cin >> k;

        if (k == 1)
        {
            if (size < MAX_SIZE)
            {
                int val;
                cout << "Enter the value to add at the end : ";
                cin >> val;
                arr[size] = val;
                size++;
            }
        }

        if (k == 2)
        {
            if (size > 0)
            {
                size--;
            }
            else
            {
                cout << "Underflow: Array is empty." << endl;
            }
        }
        cout << "Want to continue? ";
        cin >> ch;
    }

    print(arr,size);
    return 0;
}