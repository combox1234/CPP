/*Consider the playlist in a music player. Implement a playlist feature in music player application
using singly linked list. Each song in the playlist is represented as a node in the linked list. Each
node contains information about the song (such as title or artist or duration, etc.).
The playlist should allow users to:
a. Add songs
b. Remove songs
c. Display the entire playlist
d. Play specific songs*/
#include <iostream>
#include <string>

// include necessary libraries for input/output and string manipulation
using namespace std;

// define the node structure for the singly linked list
struct node {
    string title; // song title
    string artist; // song artist
    int duration; // song duration in seconds
    node* next; // pointer to the next node in the list
}; // node structure definition

// define the playlist class
class playlist {
private:
    node* head; // head of the singly linked list

public:
    // constructor to initialize the playlist
    playlist() {
        head = nullptr; // initialize head to null
    }

    // add a song to the playlist
    void addsong(string title, string artist, int duration) {
        // create a new node for the song
        node* nn = new node();
        nn->title = title;
        nn->artist = artist;
        nn->duration = duration;
        nn->next = head;
        head = nn; // add song to the beginning of the list
    } // add song to the playlist

    // remove a song from the playlist
    void removesong(string title) {
        node* curr = head;
        node* prev = nullptr;

        // traverse the list to find the song to remove
        while (curr != nullptr && curr->title != title) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr) {
            cout << "song not found in the playlist" << endl;
            return;
        }

        // update the list to remove the song
        if (prev == nullptr) {
            head = curr->next;
        } else {
            prev->next = curr->next;
        }

        delete curr; // delete the node
    } // remove song from the playlist

    // display the entire playlist
    void displayplaylist() {
        node* curr = head;
        while (curr != nullptr) {
            cout << "title: " << curr->title << ", artist: " << curr->artist << ", duration: " << curr->duration << " seconds" << endl;
            curr = curr->next;
        }
    } // display the entire playlist

    // play a specific song
    void playsong(string title) {
        node* curr = head;
        while (curr != nullptr && curr->title != title) {
            curr = curr->next;
        }

        if (curr == nullptr) {
            cout << "song not found in the playlist" << endl;
            return;
        }

        cout << "playing " << curr->title << " by " << curr->artist << endl;
    } // play a specific song
};
int main() {
    // create a new playlist object
    playlist playlist;

    // add three songs to the playlist
    playlist.addsong("song 1", "artist 1", 180); // add song 1
    playlist.addsong("song 2", "artist 2", 240); // add song 2
    playlist.addsong("song 3", "artist 3", 300); // add song 3

    // display the entire playlist
    playlist.displayplaylist(); // display the playlist with 3 songs

    // play a specific song
    playlist.playsong("song 2"); // play song 2

    // remove a song from the playlist
    playlist.removesong("song 2"); // remove song 2

    // display the updated playlist
    playlist.displayplaylist(); // display the playlist with 2 songs

    return 0;
}
