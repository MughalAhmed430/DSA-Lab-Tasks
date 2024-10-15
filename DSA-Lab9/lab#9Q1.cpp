#include <iostream>
using namespace std;

class Person {
private:
    int perID, perAge;
    string perName;
public:
    Person(int id = 0, int age = 0, string name = "") {
        perID = id;
        perAge = age;
        perName = name;
    }

    void input() {
        cout << "Enter ID: \t";
        cin >> perID;
        cout << "\nEnter the Name of the Person: \t";
        cin.ignore();
        getline(cin, perName);
        cout << "\nEnter the Age of the Person: \t";
        cin >> perAge;
    }

    void output() {
        cout << "\nID: \t" << perID;
        cout << "\nName: \t" << perName;
        cout << "\nAge: \t" << perAge;
    }
};

class Node {
public:
    Person data;
    Node* next;
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = NULL;
    }

    void addNode() {
        Node* newNode = new Node();
        newNode->data.input();
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void displayList() {
        Node* temp = head;
        while (temp != NULL) {
            temp->data.output();
            temp = temp->next;
        }
    }

    void deleteNode() {
        if (head == NULL) {
            cout << "List is empty. Cannot delete node." << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }
};

int main() {
    LinkedList list;

    while (true) {
        cout << "1. Add node" << endl;
        cout << "2. Display list" << endl;
        cout << "3. Delete node" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: " << endl;
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                list.addNode();
                break;
            case 2:
                list.displayList();
                break;
            case 3:
                list.deleteNode();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Please choose again." << endl;
        }
    }

    return 0;
}