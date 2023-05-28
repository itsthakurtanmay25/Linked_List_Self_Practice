#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    //constructor
    node(int d) {
        this->data = d;
        this->next = NULL;
    }
};

void insertAtHead(node*& head, int d) {
    //step 1: creating New Node
    node* new_node = new node(d);

    //step 2: Tod fod waali backchodi;
    new_node->next = head;

    //step 3 : Update head;
    head = new_node;
}

void insertAtTail(node*& head, int d) {
    //step 1: creating New Node
    node* new_node = new node(d);

    if (head == NULL) {
        // List is empty, update both head and tail
        head = new_node;
    } else {
        // Traverse to the last node
        node* tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
        }

        //step 2: Tod fod waali backchodi;
        tail->next = new_node;
    }
}

void insertAtAnyPos(node*& head, int pos, int d, int length) {
    if (pos > length + 1 || pos < 1) {
        cout << "Not a valid position" << endl;
        return;
    } else if (pos == 1) {
        insertAtHead(head, d);
    } else if (pos == length + 1) {
        insertAtTail(head, d);
    } else {
        node* new_node = new node(d);
        node* prev = head;
        int t = pos - 2;
        while (t--) {
            prev = prev->next;
        }
        new_node->next = prev->next;
        prev->next = new_node;
    }
}

int lengthOfLL(node* head) {
    int count = 0;
    node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void traverse(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    node* head = NULL;

    insertAtHead(head, 5);
    insertAtHead(head, 2);
    insertAtHead(head, 9);
    insertAtHead(head, 7);

    int length = lengthOfLL(head);
    cout << "Length of this Linked List: " << length << endl;

    traverse(head);

    insertAtAnyPos(head, 5, 989, length);
    traverse(head);

    return 0;
}
