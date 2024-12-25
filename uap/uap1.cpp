#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* insertNode(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

void calculateDifference(Node* root, unordered_set<int>& differences, int level) {
    if (root == nullptr) {
        return;
    }

    if (root->left != nullptr) {
        differences.insert(root->data - root->left->data);
        calculateDifference(root->left, differences, level + 1);
    }

    if (root->right != nullptr) {
        differences.insert(root->data - root->right->data);
        calculateDifference(root->right, differences, level + 1);
    }
}

int main() {
    int n;
    cin >> n;

    Node* root = nullptr;

    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        root = insertNode(root, data);
    }

    unordered_set<int> differences;
    calculateDifference(root, differences, 0);

    int sum = 0;
    for (int diff : differences) {
        sum += diff;
    }

    cout << sum << endl;

    return 0;
}