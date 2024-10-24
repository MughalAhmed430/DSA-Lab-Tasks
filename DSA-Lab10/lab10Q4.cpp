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

void inOrderTraversal(Node* root) {
    if (root == nullptr)
        return;

    inOrderTraversal(root->left);

    cout << root->data << " ";

    inOrderTraversal(root->right);
}

void preOrderTraversal(Node* root) {
    if (root == nullptr)
        return;
    cout<< root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node* root) {
    if (root == nullptr)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<< root->data << " ";
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

    cout << "In-Order traversal of the BST: ";
    inOrderTraversal(root);

    cout << "Pre-order traversal of the BST: ";
    preOrderTraversal(root);

    cout << "Post-Order traversal of the BST: ";
    postOrderTraversal(root);

    return 0;
}