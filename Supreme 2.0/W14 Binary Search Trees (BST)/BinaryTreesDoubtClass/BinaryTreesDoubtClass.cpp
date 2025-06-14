#include <iostream>
#include <queue>
using namespace std;

class Node{
public:
    int data;
    int children_count;
    Node** children;

    Node(int data) {
        this->data = data;
        this->children_count = 0;
        this->children = nullptr; // Initialize children to nullptr
    }
};

Node* takeInput(){
    int data, count; 
    cout << "Enter root data: ";
    cin >> data;
    cout << "Enter Children count for " << data << " node: ";
    cin >> count;

    Node *root = new Node(data);
    root->children_count = count;
    root->children = new Node* [count]; // Array to store links to children 
    
    for(int i=0; i<count; i++){
        cout << "Enter data for child " << i+1 << " of " << data << ": ";
        root->children[i] = takeInput(); // Create a new node for each child
    }
}

void levelOrderPrint(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL); // Use NULL as a marker for the end of the current level
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        if(front == NULL){
            cout << endl; // Print a new line for the next level
            if(!q.empty()) q.push(NULL); // Push NULL again if there are more nodes to process
        } else {
            cout << front->data << " "; // Print the current node's data
            for(int i=0; i<front->children_count; i++){
                if(front->children[i]) q.push(front->children[i]); // Push all children of the current node into the queue
            }
        }
    }
}

int main(){
    Node* root = takeInput();
    cout << "Level Order Traversal of the tree:" << endl;
    levelOrderPrint(root);
    return 0; 
}