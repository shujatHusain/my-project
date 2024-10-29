#include <iostream>
using namespace std;

struct Song {
    string title;
    Song* prev;
    Song* next;
};

void addSongToEnd(Song** head, string newTitle) {
    Song* newSong = new Song();
    Song* last = *head;
    newSong->title = newTitle;
    newSong->next = NULL;

    if (*head == NULL) {
        newSong->prev = NULL;
        *head = newSong;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newSong;
    newSong->prev = last;
}

void traverseForward(Song* node) {
    cout << "Playlist (Forward): ";
    while (node != NULL) {
        cout << node->title << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

void traverseBackward(Song* node) {
    while (node && node->next != NULL) {
        node = node->next;
    }

    cout << "Playlist (Backward): ";
    while (node != NULL) {
        cout << node->title << " -> ";
        node = node->prev;
    }
    cout << "NULL" << endl;
}

void deleteSong(Song** head, string title) {
    Song* temp = *head;

    while (temp != NULL && temp->title != title) {
        temp = temp->next;
    }

    if (temp == NULL) return;

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    delete temp;
}

int main() {
    Song* playlist = NULL;

    addSongToEnd(&playlist, "Song 1");
    addSongToEnd(&playlist, "Song 2");
    addSongToEnd(&playlist, "Song 3");
    addSongToEnd(&playlist, "Song 4");

    traverseForward(playlist);
    traverseBackward(playlist);

    deleteSong(&playlist, "Song 2");

    traverseForward(playlist);
    traverseBackward(playlist);

    return 0;
}
