#include <iostream>
using namespace std;

class Node
{
public:
    int data;      
    Node *next;     
    Node *prev;     
    Node(int value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

void insertAtEnd(Node *&head, int value)
{
    Node *newNode = new Node(value); 

    if (head == nullptr)
    {
        newNode->prev = nullptr; 
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next; 
        }
        temp->next = newNode; 
        newNode->prev = temp; 
    }
}

void findMiddle(Node *head)
{
    if (head == nullptr)
    {
        cout << "The list is empty.\n";
        return;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;       
        fast = fast->next->next; 
    }
    cout << "\nThe middle element is: " << slow->data << endl;
}

void display(Node *head)
{
    if (head == nullptr)
    {
        cout << "List is empty.\n";
        return;
    }

    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main()
{
    Node *head = nullptr;
    int value, n;

    cout << "How many values would you like to insert initially? ";
    cin >> n;

    cout << "Enter " << n << " values to insert into the list:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        insertAtEnd(head, value); 
    }

    cout << "\nInitial linked list: \n";
    display(head);

    findMiddle(head);

    return 0;
}
