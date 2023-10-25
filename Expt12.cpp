#include <iostream>
using namespace std;

void merge(int arr[], int left, int m, int right)
{
    int n1 = m - left + 1;
    int n2 = right - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

   
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
       
        int m = left + (right - left) / 2;

       
        mergeSort(arr, left, m);
        mergeSort(arr, m + 1, right);

       
        merge(arr, left, m, right);
    }
}

int main()
{
    int arr[100], size;
    cout<<"Enter the size of the array : ";
    cin>>size;

    cout<<"Enter the elements of the array : ";
    for (int i = 0; i < size ; i++)
    {
        cin>>arr[i];
    }
    

    cout << "Original array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    mergeSort(arr, 0, size - 1);

    cout << "\nSorted array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}