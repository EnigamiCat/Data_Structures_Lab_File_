#include <iostream>
#include <stack>
#include <climits>
using namespace std;

class MinStack
{
private:
    stack<int> dataStack;
    int minElement;

public:
    MinStack() : minElement(INT_MAX) {}

    
    void push(int value)
    {
        if (value <= minElement)
        {
            dataStack.push(minElement); 
            minElement = value;         
        }
        dataStack.push(value);
    }

    
    void pop()
    {
        if (dataStack.empty())
        {
            return; 
        }

        if (dataStack.top() == minElement)
        {
            dataStack.pop();              
            minElement = dataStack.top(); 
            dataStack.pop();
        }
        else
        {
            dataStack.pop(); 
        }
    }

   
    int top()
    {
        if (dataStack.empty())
        {
            return INT_MIN; 
        }
        return dataStack.top();
    }

   
    int getMin()
    {
        return minElement;
    }
};

int main()
{
    MinStack minStack;

    minStack.push(3);
    minStack.push(5);
    minStack.push(2);
    minStack.push(1);

    cout << "Minimum element: " << minStack.getMin() << endl;

    minStack.pop();
    minStack.pop();

    cout << "Top element: " << minStack.top() << endl;
    cout << "Minimum element: " << minStack.getMin() << endl;

    return 0;
}
