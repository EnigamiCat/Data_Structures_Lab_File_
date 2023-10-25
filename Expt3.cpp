#include<iostream>
using namespace std;

void remove(int arr[],int &size){
    int pos;
    cout<<"Enter the position to delete : ";
    cin>>pos;
        for (int i = pos; i < size; i++)
        {
            arr[i-1] = arr[i];
        }
        size--;
}

void insert(int arr[], int &size){
    int val,pos;  size++;
    cout<<"Enter position and value to insert respectively\n";
    cin>>pos>>val;
    for (int i = size-1 ; i >= pos; i--)
    {
        arr[i] = arr[i-1];
        
    }
    arr[pos-1] = val;
   
    
}

void print(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}

int main(){
    int arr[100],size,k;
    cout<<"Enter the size of the array : ";
    cin>>size;
    cout<<"Enter the elements of the array : ";
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    


    cout<<"*** Press 1 to delete and 2 to insert ***\n";
    cin>>k;
    if (k==1)
    {
        remove(arr,size);
        cout<<"Modified array is : ";
        print(arr,size);
    }  else if (k==2)
    {
        insert(arr, size);
        cout<<"Modified array is : ";
        print(arr,size);
    }
    
    


    
}