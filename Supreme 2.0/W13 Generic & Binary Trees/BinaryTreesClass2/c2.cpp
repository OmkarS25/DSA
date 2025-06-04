/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Lowest Common Ancestor of a Binary Tree
// Leetcode-236
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: if root is NULL, we return NULL
        // If root is equal to p or q, we return root as it is the LCA
        // if(p == NULL || q == NULL) return NULL; // If either p or q is NULL, we return NULL
        if(root == NULL) return NULL;
        if(root->val == p->val) return p;
        if(root->val == q->val) return q;

        // If both p and q are not equal to root, we will check in left and right subtree
        TreeNode* leftAns = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightAns = lowestCommonAncestor(root->right,p,q);

        // If both left and right subtree return NULL, then we return NULL
        // If only one of them returns NULL, we return the other one
        // If both return non-NULL, then we return root as it is the LCA
        if(leftAns == NULL && rightAns == NULL) return NULL;
        else if(leftAns != NULL && rightAns == NULL) return leftAns;
        else if(leftAns == NULL && rightAns != NULL) return rightAns;
        else return root;
    }
};