// Implement Left View and Right View of Binary Tree with the help of Level Order Traversal

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* createTree() {
    cout << "Enter the value for Node (-1 for NULL): ";
    int value;
    cin >> value;

    if (value == -1) {
        return NULL;
    }

    Node* root = new Node(value);
    cout << "Entering in left of: " << value << endl;
    root->left = createTree();
    cout << "Entering in right of: " << value << endl;
    root->right = createTree();
    return root;
}

void levelOrderTraversal(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL); // Marker for end of level

    cout << endl;
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl; // End of current level
            if (!q.empty()) {
                q.push(NULL); // Add marker for next level
            }
        } else {
            cout << temp->data << " ";
            if (temp->left != NULL) {
                q.push(temp->left);
            }
            if (temp->right != NULL) {
                q.push(temp->right);
            }
        }
    }
}

void printLeftView(Node* root, int level, vector<int>& leftView) {
    if (root == NULL) return;

    if (level == leftView.size()) {
        leftView.push_back(root->data);
    }
    printLeftView(root->left, level + 1, leftView);
    printLeftView(root->right, level + 1, leftView);
}

void printRightView(Node* root, int level, vector<int>& rightView) {
    if (root == NULL) return;

    if (level == rightView.size()) {
        rightView.push_back(root->data);
    }
    printRightView(root->right, level + 1, rightView);
    printRightView(root->left, level + 1, rightView);
}

int main() {
    Node* root = createTree();
    // Example input: 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1
    levelOrderTraversal(root);

    vector<int> leftView;
    printLeftView(root, 0, leftView);
    cout << "Left View: ";
    for (int val : leftView) {
        cout << val << " ";
    }
    cout << endl;

    vector<int> rightView;
    printRightView(root, 0, rightView);
    cout << "Right View: ";
    for (int val : rightView) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}