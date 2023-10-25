#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextGreaterToRight(const vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> s;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && nums[i] > nums[s.top()]) {
            result[s.top()] = nums[i];
            s.pop();
        }
        s.push(i);
    }

    return result;
}

vector<int> nextGreaterToLeft(const vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> s;

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && nums[i] > nums[s.top()]) {
            result[s.top()] = nums[i];
            s.pop();
        }
        s.push(i);
    }

    return result;
}

vector<int> nearestSmallerToLeft(const vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> s;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && nums[i] < nums[s.top()]) {
            s.pop();
        }
        if (!s.empty()) {
            result[i] = nums[s.top()];
        }
        s.push(i);
    }

    return result;
}

vector<int> nextSmallerToRight(const vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> s;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && nums[i] < nums[s.top()]) {
            result[s.top()] = nums[i];
            s.pop();
        }
        s.push(i);
    }

    return result;
}

int main() {
    vector<int> nums = {4, 5, 2, 10, 8};
    
    vector<int> result1 = nextGreaterToRight(nums);
    vector<int> result2 = nextGreaterToLeft(nums);
    vector<int> result3 = nearestSmallerToLeft(nums);
    vector<int> result4 = nextSmallerToRight(nums);

    cout << "Next Greater to Right: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Next Greater to Left: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Nearest Smaller to Left: ";
    for (int num : result3) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Next Smaller to Right: ";
    for (int num : result4) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
