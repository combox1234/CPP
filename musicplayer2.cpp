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
class Node {//class node
public:
    string title;// title var
    Node* next;//next ptr
    Node(string title) {//constructor 
        this->title = title;//assignment to the pointer in const title.
        this->next = NULL;//assignment is a pointer in const for next.
    }
};
class Playlist {//class playlist made
public:
    Node* head;//head ptr
    Playlist() {//constructor
        this->head = NULL;//assignment for head
    }
    void insert_node(string title) {//Add Track funtion
        Node* nn = new Node(title);//new ptr nn made and assigned new node made and data takes in as track 
        nn->next = head;//every node added usin this function will add from top new node means new head everytime
        head = nn;//head ptr will now have new node and will point at new node 
    }
    void delete_node(string title) {//delete node
        Node* temp = head;//temp ptr pointing head
        Node* prev = NULL;//prev assigned NULL
        while (temp != NULL && temp->title != title) {//
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "song not found in the queue" << endl;
            return;
        }
        if (prev == NULL) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }
        delete temp;
    }
    void show_track() {
        Node* temp = head;
        while (temp != NULL) {
            cout << "title: " << temp->title << endl;
            temp = temp->next;
        }
    }
    void insert_at_position(int position, string title) {
        Node* nn = new Node(title);
        if (position == 1) {
            nn->next = head;
            head = nn;
        } else {
            Node* temp = head;
            int i = 1;
            while (temp != NULL && i < position - 1) {
                temp = temp->next;
                i++;
            }
            if (temp == NULL) {
                cout << "unable to allocate this position" << endl;
                return;
            }
            nn->next = temp->next;
            temp->next = nn;
        }
    }
};
int main() {
    Playlist queue;
    int choice;
    string title;
    int position;
    do {
        cout<<"1. Enter track\n2. Add song at a position\n3. remove a song\n4. diplay track\n5. exit\n\nEnter your choice:";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter song title: ";
                cin >> title;
                queue.insert_node(title);
                break;
            case 2:
                cout << "Enter position: ";
                cin >> position;
                cout << "Enter song title: ";
                cin >> title;
                queue.insert_at_position(position, title);
                break;
            case 3:
                cout << "Enter song title to remove: ";
                cin >> title;
                queue.delete_node(title);
                break;
            case 4:
                queue.show_track();
                break;
            case 5:
                return 0;
            default:
                cout << "please try again" << endl;
        }
    } while (true);

    return 0;
}
