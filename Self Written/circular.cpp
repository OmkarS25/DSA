#include<iostream>
#include<vector>
using namespace std; 

class node{
    public:
    int val;
    node* next;
    node (int data){
        val = data;
        next = NULL;
    }
};
vector<node*> head;
vector<node*> tail;
int index = -1;
int maxindex = 0;
// node* head[index]=NULL;
// node* tail[index]=NULL;

void create(){
    index++;
    maxindex++;
    int n,val;
    cout<<"Enter the number of nodes to create:";
    cin>>n;
    head.push_back(NULL);
    tail.push_back(NULL);
    // head[index] = NULL;
    // tail[index] = NULL;

    if(n<=0){
        cout<<"Invalid Intput"<<endl;
        return;
    }
    else {
        for(int i=0; i<n; i++){
        cout<<"Enter the value for "<<i+1<<" : ";
        cin>>val;
        node* new_node = new node(val);
        if(head[index] == NULL){
            head[index] = new_node;
            tail[index] = new_node;
            tail[index]->next = head[index]; // Making it circular.
        }
        else {
            new_node->next = head[index]; // Point new_node to the head[index]
            tail[index]->next = new_node; // Make the current tail[index] point to new_node
            tail[index] = new_node;       // Update tail[index] to new_node
        }
        }
    }
}

// void display(){
//     cout<<"Elements of Linked List:";
//     node* temp = head[index];
//     do{
//         cout<<"->"<<temp->val;
//         temp = temp->next;
//     }while(temp!=head[index]);
// }

void display()
{
    if (head[index] == NULL)
    {
        cout << "Circular Linked List is empty" << endl;
        return;
    }

    node *current = head[index];

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

        node *current = head[i];

        do
        {
            cout << current->val << " -> ";
            current = current->next;
        } while (current != head[i]);

        cout << "NULL" << endl;
    }
}

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
int main(){
    // create();
    // display();
    create();
    display();
    create();
    displayalllinkedlist();
    changeindex();
    return 0;
}