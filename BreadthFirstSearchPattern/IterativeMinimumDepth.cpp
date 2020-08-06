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

int MinimumDepth(TreeNode* root) {
	queue<TreeNode*> q;
	q.push(root);
	int levels = 0;
	while (!q.empty()) {
		levels += 1;
		int size = q.size();
		bool flag = false;
		while (size--) {
			TreeNode* curr = q.front();
			q.pop();
			if (curr->left == NULL && curr->right == NULL) {
				flag = true;
				break;
			}
			if (curr->left != NULL) q.push(curr->left);
			if (curr->right != NULL) q.push(curr->right);
		}
		if (flag)
			break;
	}
	return levels;
}

int main() {
	TreeNode* root = new TreeNode(12);
	root->left = new TreeNode(7);
	root->right = new TreeNode(1);
	root->left->left = new TreeNode(9);
	root->right->left = new TreeNode(10);
	root->right->right = new TreeNode(5);
	root->right->right->left = new TreeNode(11);
	cerr << MinimumDepth(root) << endl;
}