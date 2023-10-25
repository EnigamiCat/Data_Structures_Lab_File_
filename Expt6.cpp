#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    int arr[100],size;
    cout<<"Enter the size of the array : ";
    cin>>size;
    cout<<"Enter the array : ";
    for (int i = 0; i < size; i++)
    {
      cin>>arr[i];
    }
    

    int target;
    int ch;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Search for an element" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter the element you want to search for: ";
                cin >> target;
                int index ;
                index = linearSearch(arr, size, target);

                if (index != -1) {
                    cout << "Element " << target << " found at index " << index << endl;
                } else {
                    cout << "Element " << target << " not found in the array." << endl;
                }
                break;
            case 2:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please select a valid option." << endl;
        }
    }

    return 0;
}
