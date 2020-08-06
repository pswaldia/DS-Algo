#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode* next;
	TreeNode(int data) {
		this->val = data;
		this->left = NULL;
		this->right = NULL;
		this->next = NULL;
	}
};

void ConnectLevelOrderSiblings(TreeNode* root) {
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		int numitemsinlevel = q.size();
		TreeNode* prev = NULL;
		for (int i = 1; i <= numitemsinlevel; i++) {
			TreeNode* curr = q.front();
			q.pop();
			if (prev != NULL)
				prev->next = curr;
			prev = curr;
			if (curr->left != NULL) q.push(curr->left);
			if (curr->right != NULL) q.push(curr->right);
		}
	}
}

int main() {
	TreeNode* root = new TreeNode(12);
	root->left = new TreeNode(7);
	root->right = new TreeNode(6);
	root->left->left = new TreeNode(9);
	root->right->left = new TreeNode(11);
	root->right->right = new TreeNode(5);
	ConnectLevelOrderSiblings(root);
}