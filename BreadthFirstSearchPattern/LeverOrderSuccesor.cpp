#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int data) {
		this->val = data;
		this->left = NULL;
		this->right = NULL;
	}
};

int LevelOrderSuccesor(TreeNode* root, int node) {
	queue<TreeNode*> q;
	q.push(root);
	int found = false;
	while (!q.empty()) {
		int numitemsinlevel = q.size();
		while (numitemsinlevel--) {
			TreeNode* curr = q.front();
			q.pop();
			if (found) return curr->val;
			if (curr->val == node)
				found = true;
			if (curr->left != NULL)	q.push(curr->left);
			if (curr->right != NULL)	q.push(curr->right);
		}
	}
	return -1; // this will be executed when the last node is given.
}

int main() {
	TreeNode* root = new TreeNode(12);
	root->left = new TreeNode(7);
	root->right = new TreeNode(6);
	root->left->left = new TreeNode(9);
	root->right->left = new TreeNode(11);
	root->right->right = new TreeNode(5);
	int node = 5;
	cerr << LevelOrderSuccesor(root, node) << endl;
}