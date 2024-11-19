#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
class LinkedList {
private:
    Node* head;
    Node* tail;
    bool insertAtHead;
public:
    LinkedList() : head(nullptr), tail(nullptr), insertAtHead(true) {}
    void insert(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            if (insertAtHead) {
                newNode->next = head;
                head = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
        insertAtHead = !insertAtHead;
    }
    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};
int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.display();
    return 0;
}