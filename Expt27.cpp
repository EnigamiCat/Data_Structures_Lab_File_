#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        this->next = NULL;
    }
};

void insertAtEnd(Node *&tail, int d)
{
    Node *temp = new Node(d);
    temp->next = NULL;
    tail->next = temp;
    tail = temp;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void palindrome(Node *head)
{
    vector<int> arr;
    Node *temp = head;
    while (temp)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }

    int size = arr.size();
    int s = 0;
    int e = size - 1;

    while (s<e)
    {
        if (arr[s]!=arr[e])
        {
           cout<<"Not palindrome.\n";
           return ;

        } else {
            s++;
            e--;
        }
     
        
    }

    cout<<"It is palindrome.\n";
    
}

int main()
{
    Node *node1 = new Node(10);
   

    Node *head = node1;

    Node *tail = node1;

    
    insertAtEnd(tail, 30);
    insertAtEnd(tail, 392);
    insertAtEnd(tail, 392);
    insertAtEnd(tail, 30);
    insertAtEnd(tail, 10);

    print(head);

    palindrome(head);

}