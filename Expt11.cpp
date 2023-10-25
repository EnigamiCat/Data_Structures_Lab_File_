#include <iostream>
using namespace std;



int part(int arr[], int low, int high) {
    int p = arr[high]; 
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < p) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return (i + 1); 
}


void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pIndex = part(arr, low, high); 

        // Recursively sort elements before and after the pivot
        quickSort(arr, low, pIndex - 1);
        quickSort(arr, pIndex + 1, high);
    }
}

int main() {
    int arr[100] , size ;
    cout<<"Enter the size of the array : ";
    cin>>size;
    cout<<"Enter the elements of the array : ";

    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    quickSort(arr, 0, size - 1);

    std::cout << "\nSorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
