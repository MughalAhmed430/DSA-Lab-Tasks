#include<iostream>
#include<string>
using namespace std;

class Person{
    private:
        int id;
        string perName;
        int perAge;
    public:
        Person* next;
        Person(int id = 0, string name = "", int age = 0){
            this->id = id;
            this->perName = name;
            this->perAge = age;
        }
        void input(){
            cout << "Enter ID: \t";
            cin >> id;
            cout << "\nEnter the Name of the Person: \t";
            cin.ignore();
            getline(cin, perName);
            cout << "\nEnter the Age of the Person: \t";
            cin >> perAge;
        }
        void output(){
            cout << "\nID: \t" << id;
            cout << "\nName: \t" << perName;
            cout << "\nAge: \t" << perAge;
        }
};

class LinearLinkedList{
    public:
        void insertAtHead(Person* &head, Person* newNode){
            newNode->next = head;
            head = newNode;
        }

        void display(Person* head){
            while(head!=NULL){
                head->output();
                head=head->next;
            }
        }
};

int main(){
    LinearLinkedList* list=new LinearLinkedList();
    Person* head=NULL;
    int choice=1;
    while(choice){
        Person* new_Node=new Person();
        new_Node->input();
        list->insertAtHead(head, new_Node);
        cout << "\nDo you want to add more? (1 for yes, 0 for no) \t";
        cin >> choice;
    }
    list->display(head);
    return 0;
}