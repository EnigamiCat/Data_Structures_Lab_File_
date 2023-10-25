#include <iostream>

using namespace std;


int findMinimum(int arr[], int left, int right) {
    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > arr[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return arr[left];
}


void findFloorCeilPeak(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    int floor = -1;
    int ceil = -1;
    int peak = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            floor = ceil = mid;
            break;
        } else if (arr[mid] < target) {
            floor = mid;
            left = mid + 1;
        } else {
            ceil = mid;
            right = mid - 1;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            peak = i;
            break;
        }
    }

    if (floor != -1)
        cout << "Floor: " << arr[floor] << endl;
    else
        cout << "Floor not found" << endl;

    if (ceil != -1)
        cout << "Ceiling: " << arr[ceil] << endl;
    else
        cout << "Ceiling not found" << endl;

    if (peak != -1)
        cout << "Peak: " << arr[peak] << endl;
    else
        cout << "Peak not found" << endl;
}

int main() {
   int arr[100];
   int size;
   cout<<"Enter the size : ";
   cin>>size;
   cout<<"Enter the elements of the array : ";
   for (int i = 0; i < size; i++)
   {
      cin>>arr[i];
   }
   
   int target ; 
   cout<<"Enter the target : ";

    cin>>target;
    int minimum = findMinimum(arr, 0, size - 1);
    cout << "Minimum element: " << minimum << endl;

    findFloorCeilPeak(arr, size, target);

    return 0;
}
