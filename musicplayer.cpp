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
        head = NULL; // initialize head to null
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
        node* prev = NULL;

        // traverse the list to find the song to remove
        while (curr != NULL && curr->title != title) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == NULL) {
            cout << "song not found in the playlist" << endl;
            return;
        }

        // update the list to remove the song
        if (prev == NULL) {
            head = curr->next;
        } else {
            prev->next = curr->next;
        }

        delete curr; // delete the node
    } // remove song from the playlist

    // display the entire playlist
    void displayplaylist() {
        node* curr = head;
        while (curr != NULL) {
            cout << "title: " << curr->title << ", artist: " << curr->artist << ", duration: " << curr->duration << " seconds" << endl;
            curr = curr->next;
        }
    } // display the entire playlist

    // play a specific song
    void playsong(string title) {
        node* curr = head;
        while (curr != NULL && curr->title != title) {
            curr = curr->next;
        }

        if (curr == NULL) {
            cout << "song not found in the playlist" << endl;
            return;
        }

        cout << "playing " << curr->title << " by " << curr->artist << endl;
    } // play a specific song
};

int main() {
    // create a new playlist object
    playlist playlist;

    int choice;
    string title, artist;
    int duration;

    while (true) {
        cout << "Enter your choice:" << endl;
        cout << "1. Add a song" << endl;
        cout << "2. Remove a song" << endl;
        cout << "3. Display the playlist" << endl;
        cout << "4. Play a song" << endl;
        cout << "5. Exit" << endl;

        cin >> choice;

        switch (choice) {
            case 1://add song
                cout << "Enter song title: ";
                cin >> title;
                cout << "Enter song artist: ";
                cin >> artist;
                cout << "Enter song duration (in seconds): ";
                cin >> duration;
                playlist.addsong(title, artist, duration);
                break;

            case 2://remoce song
                cout << "Enter song title to remove: ";
                cin >> title;
                playlist.removesong(title);
                break;

            case 3://show playlist
                playlist.displayplaylist();
                break;

            case 4://track to be played
                cout << "Enter song title to play: ";
                cin >> title;
                playlist.playsong(title);
                break;

            case 5://end
                return 0;

            default:
                cout << "please try again" << endl;
        }
    }

    return 0;
}
