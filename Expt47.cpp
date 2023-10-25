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
     cout<<"Enter data for inserting in right : ";
     root->right = createTree(root->right);
     return root;   
}



int height(Node*root){
    if (root==NULL)
    {
       return 0;
    }
    
    int left = height(root->left);
    int right = height(root->right);

    int h = max(left,right) + 1;
    return h;
}

int diameter(Node*root){
    if (root==NULL)
    {
       return 0;
    }
    
    int d1 = diameter(root->left);
    int d2 = diameter(root->right);
    int h = height(root->left)+height(root->right)+1;

    int dia = max(d1,max(d2,h));
    

}
int main(){
    Node * root = NULL;

    root = createTree(root);
    
    cout<<"Height of the binary tree is : "<<height(root)<<endl;
    cout<<"Diameter of the binary tree is : "<<diameter(root);
    
   
    return 0;
}