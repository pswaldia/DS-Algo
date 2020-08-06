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

vector<vector<int> > LevelOrderTraversal(TreeNode* root) {
	queue<TreeNode*> q;
	q.push(root);
	vector<vector<int> > ans;
	while (!q.empty()) {
		int numitemsinlevel = q.size();
		vector<int> v;
		while (numitemsinlevel--) {
			TreeNode* curr = q.front();
			v.push_back(curr->val);
			q.pop();
			if (curr->left != NULL)	q.push(curr->left);
			if (curr->right != NULL)	q.push(curr->right);
		}
		ans.push_back(v);
	}
	return ans;
}

int main() {
	TreeNode* root = new TreeNode(12);
	root->left = new TreeNode(7);
	root->right = new TreeNode(1);
	root->left->left = new TreeNode(9);
	root->right->left = new TreeNode(10);
	root->right->right = new TreeNode(5);
	vector<vector<int> > ans = LevelOrderTraversal(root);
	for (auto v : ans) {
		for (int x : v) {
			cerr << x << " ";
		}
		cerr << endl;
	}
}