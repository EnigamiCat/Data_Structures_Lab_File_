#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> firstNegativeInWindow(const vector<int> &nums, int k)
{
    vector<int> result;
    queue<int> window;

    int left = 0;
    int right = 0;

    while (right < nums.size())
    {
        // Check if the current element is negative and add it to the window
        if (nums[right] < 0)
        {
            window.push(nums[right]);
        }

        // Check if the window size is equal to k
        if (right - left + 1 == k)
        {
            // If the window is empty, add 0 to the result
            if (window.empty())
            {
                result.push_back(0);
            }
            else
            {
                // Otherwise, the front of the queue contains the first negative element
                result.push_back(window.front());

                // If the left element is negative, remove it from the window
                if (nums[left] < 0)
                {
                    window.pop();
                }
            }
            left++; // Move the window to the right
        }

        right++;
    }

    return result;
}

int main()
{
    vector<int> nums ;
     char ch='y'; int a ;
     cout<<"Enter the elements : ";
    while (ch=='Y' || ch=='y')
    {   cin>>a;
       nums.push_back(a);
       cout<<"Want to enter more elements ? Y/N \n";
       cin>>ch;
    }
    
    cout << "Enter the window size : ";

    int k;
    cin >> k;

    vector<int> result = firstNegativeInWindow(nums, k);


     int size = result.size();
    for (int i = 0; i <= size-k+1; i++)
    {
        cout<<result[i]<<" ";
    }
    

    return 0;
}
