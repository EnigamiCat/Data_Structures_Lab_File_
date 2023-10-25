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

Node* NthFromEnd(Node*head,int n){
    Node*a = head;
    Node*b = head;
     if (head == NULL)
     {
        cout<<"Empty linked list ";
        return NULL;
     }
     
    for (int i = 0; i < n; i++)
    {
        a = a->next;
    }

    while (a)
    {
       a = a->next;
       b = b->next;
    }
    
    return b;
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
    
    int n;
   cout<<"Enter the value of N : ";
   cin>>n;

  cout<<n<<" node from the end is "<< NthFromEnd(head,n)->data<<endl;

   

}