#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int binarySearch(int  arr[], int target, int left, int right) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] > target) {
            return binarySearch(arr, target, left, mid - 1); 
        return binarySearch(arr, target, mid + 1, right); 
    }
    return -1; 
}
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

    sort(arr,arr+size);
    

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
                index = binarySearch(arr, target, 0 , size);

                if (index != -1) {
                    cout << "Element " << target << " found "<< endl;
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
