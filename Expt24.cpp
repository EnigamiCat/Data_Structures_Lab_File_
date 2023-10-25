#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev, *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int length(Node *head)
{
    Node *temp = head;
    int l = 0;
    while (temp != NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
}

void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    temp->prev = NULL;
    head->prev = temp;
    head = temp;
}

void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    temp->prev = tail;
    temp->next = NULL;
    tail->next = temp;
    tail = temp;
}


int main()
{
    Node *node1 = new Node(20);
    Node *head = node1;
    Node *tail = node1;
    print(head);

    insertAtHead(head, 33);
    print(head);

    insertAtTail(tail, 10);
    print(head);

    insertAtHead(head, 21);

    insertAtHead(head, 309);

    insertAtHead(head, 2);

    insertAtTail(tail, 289);
    insertAtTail(tail, 87);
    cout<<"doubly linked list implemented\n";
    print(head);

    
   
}