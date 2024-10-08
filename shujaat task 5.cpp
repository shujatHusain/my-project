#include <iostream>
#include <string>
using namespace std;

class Song {
public:
    string title;
    Song* prev;
    Song* next;

    Song(string t) {
        title = t;
        prev = nullptr;
        next = nullptr;
    }
};

class Playlist {
    Song* head;

public:
    Playlist() {
        head = nullptr;
    }

    void addSong(string title) {
        Song* newSong = new Song(title);
        if (head == nullptr) {
            head = newSong;
        } else {
            Song* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newSong;
            newSong->prev = temp;
        }
    }

    void traverseForward() {
        Song* temp = head;
        while (temp != nullptr) {
            cout << temp->title << " -> ";
            temp = temp->next;
        }
        cout << "End" << endl;
    }

    void traverseBackward() {
        if (head == nullptr) return;
        Song* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        while (temp != nullptr) {
            cout << temp->title << " -> ";
            temp = temp->prev;
        }
        cout << "Start" << endl;
    }

    void deleteSong(string title) {
        if (head == nullptr) return;

        Song* temp = head;
        while (temp != nullptr && temp->title != title) {
            temp = temp->next;
        }

        if (temp == nullptr) return;

        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next;
        }

        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }

        delete temp;
    }
};

int main() {
    Playlist playlist;
    playlist.addSong("Song A");
    playlist.addSong("Song B");
    playlist.addSong("Song C");
    playlist.addSong("Song D");

    cout << "Forward Traversal:" << endl;
    playlist.traverseForward();

    cout << "Backward Traversal:" << endl;
    playlist.traverseBackward();

    playlist.deleteSong("Song B");
    cout << "After Deleting Song B:" << endl;
    playlist.traverseForward();

    return 0;
}
