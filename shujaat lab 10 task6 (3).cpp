#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        root = new Node();
        root->data = value;
        root->left = root->right = nullptr;
    } else if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}
void inOrderTraversal(Node* root) {
    if (root == nullptr) return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}
void preOrderTraversal(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void postOrderTraversal(Node* root) {
    if (root == nullptr) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}
int main() {
    Node* root = nullptr;
    int values[7];
    cout << "Enter 7 values to insert in the BST: ";
    for (int i = 0; i < 7; i++) {
        cin >> values[i];
        root = insert(root, values[i]);
    }
    cout << "In-order traversal: ";
    inOrderTraversal(root);
    cout << endl;
    cout << "Pre-order traversal: ";
    preOrderTraversal(root);
    cout << endl;
    cout << "Post-order traversal: ";
    postOrderTraversal(root);
    cout << endl;
    return 0;
}