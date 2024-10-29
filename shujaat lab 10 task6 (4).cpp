#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}
bool search(Node* root, int value) {
    if (root == nullptr) return false;
    if (root->data == value) return true;
    else if (value < root->data) return search(root->left, value);
    else return search(root->right, value);
}
int main() {
    Node* root = nullptr;
    int valueToSearch;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    cout << "Enter a value to search in the BST: ";
    cin >> valueToSearch;
    if (search(root, valueToSearch)) {
        cout << "Value " << valueToSearch << " is found in the BST." << endl;
    } else {
        cout << "Value " << valueToSearch << " is not found in the BST." << endl;
    }
    return 0;
}