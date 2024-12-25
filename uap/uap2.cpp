#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//Tidak ada template untuk C++, sorry ga sempet bikin :(
//Tapi soalnya gampang dan waktunya 1 setengah jam, so it should be fine... Goodluck

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    if (newNode) {
        newNode->data = value;
        newNode->left = newNode->right = nullptr;
    }
    return newNode;
}

Node* insertNode(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }

    return root;
}

int sumNonRootLeafNodes(Node* root) {
    if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
        return 0;
    }

    int sum = 0;

    if (root->left != nullptr && !(root->left->left == nullptr && root->left->right == nullptr)) {
        sum += root->left->data;
    }

    if (root->right != nullptr && !(root->right->left == nullptr && root->right->right == nullptr)) {
        sum += root->right->data;
    }

    sum += sumNonRootLeafNodes(root->left);
    sum += sumNonRootLeafNodes(root->right);

    return sum;
}

int main() {
    int n;
    cin >> n;
    
    Node* root = nullptr;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        root = insertNode(root, value);
    }

    int sum = sumNonRootLeafNodes(root);
    cout << sum << endl;

    return 0;
}