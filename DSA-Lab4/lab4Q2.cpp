#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *Next;
};

void insertatbegining(Node *&head, int value)
{                           
    Node *new_node = new Node(); 
    new_node->data = value;
    new_node->Next = head;
    head = new_node;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->Next;
    }
    cout << "NULL" << endl;
}

void reverseList(Node *&head)
{
    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL;

    while (current != NULL)
    {
        next = current->Next;
        current->Next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
int main()
{
   
    Node *head = NULL;
    int size;
    cout << "How many values do you want to add " << endl;
    cin >> size;
    int value;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the value for block " << i + 1 << " of the linked list: " << endl;
        cin >> value;
        if (value > 0)
        {
            insertatbegining(head, value);
        }
    }
    cout << "Linked List is: " << endl;
    display(head);
    cout << "\nReversing the linked list..." << endl;
    reverseList(head);
    cout << "Reversed Linked List is: " << endl;
    display(head);
    return 0;
}