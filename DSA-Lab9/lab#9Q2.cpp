#include <iostream>
using namespace std;

const int MAX_SIZE = 5;

class Node
{
public:
    int data;
    Node *next;
};

class Queue
{
private:
    Node *front;
    Node *rear;
    int size;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
        size = 0;
    }

    bool isFull()
    {
        return (size == MAX_SIZE);
    }

    bool isEmpty()
    {
        return (size == 0);
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is full. Cannot add more elements." << endl;
            return;
        }

        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (rear == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }

        size++;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot remove elements." << endl;
            return -1;
        }

        int value = front->data;
        Node *temp = front;
        front = front->next;

        if (front == NULL)
        {
            rear = NULL;
        }

        delete temp;
        size--;
        return value;
    }

    void display()
    {
        Node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue q1, q2;

    while (true)
    {
        cout << "1. Enqueue in Q1" << endl;
        cout << "2. Dequeue from Q1 and Enqueue in Q2" << endl;
        cout << "3. Dequeue from Q2" << endl;
        cout << "4. Display Q1" << endl;
        cout << "5. Display Q2" << endl;
        cout << "6. Exit" << endl;
        cout<<"Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int value;
            cout << "Enter value to enqueue in Q1: ";
            cin >> value;
            q1.enqueue(value);
            break;
        }
        case 2:
        {
            int value = q1.dequeue();
            if (value != -1)
            {
                q2.enqueue(value);
            }
            break;
        }
        case 3:
        {
            q2.dequeue();
            break;
        }
        case 4:
        {
            cout << "Q1: ";
            q1.display();
            break;
        }
        case 5:
        {
            cout << "Q2: ";
            q2.display();
            break;
        }
        case 6:
            return 0;
        default:
            cout << "Invalid choice. Please choose again." << endl;
        }
    }

    return 0;
}