#include<iostream>
using namespace std;

int main(){
    int n; 
    cout<<"Enter the number of students : ";
    cin>>n;  int total[n] = {0} , subTotal[5] = {0};

    
    int arr[n][5];

    for (int i = 0; i < n; i++)
    {    cout<<"Enter the marks for 5 subjects of student "<<i+1<<endl;
        for (int j = 0; j < 5; j++)
        {
            cin>>arr[i][j];
            total[i]  = total[i] +  arr[i][j];
            subTotal[j] = subTotal[j] + arr[i][j];
        }
        
    }

    for (int i = 0; i < n; i++)
    {
        cout<<"Total marks for student "<<i+1<<" is "<<total[i]<<endl;
    }
    
     for (int j = 0; j < 5; j++)
     {
            float avgSub = (float) subTotal[j]/n;
            cout<<"The average of subject "<<j+1<<" is "<<avgSub<<endl;
     }
     
    
    
}