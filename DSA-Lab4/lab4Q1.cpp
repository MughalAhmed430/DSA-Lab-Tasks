#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next=NULL;
    }
};

void insertAtHead(Node* &head,int val){
    Node* new_Node=new Node(val);
    new_Node->next=head;
    head=new_Node;
}

void insertAtPosition(Node* &head,int val,int pos){
    Node* temp=head;
    Node* new_Node=new Node(val);
    int currentPos=0;
    while (currentPos!=pos-1)
    {
        temp=temp->next;
        currentPos++;
    }
    new_Node->next=temp->next;
    temp->next=new_Node;
    
}

void deleteAtHead(Node* &head){
    Node* temp=head;
    head=head->next;
    free(temp);
}

void deleteAtAnyPosition(Node*& head,int pos){
    if (pos==0)
    {
        deleteAtHead(head);   
    }
    int current = 0;
    Node* prev = head;
    while (current != pos - 1 ) {
        prev = prev->next;
        current++;
    }
    Node* tem = prev->next;
    prev->next = prev->next->next;
    free(tem);
}


bool searchNode(Node* &head, int val, int& position) {
    Node* currentPos = head;
    position = 0; 

    while (currentPos != NULL) {
        if (currentPos->data == val) {
            return true;
        }
        currentPos = currentPos->next;
        position++; 
    }

    return false;
}
void display(Node* head){
    Node* temp=head;
    while (temp!=NULL){
        cout<<temp->data<<" ->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;    
}
int main(){
    Node* head=NULL;
    const int size=5;
    int num,pos,key,value,position;

    int array[size];

    for (int i = 0; i < size; i++)
    {
        cout<<"Enter Value "<< i+1 << ":" <<endl;
        cin>>array[i];
        insertAtHead(head,array[i]);
    }  
    display(head);

    cout<<"Enter the Value you want to insert:\t";
    cin>>num;

    cout<<"Enter the Position where you want to insert:\t";
    cin>>pos;

    cout<<endl;
    insertAtPosition(head,num,pos);
    display(head);
    deleteAtHead(head);
    cout<<"After Deleting the head"<<endl;
    display(head);

    cout<<"Enter the Number you want to Search in the linked list:\t";
    cin>>value;
   
    if ( searchNode(head,value,position)) {
        cout << "Value " << value << " found at position " << position << endl;
    } else {
        cout << "Value " << value << " not found in the linked list" << endl;
    }

    return 0;
}