#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node() : next(nullptr) {}
};
class LinkedList
{
private:
    Node *headNode;

public:
    LinkedList() : headNode(nullptr) {}
    bool isEmptyList()
    {
        return headNode == nullptr;
    }
    void appendNode(int val)
    {
        Node *newNode = new Node();
        newNode->data = val;

        if (isEmptyList())
        {
            headNode = newNode;
        }
        else
        {
            Node *tempNode = headNode;
            while (tempNode->next != nullptr)
            {
                tempNode = tempNode->next;
            }
            tempNode->next = newNode;
        }
    }
    void insertNodeAtPosition(int val, int pos)
    {
        Node *newNode = new Node();
        newNode->data = val;

        if (pos < 1)
        {
            cout << "Invalid position!" << endl;
            delete newNode; 
            return;
        }

        if (pos == 1)
        {
            newNode->next = headNode;
            headNode = newNode;
            return;
        }

        Node *tempNode = headNode;
        for (int i = 1; i < pos - 1 && tempNode != nullptr; i++)
        {
            tempNode = tempNode->next;
        }

        if (tempNode == nullptr)
        {
            cout << "Position exceeds the list length!" << endl;
            delete newNode; 
        }
        else
        {
            newNode->next = tempNode->next;
            tempNode->next = newNode;
        }
    }
    void removeFromStart()
    {
        if (isEmptyList())
        {
            cout << "List is empty, nothing to delete!" << endl;
            return;
        }

        Node *tempNode = headNode;
        headNode = headNode->next;
        delete tempNode;
    }
    void clearList()
    {
        while (!isEmptyList())
        {
            removeFromStart();
        }
    }
    void displayList()
    {
        if (isEmptyList())
        {
            cout << "The list is empty!" << endl;
            return;
        }

        Node *tempNode = headNode;
        while (tempNode != nullptr)
        {
            cout << tempNode->data << " -> ";
            tempNode = tempNode->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    LinkedList myList;
    int choice, value, position;

    do
    {
        cout << "1. Insert at the end\n";
        cout << "2. Insert at a specific position\n";
        cout << "3. Remove first node\n";
        cout << "4. Clear the list\n";
        cout << "5. Display the list\n";
        cout << "6. Exit\n";
        cout << "Enter your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value to add at the end: ";
            cin >> value;
            myList.appendNode(value);
            break;

        case 2:
            cout << "Enter the value to insert: ";
            cin >> value;
            cout << "Enter position to insert at: ";
            cin >> position;
            myList.insertNodeAtPosition(value, position);
            break;

        case 3:
            myList.removeFromStart();
            break;

        case 4:
            myList.clearList();
            break;

        case 5:
            myList.displayList();
            break;

        case 6:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid selection, please try again." << endl;
            break;
        }
    } while (choice != 6);

    return 0;
}