#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> shortestPath(vector<vector<int>>& graph, int start, int treasure) {
    int N = graph.size();

    vector<bool> visited(N, false); // untuk melacak simpul yang telah dikunjungi
    vector<int> prev(N, -1); // untuk melacak simpul sebelumnya dalam jalur terpendek
    queue<int> q; // antrian BFS

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        // Cek apakah simpul saat ini adalah simpul dengan harta karun
        if (current == treasure)
            break;

        // Cari semua tetangga simpul saat ini yang belum dikunjungi
        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                prev[neighbor] = current;
                q.push(neighbor);
            }
        }
    }

    // Jika tidak ada jalur yang ditemukan, kembalikan jalur kosong
    if (!visited[treasure])
        return {};

    // Rekonstruksi jalur terpendek dari simpul awal ke simpul dengan harta karun
    vector<int> path;
    int current = treasure;
    while (current != -1) {
        path.push_back(current);
        current = prev[current];
    }
    reverse(path.begin(), path.end());

    return path;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N);

    for (int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        graph[U].push_back(V);
        graph[V].push_back(U);
    }

    int start, treasure;
    cin >> start >> treasure;

    vector<int> path = shortestPath(graph, start, treasure);

    if (path.empty()) {
        cout << -1 << endl;
    } else {
        for (std::vector<int>::size_type i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i != path.size() - 1)
                cout << " -> ";
        }
        cout << endl;
    }

    return 0;
}