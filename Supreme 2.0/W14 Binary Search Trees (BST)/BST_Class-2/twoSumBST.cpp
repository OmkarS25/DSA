/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void storeInorder(TreeNode* root, vector<int> &inorder) {
        //base case
        if(root == NULL) {
            return;
        }
        //LNR
        storeInorder(root->left, inorder);
        //N
        inorder.push_back(root->val);
        //R
        storeInorder(root->right, inorder);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        storeInorder(root, inorder);

        ///find targetnusing 2 pointer approach
        int start = 0;
        int end = inorder.size()-1;

        while(start < end) {
            int sum = inorder[start] + inorder[end];
            if(sum == k) {
                return true;
            }
            else if(sum > k) {
                end--;
            }
            else if(sum < k) {
                start++;
            }
        }
        return false;
    }
};

// Trying to solve the problem with a different approach using two stacks
class Solution2{
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) return false;

        // Using while loop to traverse the BST
        stack<TreeNode*> s1, s2;
        TreeNode* curr1 = root;
        TreeNode* curr2 = root; 

        while(true) {
            // Traverse the left subtree of curr1
            while(curr1 != NULL) {
                s1.push(curr1);
                curr1 = curr1->left;
            }
            // Traverse the right subtree of curr2
            while(curr2 != NULL) {
                s2.push(curr2);
                curr2 = curr2->right;
            }

            if(s1.empty() || s2.empty()) break;

            TreeNode* leftNode = s1.top();
            TreeNode* rightNode = s2.top();

            // If both pointers meet, we have traversed the entire tree
            if(leftNode == rightNode) break;

            int sum = leftNode->val + rightNode->val;
            if(sum == k) return true;
            else if(sum < k) {
                s1.pop();
                curr1 = leftNode->right; // Move to the right subtree
            } else {
                s2.pop();
                curr2 = rightNode->left; // Move to the left subtree
            }
        }
        return false;
    }

};