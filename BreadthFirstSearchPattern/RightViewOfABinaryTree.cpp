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

vector<int> RightViewOfABinaryTree(TreeNode* root) {
	queue<TreeNode*> q;
	q.push(root);
	vector<int> v;
	while (!q.empty()) {
		int numitemsinlevel = q.size();
		for (int i = 1; i <= numitemsinlevel; i++) {
			TreeNode* curr = q.front();
			if (i == numitemsinlevel)
				v.push_back(curr->val);
			q.pop();
			if (curr->left != NULL) q.push(curr->left);
			if (curr->right != NULL) q.push(curr->right);
		}
	}
	return v;
}

int main() {
	TreeNode* root = new TreeNode(12);
	root->left = new TreeNode(7);
	root->right = new TreeNode(1);
	root->left->left = new TreeNode(9);
	root->left->left->left = new TreeNode(3);
	root->right->left = new TreeNode(10);
	root->right->right = new TreeNode(5);
	vector<int> v = RightViewOfABinaryTree(root);
	for (int x : v)
		cerr << x << " ";
	cerr << endl;
}