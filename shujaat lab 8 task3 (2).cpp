#include <iostream>
using namespace std;
struct Node{
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
    return 0;
}
