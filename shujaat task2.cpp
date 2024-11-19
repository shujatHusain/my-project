#include <iostream>
using namespace std;

class Node {
public:
    Node* next;
    int data;

    Node(int value) {
        next = NULL;
        data = value;
    }
};

class Queue {
    Node* front;
    Node* rear;
    int size;

public:
    Queue() {
        front = rear = NULL;
        size = 0;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    int dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow!" << endl;
            return -1;
        }
        Node* temp = front;
        int value = front->data;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        delete temp;
        size--;
        return value;
    }

    int count() {
        return size;
    }

    void display() {
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Queue elements: ";
    q.display();
    cout << "Number of elements in the queue: " << q.count() << endl;
    q.dequeue();
    cout << "Queue elements after dequeue: ";
    q.display();
    cout << "Number of elements in the queue: " << q.count() << endl;

    return 0;
}
