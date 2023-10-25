#include<iostream>
using namespace std;

void removeAtStart(int arr[],int &size){
    size--;
    for (int i = 0; i < size; i++)
    {
        arr[i] = arr[i+1];
    }

    
}

void addAtStart(int arr[], int &size){
    size++;int val;
    cout<<"Enter the value to add : ";
    cin>>val;

    for (int i = size-1; i >= 1; i--)
    {
        arr[i] = arr[i-1];
    }

    arr[0] = val;
    
}

void print(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}

int main(){
    int arr[100],size,k;
    cout<<"Enter the size : ";
    cin>>size;
    cout<<"Enter the elements of the array\n";
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
     
 cout<<"*** Press 1 to delete and 2 to insert ***\n";
    cin>>k;
    if (k==1)
    {
        removeAtStart(arr,size);
        cout<<"Modified array is : ";
        print(arr,size);
    }  else if (k==2)
    {
        addAtStart(arr, size);
        cout<<"Modified array is : ";
        print(arr,size);
    }
    
}