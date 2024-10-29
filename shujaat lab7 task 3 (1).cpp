#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    DoublyLinkedList() : head(nullptr) {}

    void deleteFromEmptyList() {
        if (!head) {
            cout << "List is empty." << endl;
        }
    }

    void insertAtPosition(int data, int position) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        if (position <= 0) {
            cout << "Invalid position." << endl;
            return;
        }

        if (position == 1) {
            newNode->next = head;
            if (head != nullptr) {
                head->prev = newNode;
            }
            head = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 1; i < position - 1 && temp; ++i) {
            temp = temp->next;
        }

        if (!temp) {
            cout << "Position is out of bounds." << endl;
        } else {
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next != nullptr) {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
        }
    }

    void deleteAllNodes() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        cout << "All nodes deleted." << endl;
    }

    void deleteFurther() {
        if (!head) {
            cout << "No nodes to delete." << endl;
        }
    }

    void printForward() {
        Node* temp = head;
        cout << "Forward traversal: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

private:
    Node* head;
};

int main() {
    DoublyLinkedList list;

    list.deleteFromEmptyList();

    list.insertAtPosition(10, 5);

    list.deleteAllNodes();
    list.deleteFurther();

    return 0;
}
