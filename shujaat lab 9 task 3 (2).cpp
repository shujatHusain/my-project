#include <iostream>
#include <string>
using namespace std;
class person {
    int per_id;
    string per_name;
    int per_age;
public:
    person(int id, string name, int age) {
        per_id = id;
        per_name = name;
        per_age = age;
    }
    void input() {
        cout << "Enter ID: ";
        cin >> per_id;
        cout << "Enter Name: ";
        cin >> per_name;
        cout << "Enter Age: ";
        cin >> per_age;
    }
    void output() {
        cout << "ID: " << per_id << ", Name: " << per_name << ", Age: " << per_age << endl;
    }
};
class Node {
public:
    person data;
    Node* next;
    Node(person p) : data(p), next(nullptr) {}
};
class Queue {
    Node* front;
    Node* rear;
public:
    Queue() {
        front = rear = nullptr;
    }
    void addQueue(person p) {
        Node* newNode = new Node(p);
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }
    void removeQueue() {
        if (front == nullptr) return;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        delete temp;
    }
    bool isEmpty() {
        return front == nullptr;
    }
    void display() {
        Node* temp = front;
        while (temp != nullptr) {
            temp->data.output();
            temp = temp->next;
        }
    }
};
int main() {
    Queue q;
    person p1(1, "Alice", 30);
    person p2(2, "Bob", 25);
    person p3(3, "Charlie", 35);
    q.addQueue(p1);
    q.addQueue(p2);
    q.addQueue(p3);
    cout << "Queue contents:" << endl;
    q.display();
    q.removeQueue();
    cout << "Queue after removing one element:" << endl;
    q.display();
    return 0;
}
