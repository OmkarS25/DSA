// This Class was taken in Week 15 but belongs to Week 14.
#include<iostream>
#include<map>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int _val) : val(_val), left(NULL), right(NULL) {}
};

// Leetcode 450 : Delete Node in a BST
class Solution {
public:
bool fromLST = true;
    TreeNode* deleteNode(TreeNode* root, int key){
        if(!root) return NULL;
        if(root->val == key){
            // case 1: leaf node
            if(!root->left && !root->right){
                delete root;
                return NULL;
            }
            // case 2: left NULL && right != NULL
            else if(!root->left){
                TreeNode* temp = root;
                root = root->right;
                delete temp;
                return root;
            }
            // case 3: left 1= NULL && right NULL
            else if(!root->right){
                TreeNode* temp = root;
                root = root->left;
                delete temp;
                return root;
            }
            // case 4: left != NULL && right != NULL
            else if(!fromLST){
                // RST ka min nikalo
                TreeNode* rscan = root->right;
                while(rscan->left)
                    rscan = rscan->left;
                rscan->left = root->left;
                TreeNode* temp = root;
                root = root->right;
                delete temp;
                return root;
            }
            else{
                // LST ka max nikalo
                TreeNode* lscan = root->left;
                while(lscan->right)
                    lscan = lscan->right;
                lscan->right = root->right;
                TreeNode* temp = root;
                root = root->left;
                delete temp;
                return root;
            }
        }
        else if(key > root->val)
            root->right = deleteNode(root->right, key);
        else root->left = deleteNode(root->left, key);
        return root;
    }
};

// Two Sum in BST using Hashmap
class Solution2 {
    bool helper(TreeNode* root, int k, map<int, bool>& mp){
        if(!root) return false;
        if(mp.find(k - root->val) != mp.end()) return true;
        mp[root->val] = true;
        return helper(root->left, k, mp) || helper(root->right, k, mp);
    }

public:
    bool findTarget(TreeNode* root, int k){
        map<int, bool> mp;
        return helper(root, k, mp);
    }
};