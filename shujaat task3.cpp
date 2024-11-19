#include <iostream>
using namespace std;

class Queue {
    struct Node {
        int data;
        Node* next;
    };
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    ~Queue() {
        clear();
    }

    void enqueue(int item) {
        Node* newNode = new Node;
        newNode->data = item;
        newNode->next = nullptr;
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
            if (front == nullptr) {
                rear = nullptr;
            }
        } else {
            cout << "Queue is empty. Cannot dequeue." << endl;
        }
    }

    void clear() {
        while (front != nullptr) {
            dequeue();
        }
    }

    bool isEmpty() const {
        return front == nullptr;
    }

    void display() {
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.clear();
    q.display();
    return 0;
}