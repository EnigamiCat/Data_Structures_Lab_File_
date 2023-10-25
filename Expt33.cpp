#include <iostream>
#include <vector>
using namespace std;

int trapRainwater(const vector<int>& height) {
    int n = height.size();
    if (n <= 2) {
        return 0; 
    }

    vector<int> leftMax(n);
    vector<int> rightMax(n);

    leftMax[0] = height[0];
    for (int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i - 1], height[i]);
    }

    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i + 1], height[i]);
    }

    int trappedWater = 0;
    for (int i = 0; i < n; i++) {
        trappedWater += min(leftMax[i], rightMax[i]) - height[i];
    }

    return trappedWater;
}

int main() {
    vector<int> height ;
    int n;
    char ch = 'y';
   
    cout<<"Enter the heights of the buildings : ";
    while (ch=='y' || ch=='Y')
    {
      cin>>n;
      height.push_back(n);

      cout<<"Want to add more builings? Y/N \n";
      cin>>ch;
    }
    
    
    int trappedWater = trapRainwater(height);

    cout << "Trapped rainwater: " << trappedWater << " units" << endl;

    return 0;
}
