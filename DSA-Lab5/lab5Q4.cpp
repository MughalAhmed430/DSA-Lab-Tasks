#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() {
        data = 0;
        next = nullptr;
    }

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void findMiddle() {
        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (slow != nullptr) {
            cout << "The middle element is: " << slow->data << endl;
        }
    }
};

int main() {
    cout << "*** LAB 5 ***" << endl;
    LinkedList list;
    int size;
    cout << "How many values do you want to enter in the linked list? " << endl;
    cin >> size;
    int value;
    for (int i = 0; i < size; i++) {
        cout << "Enter the value for block " << i + 1 << " of the linked list: " << endl;
        cin >> value;
        if (value > 0) {
            list.insertAtBeginning(value);
        }
    }
    cout << "Linked List is: " << endl;
    list.printList();
    cout << "\nFinding the middle element of the linked list..." << endl;
    list.findMiddle();
    return 0;
}
