#include <iostream>
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

void addAtTail(Node *&tail, int d)
{

    Node *temp = new Node(d);
    tail->next = temp;

    tail = temp;
}

void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtEnd(Node *&tail, int d)
{
    Node *temp = new Node(d);
    temp->next = NULL;
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(int pos, int d, Node *&head, Node *&tail)
{
    if (pos == 1)
    {
        insertAtHead(head, d);
    }
    else

    {
        Node *temp = new Node(d);

        Node *a = head;
        for (int i = 1; i < pos - 1; i++)
        {
            a = a->next;
        }

        if (a->next == NULL)
        {
            insertAtEnd(tail, d);
        }
        else
        {
            temp->next = a->next;
            a->next = temp;
        }
    }
}

Node* reverse(Node*&head,Node*&tail){
    Node*curr,*forward,*prev;

    curr = head;
    prev = NULL;

    while (curr!=NULL)
    {  forward = curr->next;
       curr->next = prev;
       prev = curr;
       curr = forward;
    }

    return prev;
    
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

int main()
{
    Node *node1 = new Node(10);
   
    Node *head = node1;

    Node *tail = node1;

   

    insertAtHead(head, 15);

   

    addAtTail(tail, 19);

    

    insertAtPosition(3, 20, head, tail);
   

    insertAtPosition(1, 24, head, tail);
  

    insertAtPosition(6, 30, head, tail);
    print(head);

    cout<<"Reversed linked list is \n";
  Node*a =   reverse(head,tail);
    print(a);
}

