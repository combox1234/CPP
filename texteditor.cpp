/*Implement simple text editor application using doubly linked list to manage the text buffer. Text editor should support the following functionalities:
a. Insert text
b. Delete text
c. Display text
d. Search text
e. Print text in reverse*/
#include<iostream>
#include<string>
class Node{
    char data;
    Node* next;
    node* prev;
    public:
    Node(data){//1st head node created will data 0 pointing NULL on both side
        data = 0;
        next = NULL;
        prev = NULL;
    }
    node(char d)
    {
        data = d;
    }
};
class text_editor{
    Node* head;
    text_editor(){
        head -> NULL;
    }
    void insert_text(char d){
        Node* nn = new Node(d);
        nn -> next = head;
        head = nn;
        prev = NULL;
    }
    void show_text(char d)
    {
        Node* temp;
        
    }
};
