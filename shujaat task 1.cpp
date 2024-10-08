#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void insertAtPosition(int val, int pos) {
        Node* newNode = new Node(val);
        if (pos == 1) {
            insertAtBeginning(val);
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            insertAtEnd(val);
        } else {
            newNode->next = temp->next;
            if (temp->next != nullptr) {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void deleteFromBeginning() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
    }

    void deleteFromEnd() {
        if (head == nullptr) return;
        Node* temp = head;
        if (head->next == nullptr) {
            head = nullptr;
        } else {
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->prev->next = nullptr;
        }
        delete temp;
    }

    void deleteFromPosition(int pos) {
        if (head == nullptr) return;
        if (pos == 1) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) return;
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }
        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        }
        delete temp;
    }

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertAtBeginning(10);
    dll.printList();
    dll.insertAtEnd(20);
    dll.printList();
    dll.insertAtPosition(15, 2);
    dll.printList();
    dll.deleteFromBeginning();
    dll.printList();
    dll.deleteFromEnd();
    dll.printList();
    dll.deleteFromPosition(1);
    dll.printList();
    return 0;
}
