#include <iostream>

using namespace std;

struct Node {
    int dest;
    int weight;
    Node *next;
};

struct Graph {
    Node **node;
    int jNode;
    Graph(int);
    void addAdj(int, int, int);
    void cetak(string);
    void clean();
};

Graph::Graph(int jumlah) {
    jNode = jumlah;
    node = new Node*[jNode];
    for (int i = 0; i < jNode; i++)
        node[i] = NULL;
}

void Graph::addAdj(int head, int adj, int weight) {
    Node *n = new Node();
    n->dest = adj;
    n->weight = weight;
    n->next = node[head];
    node[head] = n;
}

void Graph::cetak(string komentar) {
    cout << komentar << endl;
    for (int i = 0; i < jNode; i++) {
        cout << "[" << i << "]";
        Node *n = node[i];
        while (n != NULL) {
            cout << "-> (" << n->dest << ", " << n->weight << ")";
            n = n->next;
        }
        cout << endl;
    }
}

void Graph::clean() {
    for (int i = 0; i < jNode; i++) {
        Node *n = node[i];
        while (n != NULL) {
            Node *temp = n;
            n = n->next;
            delete temp;
        }
    }
    delete [] node;
}

int main() {
    Graph *g = new Graph(5);
    g->addAdj(0, 3, 4);
    g->addAdj(0, 1, 2);
    g->addAdj(1, 4, 3);
    g->addAdj(1, 2, 1);
    g->addAdj(2, 4, 5);
    g->addAdj(2, 1, 1);
    g->addAdj(4, 3, 6);
    g->cetak("Kondisi awal");
    g->clean();
    return 0;
}