#include <iostream>
using namespace std;

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    int arr[100] , size;
    cout<<"Enter the size of the array : ";
    cin>>size;
     cout<<"Enter the array : ";
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    
    
    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    selectionSort(arr, size);

    cout << "\nSorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
