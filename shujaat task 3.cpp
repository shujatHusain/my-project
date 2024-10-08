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
            newNode->next = head;
            if (head != nullptr) head->prev = newNode;
            head = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Position greater than the length of the list" << endl;
            return;
        }

        newNode->next = temp->next;
        if (temp->next != nullptr) temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        if (head != nullptr) head->prev = nullptr;
        delete temp;
    }

    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

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

    void printList() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

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

    dll.deleteFromBeginning(); // Edge case: deleting from empty list

    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtPosition(30, 5); // Edge case: inserting at a position greater than the length
    dll.printList();

    dll.insertAtEnd(30);
    dll.printList();

    dll.deleteFromBeginning();
    dll.deleteFromEnd();
    dll.printList();

    dll.deleteFromBeginning();
    dll.deleteFromEnd(); // Edge case: deleting further after all nodes are deleted
    dll.printList();

    return 0;
}
