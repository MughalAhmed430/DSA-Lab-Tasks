#include <iostream>
#include <string>

using namespace std;

class Queue {
private:
    struct Node {
        char data;
        Node* next;
    };

    Node* front;
    Node* rear;
    int size;
    int capacity;

public:
    Queue(int capacity = 10) {
        front = nullptr;
        rear = nullptr;
        size = 0;
        this->capacity = capacity;
    }

    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(char data) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }

        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        size++;
    }

    char dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return '\0';
        }

        char data = front->data;
        Node* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
        size--;
        return data;
    }

    char peek() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot peek." << endl;
            return '\0';
        }

        return front->data;
    }

    void clear() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }

        rear = nullptr;
        size = 0;
    }

    void display() {
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int count() {
        return size;
    }
};

int main() {
    Queue queue(5);

    queue.enqueue('A');
    queue.enqueue('B');
    queue.enqueue('C');
    queue.enqueue('D');
    queue.enqueue('E');

    cout << "Queue: ";
    queue.display();

    cout << "Number of elements in the queue: " << queue.count() << endl;

    queue.clear();

    cout << "Queue after clear: ";
    queue.display();

    cout << "Number of elements in the queue after clear: " << queue.count() << endl;

    return 0;
}