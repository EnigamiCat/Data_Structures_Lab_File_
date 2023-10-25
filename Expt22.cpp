#include <iostream>
#include<map>
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

 

 

bool detectCycle(Node*head){
      if (head==NULL)
      {
       return false;
      }
      
      map<Node*,bool> visited;

      Node*temp = head;

      while (temp!=NULL)
      {
        if (visited[temp]==true)
        {
           return true;
        }
        visited[temp] = true;
        temp = temp->next;
      }

      return false;
      
}

Node* floydDetectCycle(Node*head){
    if (head==NULL)
    {
       return NULL ;
    }
    Node*slow = head;
    Node*fast = head;

    while (slow!=NULL && fast!=NULL)
    {
       fast = fast->next;
       if (fast!=NULL)
       {
        fast = fast->next;
       }
       
       slow = slow->next;
       if (slow==fast)
       {
        return slow;
       }
       
    }
    return NULL;
    
}

Node* getStartNode(Node*head){
    if (head==NULL)
    {
        return NULL;
    }
    
    Node* intersection = floydDetectCycle(head);
    Node* slow  = head;

    while (slow!=intersection)
    {
       slow = slow->next;
       intersection = intersection->next;
    }
    return slow;
}

void removeCycle(Node*head){
    if (head==NULL)
    {
       return ;
    }
    Node* startOfLoop = getStartNode(head);
    Node* temp = startOfLoop;

    while (temp->next!=startOfLoop)
    {
       temp = temp->next;
    }
     
     temp->next = NULL;
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

    

    insertAtEnd(tail,20);
    insertAtEnd(tail,30);
    insertAtEnd(tail,40);
    insertAtEnd(tail,50);

    print(head);

    

    tail->next = head->next;

    if (floydDetectCycle(head))
    {
       cout<<"This linked list contains cycle.\n";
    }
    else cout<<"This linked list does not contain cycle.\n";

    cout<<"The starting node of the cycle is : "<< getStartNode(head)->data<<endl;

    cout<<"Removing the cycle : \n";
    removeCycle(head);

     if (floydDetectCycle(head))
    {
       cout<<"This linked list contains cycle.\n";
    }
    else cout<<"This linked list does not contain cycle.\n";

    cout<<"The starting node of the cycle is : "<< getStartNode(head)->data<<endl;
   
    
    
    

}