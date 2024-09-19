void delete_node(string song) {
    if (head == NULL) {
        cout << "song not found in the queue" << endl;
        return;
    }
    if (head->title == song) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "deleted\n";
        return;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->title != song) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        cout << "song not found in the queue" << endl;
        return;
    }
    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
    cout << "deleted\n";
}
