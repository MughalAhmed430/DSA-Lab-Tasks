#include<iostream>
using namespace std;

class Person{
    private:
        int id;
        string name;
        int age;
    public:
        Person() : id(0), name(""), age(0) {}

        void input(){
            cout << "\nEnter ID: \t";
            cin >> id;
            cout << "\nEnter the Name of the Person: \t";
            cin.ignore();
            getline(cin, name);
            cout << "\nEnter the Age of the Person: \t";
            cin >> age;
        }

        void output() const{
            cout << "\nPerson details:\n";
            cout << "ID: \t" << id << endl;
            cout << "Name: \t" << name << endl;
            cout << "Age: \t" << age << endl;
        }
};

class Node{
    public:
        Person data;
        Node *next;

        Node(const Person &p) : data(p), next(nullptr) {}
};

class LinearLinkedList{
    private:
        Node *head;

    public:
        LinearLinkedList() : head(nullptr) {}

        void insertAtHead(const Person &p){
            Node *newNode = new Node(p);
            newNode->next = head;
            head = newNode;
            cout << "Person inserted at the head of the list!\n";
        }

        void insertAtTail(const Person &p){
            Node *newNode = new Node(p);
            if (head == nullptr){
                head = newNode;
            }
            else{
                Node *temp = head;
                while (temp->next != nullptr){
                    temp = temp->next;
                }
                temp->next = newNode;
            }
            cout << "Person inserted at the tail of the list!\n";
        }

        void displayList() const{
            if (head == nullptr){
                cout << "The list is empty!\n";
                return;
            }

            Node *temp = head;
            while (temp != nullptr){
                temp->data.output();
                temp = temp->next;
            }
        }

        ~LinearLinkedList(){
            while (head != nullptr){
                Node *temp = head;
                head = head->next;
                delete temp;
            }
        }
};

int main(){
    LinearLinkedList list;
    int choice;

    while (true){
        cout << "1. Insert a person at the head\n";
        cout << "2. Insert a person at the tail\n";
        cout << "3. Display all persons\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: \t";
        cin >> choice;

        if (choice == 1){
            Person p;
            p.input();
            list.insertAtHead(p);
        }
        else if (choice == 2){
            Person p;
            p.input();
            list.insertAtTail(p);
        }
        else if (choice == 3){
            list.displayList();
        }
        else if (choice == 4){
            cout << "Exiting...\n";
            break;
        }
        else{
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}