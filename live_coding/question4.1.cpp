#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    stack<string> commandStack; // stack untuk menyimpan perintah
    stack<string> redoStack; // stack untuk menyimpan perintah yang telah di-undo

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;

        if (command == "undo") {
            if (!commandStack.empty()) { // cek apakah ada perintah yang dapat di-undo
                redoStack.push(commandStack.top()); // masukkan perintah terakhir dari stack perintah ke stack redo
                commandStack.pop(); // keluarkan perintah terakhir dari stack perintah
            }
        } else if (command == "redo") {
            if (!redoStack.empty()) { // cek apakah ada perintah yang dapat di-redo
                commandStack.push(redoStack.top()); // masukkan perintah terakhir dari stack redo ke stack perintah
                redoStack.pop(); // keluarkan perintah terakhir dari stack redo
            }
        } else {
            commandStack.push(command); // masukkan perintah ke stack perintah
            while (!redoStack.empty()) { // kosongkan stack redo
                redoStack.pop();
            }
        }
    }

    stack<string> tempStack; // stack sementara untuk membalik urutan output
    while (!commandStack.empty()) { // keluarkan semua perintah dari stack perintah dan masukkan ke stack sementara
        tempStack.push(commandStack.top());
        commandStack.pop();
    }

    while (!tempStack.empty()) { // keluarkan semua perintah dari stack sementara dan tampilkan output
        cout << tempStack.top() << endl;
        tempStack.pop();
    }

    return 0;
}