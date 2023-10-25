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

Node* middle(Node*head){
    int len=0 ; Node*temp = head;
    while (temp!= NULL)
    {
      len++;
      temp = temp->next;
    }
  
    Node*t=head;
    
    int mid = len/2;

   while (mid)
   {
      t = t->next;
      mid--;
   }
   return t;
    
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
     insertAtPosition(6, 35, head, tail);
    print(head);

    cout<<"head data : "<<head->data<<endl;
    cout<<"tail data : "<<tail->data<<endl;

  Node* a=  middle(head);
   cout<< "Middle element of the linked list is : "<<a->data;

}