//failed
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Song {
    string title;
    string artist;
    Song *next = NULL;
    Song *prev = NULL;
};

struct Playlist {
    string name;
    Song *head = NULL;
    Song *tail = NULL;
    Playlist *next = NULL;
    Playlist *prev = NULL;
};

Playlist *currentPlaylist = NULL;

bool isEmpty(Song *head) {
    return head == NULL;
}

bool isEmpty(Playlist *head) {
    return head == NULL;
}

void addFront(Song *&head, Song *&tail, string title, string artist) {
    Song *newNode = new Song;
    newNode->title = title;
    newNode->artist = artist;
    newNode->prev = tail;
    newNode->next = head;

    if (isEmpty(head)) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
}

void addBack(Song *&head, Song *&tail, string title, string artist) {
    Song *newNode = new Song;
    newNode->title = title;
    newNode->artist = artist;
    newNode->prev = tail;
    newNode->next = head;

    if (isEmpty(head)) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        head->prev = newNode;
        tail = newNode;
    }
}

void removeFront(Song *&head, Song *&tail) {
    if (!isEmpty(head)) {
        if (tail == head) {
            tail = head = NULL;
            return;
        }

        Song *temp = head;
        head = head->next;
        head->prev = tail;
        tail->next = head;
        delete temp;
    }
}

void removeBack(Song *&head, Song *&tail) {
    if (!isEmpty(head)) {
        if (tail == head) {
            tail = head = NULL;
            return;
        }

        Song *temp = tail;
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        delete temp;
    }
}

void removeSong(Song *&head, Song *&tail, string title) {
    if (head->title == title) {
        removeFront(head, tail);
        return;
    }

    if (tail->title == title) {
        removeBack(head, tail);
        return;
    }

    if (!isEmpty(head)) {
        Song *temp = head;

        do {
            if (temp->next->title == title) {
                Song *del = temp->next;
                temp->next = del->next;
                del->next->prev = temp;
                delete del;
            }
            temp = temp->next;
        } while (temp != head);
    }
}

void createPlaylist(Playlist *&head, Playlist *&tail, string name) {
    Playlist *newPlaylist = new Playlist;
    newPlaylist->name = name;
    newPlaylist->next = NULL;
    newPlaylist->prev = tail;

    if (isEmpty(head)) {
        head = tail = newPlaylist;
    } else {
        tail->next = newPlaylist;
        tail = newPlaylist;
    }
}

void changePlaylist(Playlist* &currentPlaylist, Playlist* headPlaylist) {
    string namaPlaylist;

    cout << "Nama playlist yang ingin diubah: ";
    cin.ignore();
    getline(cin, namaPlaylist);

    Playlist *temp = headPlaylist;

    while (temp != NULL) {
        if (temp->name == namaPlaylist) {
            currentPlaylist = temp;
            cout << "Playlist saat ini : " << currentPlaylist->name << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Playlist tidak ditemukan" << endl;
}

void playSong(Song* currentSong) {
    if (currentSong == NULL) {
        cout << "Playlist kosong" << endl;
    }
    else {
        cout << "Memutar lagu : " << currentSong->title << " | Artist : " << currentSong->artist << endl;
    }
}

void nextSong(Song* &currentSong, Playlist* currentPlaylist) {
    if (currentSong == NULL) {
        cout << "Playlist kosong" << endl;
    }
    else if (currentSong->next == NULL) {
        cout << "Tidak ada lagu selanjutnya" << endl;
    }
    else {
        currentSong = currentSong->next;
        cout << "Memutar lagu : " << currentSong->title << " | Artist : " << currentSong->artist << endl;
    }
}

void prevSong(Song* &currentSong, Playlist* currentPlaylist) {
    if (currentSong == NULL) {
        cout << "Playlist kosong" << endl;
    }
    else if (currentSong->prev == NULL) {
        cout << "Tidak ada lagu sebelumnya" << endl;
    }
    else {
        currentSong = currentSong->prev;
        cout << "Memutar lagu : " << currentSong->title << " | Artist : " << currentSong->artist << endl;
    }
}

void seePlaylist(Playlist* headPlaylist) {
    if (headPlaylist == NULL) {
        cout << "Belum ada playlist yang dibuat" << endl;
    }
    else {
        cout << "Daftar nama playlist : " << endl;

        Playlist *temp = headPlaylist;

        while (temp != NULL) {
            cout << temp->name << endl;
            temp = temp->next;
        }
    }
}

void seeSong(Playlist* currentPlaylist) {
    if (currentPlaylist == NULL) {
        cout << "Playlist kosong" << endl;
    }
    else {
        cout << "Lagu dalam playlist " << currentPlaylist->name << " adalah: " << endl;

        Song *temp = currentPlaylist->head;

        while (temp != NULL) {
            cout << "title : " << temp->title << " | artist : " << temp->artist << endl;
            temp = temp->next;
        }
    }
}

int main() {
    Playlist *currentPlaylist = NULL;
    Song *currentSong = NULL;

    while (true) {
        string input;

        cout << "Masukkan perintah : ";
        cin >> input;

        if (input == "CREATEPLAYLIST") {
            string namaPlaylist;

            cout << "Nama playlist baru: ";
            cin.ignore();
            getline(cin, namaPlaylist);

            createPlaylist(namaPlaylist);
            changePlaylist(currentPlaylist);
        }
        else if (input == "ADDSONG") {
            if (currentPlaylist == NULL) {
                cout << "Playlist belum dipilih, gunakan perintah CHANGEPLAYLIST untuk memilih playlist" << endl;
            }
            else {
                string title, artist;
                string addType;
                cout << "Judul lagu: ";
                cin.ignore();
                getline(cin, title);

                cout << "Nama artist: ";
                getline(cin, artist);

                cout << "Tambahkan ke awal atau akhir playlist? (insertfront/addfront): ";
                cin >> addType;
/*
                if (addType == "insertfront") {
                    insertFrontSong(currentPlaylist, title, artist);
                }
                else if (addType == "addfront") {
                    addFrontSong(currentPlaylist, title, artist);
                }*/
            }
        }
        else if (input == "CHANGEPLAYLIST") {
            changePlaylist(currentPlaylist);
        }
        else if (input == "PLAYSONG") {
            playSong(currentSong);
        }
        else if (input == "NEXTSONG") {
            nextSong(currentSong, currentPlaylist);
        }
        else if (input == "PREVSONG") {
            prevSong(currentSong, currentPlaylist);
        }
        else if (input == "SEEPLAYLIST") {
            seePlaylist();
        }
        else if (input == "SEESONG") {
            seeSong(currentPlaylist);
        }
        else {
            cout << "Perintah tidak dikenali" << endl;
        }
    }

    return 0;
}