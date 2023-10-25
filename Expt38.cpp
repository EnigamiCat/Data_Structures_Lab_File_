#include <iostream>
#include <stack>

using namespace std;

class QueueUsingStacks {
public:
    void enqueue(int value) {
        
        inputStack.push(value);
    }

    int dequeue() {
        if (outputStack.empty()) {
             
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }

        
        if (!outputStack.empty()) {
            int front = outputStack.top();
            outputStack.pop();
            return front;
        } else {
            
        cout << "Queue is empty." << endl;
            return -1;  
        }
    }

    bool isEmpty() {
        return inputStack.empty() && outputStack.empty();
    }

private:
    stack<int> inputStack;
    stack<int> outputStack;
};

int main() {
    QueueUsingStacks myQueue;

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);

    cout << "Dequeued: " << myQueue.dequeue() << endl;
    cout << "Dequeued: " << myQueue.dequeue() << endl;

    myQueue.enqueue(4);

    cout << "Dequeued: " << myQueue.dequeue() << endl;
    cout << "Dequeued: " << myQueue.dequeue() << endl;

    return 0;
}
