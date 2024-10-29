#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtEnd(Node** head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

void deleteNode(Node** head, int key) {
    Node* temp = *head;
    Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        delete temp;
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    delete temp;
}

void insertAtEndArray(vector<int>& arr, int newData) {
    arr.push_back(newData);
}

void deleteFromArray(vector<int>& arr, int key) {
    auto it = find(arr.begin(), arr.end(), key);
    if (it != arr.end()) {
        arr.erase(it);
    } else {
        cout << "Value " << key << " not found in array." << endl;
    }
}

void printList(Node* node) {
    cout << "Linked List: ";
    while (node != NULL) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

void printArray(const vector<int>& arr) {
    cout << "Array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

void freeList(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = NULL;
    vector<int> arr;
    int n, value;

    cout << "How many values do you want to insert? ";
    cin >> n;

    clock_t start = clock();
    for (int i = 0; i < n; i++) {
        cout << "Enter value for Linked List " << i + 1 << ": ";
        cin >> value;
        insertAtEnd(&head, value);
    }
    clock_t end = clock();
    double linkedListInsertionTime = double(end - start) / CLOCKS_PER_SEC;

    start = clock();
    for (int i = 0; i < n; i++) {
        cout << "Enter value for Array " << i + 1 << ": ";
        cin >> value;
        insertAtEndArray(arr, value);
    }
    end = clock();
    double arrayInsertionTime = double(end - start) / CLOCKS_PER_SEC;

    printList(head);
    printArray(arr);

    cout << "Linked List Insertion Time: " << linkedListInsertionTime << " seconds" << endl;
    cout << "Array Insertion Time: " << arrayInsertionTime << " seconds" << endl;

    cout << "Enter value to delete from Linked List: ";
    cin >> value;
    start = clock();
    deleteNode(&head, value);
    end = clock();
    double linkedListDeletionTime = double(end - start) / CLOCKS_PER_SEC;

    cout << "Enter value to delete from Array: ";
    cin >> value;
    start = clock();
    deleteFromArray(arr, value);
    end = clock();
    double arrayDeletionTime = double(end - start) / CLOCKS_PER_SEC;

    printList(head);
    printArray(arr);

    cout << "Linked List Deletion Time: " << linkedListDeletionTime << " seconds" << endl;
    cout << "Array Deletion Time: " << arrayDeletionTime << " seconds" << endl;

    freeList(head); // Free linked list memory

    return 0;
}
