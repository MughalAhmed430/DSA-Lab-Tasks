#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
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

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void deleteAtPosition(int position) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        if (position == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "\nHead node deleted.\n";
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position - 1 && temp->next != nullptr; ++i) {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr) {
            cout << "Position out of range!" << endl;
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
        cout << "\nNode at position " << position << " deleted.\n";
    }

    void displayList() {
        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "Null" << endl;
    }
};

void insertInArray(int arr[], int& size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter the value " << i + 1 << " : ";
        cin >> arr[i];
    }
}

void deleteFromArray(int arr[], int& size, int position) {
    if (position < 0 || position >= size) {
        cout << "\nInvalid position\n";
        return;
    }

    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    cout << "\nElement deleted successfully\n";
}

void displayArray(int arr[], int size) {
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    LinkedList list;
    int n, del, value;
    int size = 0, pos;
    int choice;
    int arr[100];

    while (true) {
        cout << "\n--- Linked List Operations ---\n";
        cout << "1. Insert (Linked List)\n2. Delete (Linked List)\n3. Display (Linked List)\n";
        cout << "\n--- Array Operations ---\n";
        cout << "4. Insert (Array)\n5. Delete (Array)\n6. Display (Array)\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter the number of elements you want to enter: ";
            cin >> n;
            for (int i = 0; i < n; i++) {
                cout << "\nEnter the value " << i + 1 << " : ";
                cin >> value;
                list.insertAtEnd(value);
            }
        } else if (choice == 2) {
            cout << "\nPlease enter the index of the node you want to delete: ";
            cin >> del;
            list.deleteAtPosition(del);
        } else if (choice == 3) {
            cout << "\nCurrent values in the list:\n";
            list.displayList();
        } else if (choice == 4) {
            cout << "Enter the number of elements you want to insert into the array: ";
            cin >> size;
            insertInArray(arr, size);
        } else if (choice == 5) {
            cout << "\nPlease enter the index of the element you want to delete: ";
            cin >> pos;
            deleteFromArray(arr, size, pos);
        } else if (choice == 6) {
            displayArray(arr, size);
        } else if (choice == 7) {
            cout << "Exiting...\n";
            break;
        } else {
            cout << "\nInvalid choice!" << endl;
        }
    }

    return 0;
}
