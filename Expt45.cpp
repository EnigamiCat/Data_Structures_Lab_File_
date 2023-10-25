#include<iostream>
using namespace std;

class Node{
        public : 
        int data;
        Node* left;
        Node* right;

        Node(int d){
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }
};


Node* createTree(Node* root){
    cout<<"Enter the data : ";
    int data;
    cin>>data;
    root = new Node(data);

    if (data==-1)
    {
        return NULL;
    }

     cout<<"Enter data for inserting in left : ";
     root->left =  createTree(root->left);
     cout<<"Enrer data for inserting in right : ";
     root->right = createTree(root->right);
     return root;   
}

void postorder(Node*root){
    if (root==NULL)
    {
       return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    
}

int main(){
    Node * root = NULL;

    root = createTree(root);
    cout<<"Preorder traversal is : ";
    
    postorder(root);
    return 0;
}