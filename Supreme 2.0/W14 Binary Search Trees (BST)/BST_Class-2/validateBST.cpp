#include <iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* left;
	Node* right;

	Node(int value) {
		this->data = value;
		this->left = NULL;
		this->right = NULL;
	}
};

class Solution {
public:
	bool helper(Node* root, long long int lowerbound, long long int upperbound) {
		if(root == NULL) {
			return true;
		}

		if(root->data > lowerbound && root->data < upperbound
			&& helper(root->left, lowerbound, root->data)
			&& helper(root->right, root->data, upperbound)) {
			return true;
		}
		else {
			return false;
		}

		// if(root->data <= lowerbound || root->data >= upperbound) {
		// 	return false;
		// }

		// bool leftAns = helper(root->left, lowerbound, root->data);
		// bool rightAns = helper(root->right, root->data, upperbound);

		// return leftAns && rightAns;
	}
	bool validateBST(Node* root) {
		return helper(root, LONG_MIN, LONG_MAX);
	}
};