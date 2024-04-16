#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int data) {
        val = data;
        next = NULL;
    }
};

Node* head = NULL; // Initialize head to NULL initially.
Node* tail = NULL; // Initialize tail to NULL initially.

int getLength() {
    int count = 0;
    Node* temp = head;
    if (head == NULL) {
        return count;
    }
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

void create() {
    int n, val;
    cout << "Enter the number of nodes: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of nodes" << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        cout << "Enter the data for node " << i + 1 << ": ";
        cin >> val;

        Node* new_node = new Node(val);

        if (head == NULL) {
            head = new_node;
            tail = new_node;
            tail->next = head; // Make it circular
        } else {
            new_node->next = head; // Point new_node to the head
            tail->next = new_node; // Make the current tail point to new_node
            tail = new_node;       // Update tail to new_node
        }
    }
}

void insertAtStart(int val) {
    Node* new_node = new Node(val);
    if (head == NULL) {
        head = new_node;
        new_node->next = head; // Circular linked list
        return;
    }

    Node* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }

    tail->next = new_node;
    new_node->next = head;
    head = new_node;
}

void insertAtEnd(int val) {
    Node* new_node = new Node(val);
    if (head == NULL) {
        head = new_node;
        new_node->next = head; // Circular linked list
        return;
    }

    Node* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }

    tail->next = new_node;
    new_node->next = head;
}

void insertAtSpecificPoint() {
    int loc,val;
    cout << "Enter the location where you want to add node: ";
    cin >> loc;
    int l = getLength();
    
    if (loc < 1 || loc > l + 1) {
        cout << "Invalid location" << endl;
    } else if (loc == 1) {
        cout << "Enter value to insert: ";
        cin >> val;
        insertAtStart(val);
    } else if (loc == l + 1) {
        cout << "Enter value to insert: ";
        cin >> val;
        insertAtEnd(val);
    } else {
        cout << "Enter value to insert: ";
        cin >> val;
        Node* new_node = new Node(val);
        Node* temp = head;
        for (int i = 1; i < loc - 1; i++) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void deleteAtStart() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = head;
    Node* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }

    head = head->next;
    tail->next = head;
    delete temp;
}

void deleteAtEnd() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = head;
    Node* tail = head;
    Node* prev = NULL;
    
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    if (prev != NULL) {
        prev->next = head;
        tail = prev;
    } else {
        head = NULL;
        tail = NULL;
    }

    delete temp;
}

void deleteAtSpecificLocation() {
    int loc;
    cout << "Enter the location: ";
    cin >> loc;
    int l = getLength();
    
    if (loc < 1 || loc > l) {
        cout << "Invalid location" << endl;
        return;
    }
    
    if (loc == 1) {
        deleteAtStart();
        return;
    } else if (loc == l) {
        deleteAtEnd();
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    for (int i = 1; i < loc; i++) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;
    delete temp;
}

void display() {
    if (head == NULL) {
        cout << "Circular Linked List is empty" << endl;
        return;
    }

    Node* current = head;

    do {
        cout << current->val << " -> ";
        current = current->next;
    } while (current != head);

    cout << "NULL" << endl;
}

int main() {
    int choice;
    while (1) {
        cout << "\n\n\t\tMENU Circular Linked List\n\n\n";
        cout << "Enter the operation" << endl;
        cout << endl;
        cout << "1. Create linked list" << endl;
        cout << "2. Insert at Start" << endl;
        cout << "3. Insert at end" << endl;
        cout << "4. Insert at specific location" << endl;
        cout << "5. Delete from beginning" << endl;
        cout << "6. Delete from end" << endl;
        cout << "7. Delete at specific position" << endl;
        cout << "8. Display" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice) {
        case 1:
            create();
            break;
        case 2:
            int val_start;
            cout << "Enter value to insert: ";
            cin >> val_start;
            insertAtStart(val_start);
            break;
        case 3:
            int val_end;
            cout << "Enter value to End: ";
            cin >> val_end;
            insertAtEnd(val_end);
            break;
        case 4:
            insertAtSpecificPoint();
            break;
        case 5:
            deleteAtStart();
            break;
        case 6:
            deleteAtEnd();
            break;
        case 7:
            deleteAtSpecificLocation();
            break;
        case 8:
            display();
            break;
        case 9:
            exit(0);
        default:
            cout << "Invalid input" << endl;
            break;
        }
    }

    return 0;
}