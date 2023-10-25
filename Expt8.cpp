#include <iostream>
using namespace std;


void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
       
        

        for (int j = 1; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
               
                std::swap(arr[j], arr[j + 1]);
                
            }
        }

       
        
    }
}

int main() {
    int arr[100];
   int n;
   cout<<"Enter the size of the array : ";
   cin>>n;
   cout<<"Enter the elements of the array : ";
   for (int i = 0; i < n; i++)
   {
    cin>>arr[i];
   }
   

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    bubbleSort(arr, n);

    std::cout << "\nSorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
