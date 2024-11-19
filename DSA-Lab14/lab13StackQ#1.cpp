#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    struct Node {
        char data;
        Node* next;
    };

    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    ~Stack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(char data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return '\0';
        }

        char data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return data;
    }

    char peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot peek." << endl;
            return '\0';
        }

        return top->data;
    }

    void clear() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

void reverseString(string str) {
    Stack stack;
    for (int i = 0; i < str.length(); i++) {
        stack.push(str[i]);
    }

    string reversedStr = "";
    while (!stack.isEmpty()) {
        reversedStr += stack.pop();
    }

    cout << "Reversed string: " << reversedStr << endl;
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    reverseString(str);

    return 0;
}