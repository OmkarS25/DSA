// Implement N-ary Tree and its Traversals
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    vector<TreeNode*> children;
    TreeNode(int value) : val(value) {}
    // You can also add a constructor to initialize children if needed
    TreeNode(int value, const vector<TreeNode*>& childNodes) : val(value), children(childNodes) {}
    // You can also add a destructor if you need to manage memory
    ~TreeNode() {
        for (int i = 0; i < children.size(); ++i) {
            TreeNode* child = children[i];
            delete child;
        }
    }
};

void printNaryTree(TreeNode* root, int level = 0) {
    if (!root) return;
    
    // Print the current node's value
    cout << string(level * 2, ' ') << root->val << endl;

    // Recursively print all children
    for (int i = 0; i < root->children.size(); ++i) {
        TreeNode* child = root->children[i];
        printNaryTree(child, level + 1);
    }
}

void runNaryTreeExample() {
    // Create a sample N-ary tree
    TreeNode* root = new TreeNode(1);
    TreeNode* child1 = new TreeNode(2);
    TreeNode* child2 = new TreeNode(3);
    TreeNode* child3 = new TreeNode(4);
    root->children.push_back(child1);
    root->children.push_back(child2);
    child1->children.push_back(child3);
    
    // Print the N-ary tree
    printNaryTree(root);
    
    // Clean up memory
    delete root; // This will recursively delete all children
    // Note: No need to delete child1 and child2 separately, as they will be deleted by the destructor of root
}

// Now, we will implement morris traversal for Binary trees
// Note: Morris traversal is typically used for binary trees, not N-ary trees.

void morrisTraversalNaryTrees(TreeNode* root) {
    TreeNode* current = root;
    while (current) {
        if (!current->children.empty()) {
            // Find the rightmost child in the left subtree
            TreeNode* rightmost = current->children[0];
            while (!rightmost->children.empty()) {
                rightmost = rightmost->children.back();
            }
            // Link the rightmost child to the current node
            rightmost->children.push_back(current);
            // Move to the left child
            current = current->children[0];
        } else {
            // Print the current node's value
            cout << current->val << " ";
            // Move to the next node in the traversal
            if (!current->children.empty()) {
                current = current->children.back();
            } else {
                current = nullptr; // End of traversal
            }
        }
    }
}

// Let's understand how morris traversal works with a binary tree example
struct BinaryTreeNode {
    int val;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
void morrisTraversalBinaryTree(BinaryTreeNode* root) {
    BinaryTreeNode* current = root;
    while (current) {
        if (!current->left) {
            // Print the current node's value
            cout << current->val << " ";
            // Move to the right child
            current = current->right;
        } else {
            // Find the rightmost node in the left subtree
            BinaryTreeNode* predecessor = current->left;
            while (predecessor->right && predecessor->right != current) {
                predecessor = predecessor->right;
            }
            // Make a temporary link to the current node
            if (!predecessor->right) {
                predecessor->right = current;
                current = current->left;
            } else {
                // Restore the tree structure
                predecessor->right = nullptr;
                cout << current->val << " ";
                current = current->right;
            }
        }
    }
}

void runMorrisTraversalExample() {
    // Create a sample binary tree
    BinaryTreeNode* root = new BinaryTreeNode(1);
    root->left = new BinaryTreeNode(2);
    root->right = new BinaryTreeNode(3);
    root->left->left = new BinaryTreeNode(4);
    root->left->right = new BinaryTreeNode(5);

    // Perform Morris traversal
    cout << "Morris Traversal of Binary Tree: ";
    morrisTraversalBinaryTree(root);
    cout << endl;

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
}

int main() {
    runNaryTreeExample();
    runMorrisTraversalExample();
    return 0;
}