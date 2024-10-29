#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* prev;
    Node* next;
};

void insertAtBeginning(Node** head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = *head;
    newNode->prev = nullptr;

    if (*head != nullptr) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void insertAtEnd(Node** head, int newData) {
    Node* newNode = new Node();
    Node* last = *head;
    newNode->data = newData;
    newNode->next = nullptr;

    if (*head == nullptr) {
        newNode->prev = nullptr;
        *head = newNode;
        return;
    }

    while (last->next != nullptr) {
        last = last->next;
    }

    last->next = newNode;
    newNode->prev = last;
}

void insertAtPosition(Node** head, int newData, int position) {
    if (position == 1) {
        insertAtBeginning(head, newData);
        return;
    }

    Node* newNode = new Node();
    newNode->data = newData;
    Node* temp = *head;

    for (int i = 1; temp != nullptr && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Position out of bounds." << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void deleteFromBeginning(Node** head) {
    if (*head == nullptr) return;
    
    Node* temp = *head;
    *head = (*head)->next;
    
    if (*head != nullptr) {
        (*head)->prev = nullptr;
    }
    delete temp;
}

void deleteFromEnd(Node** head) {
    if (*head == nullptr) return;

    Node* temp = *head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    if (temp->prev != nullptr) {
        temp->prev->next = nullptr;
    } else {
        *head = nullptr;
    }
    delete temp;
}

void deleteFromPosition(Node** head, int position) {
    if (*head == nullptr || position <= 0) return;

    Node* temp = *head;

    if (position == 1) {
        deleteFromBeginning(head);
        return;
    }

    for (int i = 1; temp != nullptr && i < position; i++) {
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

void printForward(Node* node) {
    cout << "Forward traversal: ";
    while (node != nullptr) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtBeginning(&head, 5);
    insertAtPosition(&head, 15, 3);

    printForward(head);

    deleteFromBeginning(&head);
    printForward(head);

    deleteFromEnd(&head);
    printForward(head);

    deleteFromPosition(&head, 2);
    printForward(head);

    return 0;
}
