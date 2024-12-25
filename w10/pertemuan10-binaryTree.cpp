#include <iostream>
#include <stdlib.h>     // srand, rand
#include <time.h>       // time

using namespace std;

struct Node {
    int data;
    Node* anakKiri;
    Node* anakKanan;

    Node(int);
};

struct Tree {
    Node* root;

    Tree();
    void sisipDtNode(int);
    void preorderTraversal();
    void inorderTraversal();
    void postorderTraversal();
    int hitungNode();
    int hitungLeaf();
    int hitungHeight();

private:
    void sisipDt(Node*, int);
    void preorder(Node*);
    void inorder(Node*);
    void postorder(Node*);
    int hitungNode(Node*);
    int hitungLeaf(Node*);
    int hitungHeight(Node*);
};

Node::Node(int dt) {
    data = dt;
    anakKiri = anakKanan = NULL;
}

Tree::Tree() {
    root = NULL;
}

void Tree::sisipDtNode(int dtSisip) {
    if (root == NULL)
        root = new Node(dtSisip);
    else
        sisipDt(root, dtSisip);
}

void Tree::preorderTraversal() {
    preorder(root);
}

void Tree::inorderTraversal() {
    inorder(root);
}

void Tree::postorderTraversal() {
    postorder(root);
}

void Tree::sisipDt(Node* node, int dtSisip) {
    if (dtSisip < node->data) {
        if (node->anakKiri == NULL)
            node->anakKiri = new Node(dtSisip);
        else
            sisipDt(node->anakKiri, dtSisip);
    }
    else if (dtSisip > node->data) {
        if (node->anakKanan == NULL)
            node->anakKanan = new Node(dtSisip);
        else
            sisipDt(node->anakKanan, dtSisip);
    }
}

void Tree::preorder(Node* node) {
    if (node == NULL) return;

    cout << node->data << ", ";
    preorder(node->anakKiri);
    preorder(node->anakKanan);
}

void Tree::inorder(Node* node) {
    if (node == NULL) return;

    inorder(node->anakKiri);
    cout << node->data << ", ";
    inorder(node->anakKanan);
}

void Tree::postorder(Node* node) {
    if (node == NULL) return;

    postorder(node->anakKiri);
    postorder(node->anakKanan);
    cout << node->data << ", ";
}

int Tree::hitungNode() {
    return hitungNode(root);
}

int Tree::hitungNode(Node* node) {
    if (node == NULL) return 0;

    int countLeft = hitungNode(node->anakKiri);
    int countRight = hitungNode(node->anakKanan);

    return 1 + countLeft + countRight;
}

int Tree::hitungLeaf() {
    return hitungLeaf(root);
}

int Tree::hitungLeaf(Node* node) {
    if (node == NULL) return 0;

    if (node->anakKiri == NULL && node->anakKanan == NULL)
        return 1;

    int countLeft = hitungLeaf(node->anakKiri);
    int countRight = hitungLeaf(node->anakKanan);

    return countLeft + countRight;
}

int Tree::hitungHeight() {
    return hitungHeight(root);
}

int Tree::hitungHeight(Node* node) {
    if (node == NULL) return -1;
    int leftHeight = hitungHeight(node->anakKiri);
    int rightHeight = hitungHeight(node->anakKanan);

    return max(leftHeight, rightHeight) + 1;
}

int main() {
    Tree* tree = new Tree();
    int nilai;
    cout << "Sisip nilai data berikut: " << endl;

    // sisip data 10 bilangan acak dari 0-99 ke dalam tree
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        nilai = rand() % 100;
        cout << nilai << " ";
        tree->sisipDtNode(nilai);
    }

    cout << "\n\nPreorder Traversal" << endl;
    tree->preorderTraversal();

    cout << "\n\nInorder Traversal" << endl;
    tree->inorderTraversal();

    cout << "\n\nPostorder Traversal" << endl;
    tree->postorderTraversal();

    int jumlahNode = tree->hitungNode();
    cout << "\n\nJumlah Node pada Binary Search Tree: " << jumlahNode << endl;

    int jumlahLeaf = tree->hitungLeaf();
    cout << "Jumlah Leaf pada Binary Search Tree: " << jumlahLeaf << endl;

    int height = tree->hitungHeight();
    cout << "Tinggi Binary Search Tree: " << height << endl;

    return 0;
}