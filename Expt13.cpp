#include <iostream>
using namespace std;


void heapify(int arr[], int size, int rootIndex) {
    int largest = rootIndex;  
    int leftChild = 2 * rootIndex + 1;  
    int rightChild = 2 * rootIndex + 2;

   
    if (leftChild < size && arr[leftChild] > arr[largest])
        largest = leftChild;

   
    if (rightChild < size && arr[rightChild] > arr[largest])
        largest = rightChild;

   
    if (largest != rootIndex) {
   swap(arr[rootIndex], arr[largest]);
        
        heapify(arr, size, largest);
    }
}


void heapSort(int arr[], int size) {
   
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);

   
    for (int i = size - 1; i > 0; i--) {
        swap(arr[0], arr[i]); 
        heapify(arr, i, 0); 
    }
}

int main() {
    int arr[100] , size ; 

    cout<<"Enter the size : ";
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

    heapSort(arr, size);

    cout << "\nSorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
