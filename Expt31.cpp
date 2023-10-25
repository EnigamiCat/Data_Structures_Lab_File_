#include <iostream>
using namespace std;
int f = -1, r = -1;

void enqueue(int queue[], int x)
{
    if (r == 99)
    {
        cout << "Queue overflow.";
    }
    else if (r == -1 && f == -1)
    {
       f++;
        queue[++r] =x;
        
    }

    else
    {
        queue[++r] = x;
    }
}

void dequeue(int queue[])
{
    if (f == -1 && r == -1)
    {
        cout << "Underflow.";
    }

    else if (f == r)
    {
        f = -1;
        r = -1;
    }
    else
    {
        cout << "Popping the element " << queue[f];
        f++;
    }
}

void isEmpty()
{
    if (f == -1)
    {
        cout << "Queue is empty";
    }
    else
        cout << "Queue is not empty";
}

void peek(int queue[])
{
    cout << "Element at the start of the queue is : " << queue[f] << endl;
}

void print(int queue[])
{
    cout << "elements of the queue are : ";
    for (int i = 0; i <= r; i++)
    {
        cout << queue[i] << " ";
    }
}

int main()
{
    int queue[100];
    

    enqueue(queue, 30);
    enqueue(queue, 23);
    enqueue(queue, 1);
    enqueue(queue, 31);
    enqueue(queue, 13);

    print(queue);
}