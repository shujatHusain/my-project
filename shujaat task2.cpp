#include <iostream>
#include <string>
using namespace std;
class Person {
    int per_id;
    string per_name;
    int per_age;
public:
    void input() {
        cin >> per_id >> per_name >> per_age;
    }
    void output() {
        cout << per_id << " " << per_name << " " << per_age << endl;
    }
};
struct Node {
    Person data;
    Node* next;
};
class LinkedList {
    Node* head;
    Node* tail;
public:
    LinkedList() : head(nullptr), tail(nullptr) {}
    void insert(Person p) {
        Node* newNode = new Node{p, nullptr};
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void display() {
        Node* temp = head;
        while (temp) {
            temp->data.output();
            temp = temp->next;
        }
    }
};
int main() {
    LinkedList list;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        Person p;
        p.input();
        list.insert(p);
    }
    list.display();
    return 0;
}