#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int _data){
        data = _data;
        left = NULL;
        right = NULL;
    }
};

class Deletion_of_Node_in_BST{
public:
    bool takeFromLeft = true;
    Node* deleteFromBST(Node* root, int target){
        // 1. find the target
        // 2. delete the target

        // B.C
        if(root == NULL) return NULL;

        // Delete Case
        if(root->data == target){
            // 4 cases of deletion
            
            // 1-Case Leaf Node
            if(!root->left && !root->right){
                delete root;
                return NULL;
            }
            // 2-Case Left Non-NULL and Right NULL
            else if(root->left && !root->right){
                Node *temp = root->left;
                delete root;
                return temp;
            }
            // 3-Case Left NULL and Right Non-NULL
            else if(!root->left && root->right){
                Node *temp = root->right;
                delete root;
                return temp;
            }
            // 4-Case Left and Right both Non-NULL
            else{
                Node *tempLeft = root->left, *tempRight = root->right;
                delete root;

                // There are two options
                // 1. Max Value from LST
                // 2. Min Value from RST
                // Here I want to bring the actual node, rather than transfering data
                // but it will become too long of a process.
                Node* newRoot = nullptr;
                if(takeFromLeft){
                    Node* parent = tempLeft;
                    Node* curr = tempLeft;
                    
                    while(curr->right != NULL){
                        parent = curr;
                        curr = curr->right;
                    }

                    if(curr == parent){
                        newRoot = tempLeft;
                        newRoot->right = tempRight;
                    }
                    else{
                        newRoot = curr;
                        parent->right = curr->left; // left child of the max node
                        newRoot->left = tempLeft; // left subtree
                        newRoot->right = tempRight; // right subtree
                    }
                }
                else{
                    Node* parent = tempRight;
                    Node* curr = tempRight;
                    
                    while(curr->left != NULL){
                        parent = curr;
                        curr = curr->left;
                    }

                    if(curr == parent){
                        newRoot = tempRight;
                        newRoot->left = tempLeft;
                    }
                    else{
                        newRoot = curr;
                        parent->left = curr->right; // right child of the min node
                        newRoot->right = tempRight; // right subtree
                        newRoot->left = tempLeft; // left subtree
                    }
                }
                return newRoot;
            }
        }
        
        // Making recursion call
        if(target < root->data)
            root->left = deleteFromBST(root->left, target);
        else 
            root->right = deleteFromBST(root->right, target);
        
        return root;
    }
};