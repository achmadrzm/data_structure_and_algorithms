#include <iostream>
using namespace std;

const int MAX_SIZE = 40;

class BST {
private:
    int tree[MAX_SIZE];
    int size;

public:
    BST() {
        size = 0;
        for (int i = 0; i < MAX_SIZE; i++) {
            tree[i] = 0;
        }
    }

    void insert(int value) {
        if (size >= MAX_SIZE) {
            cout << "Tidak dapat menyisipkan node baru. Batas array tercapai." << endl;
            return;
        }

        if (size == 0) {
            tree[0] = value;
            size++;
            return;
        }

        int currentIndex = 0;
        while (true) {
            if (value <= tree[currentIndex]) {
                if (2 * currentIndex + 1 >= MAX_SIZE) {
                    cout << "Tidak dapat menyisipkan node baru. Batas array tercapai." << endl;
                    return;
                }

                if (tree[2 * currentIndex + 1] == 0) {
                    tree[2 * currentIndex + 1] = value;
                    size++;
                    return;
                } else {
                    currentIndex = 2 * currentIndex + 1;
                }
            } else {
                if (2 * currentIndex + 2 >= MAX_SIZE) {
                    cout << "Tidak dapat menyisipkan node baru. Batas array tercapai." << endl;
                    return;
                }

                if (tree[2 * currentIndex + 2] == 0) {
                    tree[2 * currentIndex + 2] = value;
                    size++;
                    return;
                } else {
                    currentIndex = 2 * currentIndex + 2;
                }
            }
        }
    }

    void printInorder(int index) {
        if (index >= MAX_SIZE || tree[index] == 0) {
            return;
        }

        printInorder(2 * index + 1);
        cout << tree[index] << " ";
        printInorder(2 * index + 2);
    }

    void printTree() {
        cout << "Binary Search Tree (Inorder traversal): ";
        printInorder(0);
        cout << endl;
    }
};

int main() {
    BST bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);
    bst.insert(10);
    bst.insert(90);
    bst.insert(35);

    bst.printTree();

    return 0;
}