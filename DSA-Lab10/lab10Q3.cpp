#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int value) {
    
    if (root == nullptr) {
        return createNode(value);
    }
    
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

bool search(Node* root,int value){
    if (root==nullptr)
    {
        return false;
    }
    if (root->data==value)
    {
        return true;
    }
    if (value<root->data)
    {
        return search(root->left,value);
    }else{
        return search(root->right,value);
    }
}


int main() {
    Node* root = nullptr;

    int val;
    cout<<"Enter the number of Value:"<<endl;
    cin>>val;
    int arr;
    for (int i = 0; i < val; i++)
    {
        cout<<"Enter the Intergers Value:"<<endl;
        cin>>arr;
        root = insert(root, arr);
    }

    int key=40;
    if (search(root,key)){
        cout<< key << " found in the BST\n";
    }else
    {
        cout<< key << "not found in the BST\n";
    }
    
    return 0;
}