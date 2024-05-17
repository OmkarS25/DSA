#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int data)
    {
        val = data;
        next = NULL;
    }
};
vector<Node *> head;
vector<Node *> tail;
// Node* head[10];
// Node* tail[10];
// Node* head = NULL; // Initialize head to NULL initially
// Node* tail = NULL; // Initialize tail to NULL initially
int index = -1, maxindex = 0;

void changeindex(){
    int n;
    cout << "Enter which linked list you want to work with, your options are 0 to " << maxindex-1 <<": ";
    cin >> n;
    if (n < 0 || n >= maxindex)
    {
        cout << "Invalid input." << endl;
        cout << "Try again." << endl;
        changeindex();
    }
    else
    {
        cout << "Now you working with linked list index no.=" << n << endl;
        index = n;
    }
}
int getLength()
{
    int count = 0;
    Node *temp = head[index];
    if (head[index] == NULL)
    {
        return count;
    }
    do
    {
        count++;
        temp = temp->next;
    } while (temp != head[index]);
    return count;
}

void create()
{
    index++;
    maxindex++;
    int n, val;
    cout << "Enter the number of nodes: ";
    cin >> n;
    // head[index] = NULL;
    // tail[index] = NULL;
    head.push_back(NULL);
    tail.push_back(NULL);

    if (n <= 0)
    {
        cout << "Invalid number of nodes" << endl;
        return;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Enter the data for node " << i + 1 << ": ";
            cin >> val;

            Node *new_node = new Node(val);

            if (head[index] == NULL)
            {
                head[index] = new_node;
                tail[index] = new_node;
                tail[index]->next = head[index]; // Make it circular
            }
            else
            {
                new_node->next = head[index]; // Point new_node to the head
                tail[index]->next = new_node; // Make the current tail point to new_node
                tail[index] = new_node;       // Update tail to new_node
            }
        }
    }
}

void insertAtStart(int val)
{
    Node *new_node = new Node(val);
    if (head[index] == NULL)
    {
        head[index] = new_node;
        new_node->next = head[index]; // Circular linked list
        return;
    }

    Node *tail[index] = {head[index]};
    while (tail[index]->next != head[index])
    {
        tail[index] = tail[index]->next;
    }

    tail[index]->next = new_node;
    new_node->next = head[index];
    head[index] = new_node;
}

void insertAtEnd(int val)
{
    Node *new_node = new Node(val);
    if (head[index] == NULL)
    {
        head[index] = new_node;
        new_node->next = head[index]; // Circular linked list
        return;
    }

    Node *tail[index] = {head[index]};
    while (tail[index]->next != head[index])
    {
        tail[index] = tail[index]->next;
    }

    tail[index]->next = new_node;
    new_node->next = head[index];
}

void insertAtSpecificPoint()
{
    int loc, val;
    cout << "Enter the location where you want to add node: ";
    cin >> loc;
    int l = getLength();

    if (loc < 1 || loc > l + 1)
    {
        cout << "Invalid location" << endl;
    }
    else if (loc == 1)
    {
        cout << "Enter value to insert: ";
        cin >> val;
        insertAtStart(val);
    }
    else if (loc == l + 1)
    {
        cout << "Enter value to insert: ";
        cin >> val;
        insertAtEnd(val);
    }
    else
    {
        cout << "Enter value to insert: ";
        cin >> val;
        Node *new_node = new Node(val);
        Node *temp = head[index];
        for (int i = 1; i < loc - 1; i++)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void deleteAtStart()
{
    if (head[index] == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    Node *temp = head[index];
    Node *tail[index] = {head[index]};
    while (tail[index]->next != head[index])
    {
        tail[index] = tail[index]->next;
    }

    head[index] = head[index]->next;
    tail[index]->next = head[index];
    delete temp;
}

void deleteAtEnd()
{
    if (head[index] == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    Node *temp = head[index];
    Node *tail[index] = {head[index]};
    Node *prev = NULL;

    while (temp->next != head[index])
    {
        prev = temp;
        temp = temp->next;
    }

    if (prev != NULL)
    {
        prev->next = head[index];
        tail[index] = prev;
    }
    else
    {
        head[index] = NULL;
        tail[index] = NULL;
    }

    delete temp;
}

void deleteAtSpecificLocation()
{
    int loc;
    cout << "Enter the location: ";
    cin >> loc;
    int l = getLength();

    if (loc < 1 || loc > l)
    {
        cout << "Invalid location" << endl;
        return;
    }

    if (loc == 1)
    {
        deleteAtStart();
        return;
    }
    else if (loc == l)
    {
        deleteAtEnd();
        return;
    }

    Node *temp = head[index];
    Node *prev = NULL;

    for (int i = 1; i < loc; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;
    delete temp;
}

void display()
{
    if (head[index] == NULL)
    {
        cout << "Circular Linked List is empty" << endl;
        return;
    }

    Node *current = head[index];

    do
    {
        cout << current->val << " -> ";
        current = current->next;
    } while (current != head[index]);

    cout << "NULL" << endl;
}

void displayalllinkedlist()
{
    for (int i = 0; i < maxindex; i++)
    {
        if (head[i] == NULL)
        {
            cout << "Circular Linked List is empty" << endl;
            return;
        }

        Node *current = head[i];

        do
        {
            cout << current->val << " -> ";
            current = current->next;
        } while (current != head[i]);

        cout << "NULL" << endl;
    }
}

int main()
{
    int choice;
    while (1)
    {
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
        cout << "9. Display all the linked list created" << endl;
        cout << "10. Change your linked list" << endl;
        cout << "11. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
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
            displayalllinkedlist();
            break;
        case 10:
            changeindex();
            break;
        case 11:
            exit(0);
        default:
            cout << "Invalid input" << endl;
            break;
        }
    }
    // create();
    // create();
    // create();
    // display();
    // displayalllinkedlist();
    return 0;
}