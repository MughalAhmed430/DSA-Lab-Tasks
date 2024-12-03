#include <iostream>
using namespace std;

class ListNode {
public:
    int value;
    ListNode* next;

    ListNode() {
        next = NULL;
    }
};

void insertAtFront(ListNode* &head, int data) {
    ListNode* newNode = new ListNode();
    newNode->value = data;
    newNode->next = head;
    head = newNode;
}

void displayList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        cout << current->value << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

void reverseLinkedList(ListNode*& head) {
    ListNode* previous = NULL;
    ListNode* current = head;
    ListNode* nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }
    head = previous;
}

int main() {
     cout << "*** LAB 5 Revision ***" << endl;
    cout << "*** LINKED LIST OPERATIONS ***" << endl;
    ListNode* head = NULL;
    int count;
    cout << "How many nodes do you want to add to the linked list? " << endl;
    cin >> count;
    int data;
    for (int i = 0; i < count; i++) {
        cout << "Enter the value for node " << i + 1 << " of the linked list: " << endl;
        cin >> data;
        if (data > 0) {
            insertAtFront(head, data);
        }
    }
    cout << "Current Linked List: " << endl;
    displayList(head);

    cout << "\nReversing the linked list..." << endl;
    reverseLinkedList(head);
    cout << "Reversed Linked List: " << endl;
    displayList(head);

    return 0;
}
