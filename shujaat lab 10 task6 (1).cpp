#include <iostream>
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
void inOrderTraversal(Node* root, int* arr, int& index) {
    if (root == nullptr) return;
    inOrderTraversal(root->left, arr, index);
    arr[index++] = root->data;
    inOrderTraversal(root->right, arr, index);
}
void sortArrayUsingBST(int* arr, int size) {
    Node* root = nullptr;
    for (int i = 0; i < size; i++) {
        root = insert(root, arr[i]);
    }
    int index = 0;
    inOrderTraversal(root, arr, index);
}
int main() {
    int arr[] = {50, 30, 20, 40, 70, 60, 80};
    int size = sizeof(arr) / sizeof(arr[0]);
    sortArrayUsingBST(arr, size);
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}