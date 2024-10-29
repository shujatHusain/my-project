#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
class CircularLinkedList{
public:
    Node* head;
    CircularLinkedList()
    {
        head = nullptr;
    }
    void insertAtEnd(int value)
    {
        Node* newNode = new Node();
        newNode->data = value;
        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
        } else
        {
            Node* temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }
    void deleteNode(int value)
    {
        if (head == nullptr) {
            return;
        }
        Node* current = head;
        Node* previous = nullptr;
        if (head->data == value && head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }
        do {
            if (current->data == value)
            {
                if (current == head)
                {
                    Node* temp = head;
                    while (temp->next != head)
                    {
                        temp = temp->next;
                    }
                    temp->next = head->next;
                    head = head->next;
                } else
                {
                    previous->next = current->next;
                }
                delete current;
                return;
            }
            previous = current;
            current = current->next;
        } while (current != head);
    }
    void traverse()
    {
        if (head == nullptr)
        {
            return;
        }
        Node* temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};
int main()
{
    CircularLinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.traverse();
    list.deleteNode(2);
    list.traverse();
    return 0;
}
