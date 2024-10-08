#include <iostream>
using namespace std;

class Node
{
public:
    int dataValue;  
    Node *nextNode; 
    Node(int value)
    {
        dataValue = value;
        nextNode = nullptr;
    }
};
class LinkedList
{
private:
    Node *headNode; 
    int listLength; 

public:
    LinkedList() : headNode(nullptr), listLength(0) {}

    bool isEmpty()
    {
        return headNode == nullptr;
    }

    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value); 
        if (isEmpty())
        {
            headNode = newNode;
        }
        else
        {
            Node *tempNode = headNode;
            while (tempNode->nextNode != nullptr)
            {
                tempNode = tempNode->nextNode;
            }
            tempNode->nextNode = newNode; 
        }
        listLength++; 
    }
    void insertAtPosition(int value, int pos)
    {
        if (pos < 1)
        {
            cout << "Invalid position!" << endl;
            return;
        }

        if (pos > listLength + 1)
        {
            cout << "Position exceeds the current length of the list!" << endl;
            return;
        }

        Node *newNode = new Node(value); 

        if (pos == 1)
        {
            newNode->nextNode = headNode; 
            headNode = newNode;
        }
        else
        {
            Node *tempNode = headNode;
            for (int i = 1; i < pos - 1 && tempNode != nullptr; i++)
            {
                tempNode = tempNode->nextNode;
            }
            newNode->nextNode = tempNode->nextNode;
            tempNode->nextNode = newNode;
        }
        listLength++;
    }
    void deleteFromStart()
    {
        if (isEmpty())
        {
            cout << "List is empty, nothing to delete!" << endl;
            return;
        }

        Node *tempNode = headNode;
        headNode = headNode->nextNode; 
        delete tempNode;               
        listLength--;                  
    }

    void deleteAllNodes()
    {
        if (isEmpty())
        {
            cout << "List is already empty, nothing to delete!" << endl;
            return;
        }

        while (!isEmpty())
        {
            deleteFromStart(); 
        }

        cout << "All nodes have been deleted." << endl;
    }
    void printList()
    {
        if (isEmpty())
        {
            cout << "The list is empty!" << endl;
            return;
        }

        Node *tempNode = headNode;
        while (tempNode != nullptr)
        {
            cout << tempNode->dataValue << " -> ";
            tempNode = tempNode->nextNode;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    LinkedList myList;
    int option, inputValue, pos;

    do
    {
        cout << "1. Insert node at end\n";
        cout << "2. Insert node at position\n";
        cout << "3. Delete node from start\n";
        cout << "4. Delete all nodes\n";
        cout << "5. Display list\n";
        cout << "6. Exit\n";
        cout << "Enter your option: ";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Enter value to insert at end: ";
            cin >> inputValue;
            myList.insertAtEnd(inputValue);
            break;

        case 2:
            cout << "Enter the value to insert: ";
            cin >> inputValue;
            cout << "Enter the position to insert at: ";
            cin >> pos;
            myList.insertAtPosition(inputValue, pos);
            break;

        case 3:
            myList.deleteFromStart();
            break;

        case 4:
            myList.deleteAllNodes();
            break;

        case 5:
            myList.printList();
            break;

        case 6:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid option! Please try again." << endl;
            break;
        }
    } while (option != 6);

    return 0;
}
