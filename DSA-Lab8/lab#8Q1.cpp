#include <iostream>
using namespace std;

class Student
{
private:
    int regNum;
    string stdName;
    float cgpa;

public:
    Student(int reg_no, string name, float CGPA)
    {
        regNum = reg_no;
        stdName = name;
        cgpa = CGPA;
    }

    Student() : regNum(0), stdName(""), cgpa(0.0) {}

    void input()
    {
        cout << "Enter the Registration Number: \t";
        cin >> regNum;
        cout << "\nEnter the Student Name: \t";
        cin.ignore();
        getline(cin, stdName);
        cout << "\nEnter the CGPA: \t";
        cin >> cgpa;
    }

    void output()
    {
        cout << "\nRegistration Number: \t" << regNum;
        cout << "\nStudent Name: \t" << stdName;
        cout << "\nCGPA: \t" << cgpa;
    }
};

class Stack
{
private:
    Student *arr;
    int size;
    int top;

public:
    Stack(int size)
    {
        this->size = size;
        arr = new Student[size];
        top = -1;
    }

    ~Stack()
    {
        delete[] arr;
    }

    void push()
    {
        if (top == size - 1)
        {
            cout << "Stack is full. Cannot push more elements." << endl;
            return;
        }
        top++;
        arr[top].input();
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty. Cannot pop more elements." << endl;
            return;
        }
        arr[top].output();
        top--;
    }
};

int main()
{
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;

    Stack stack(size);

    while (true)
    {
        cout << "\n1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Exit" << endl;
        cout << " Enter your choice:" << endl;
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            stack.push();
            break;
        case 2:
            stack.pop();
            break;
        case 3:
            return 0;
        default:
            cout << "Invalid choice. Please choose again." << endl;
        }
    }

    return 0;
}