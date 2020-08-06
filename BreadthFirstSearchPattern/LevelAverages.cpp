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

vector<double> LevelAverages(TreeNode* root) {
	queue<TreeNode*> q;
	q.push(root);
	vector<double> ans;
	while (!q.empty()) {
		int numitemsinlevel = q.size();
		int numerator = 0;
		int size = numitemsinlevel;
		while (numitemsinlevel--) {
			TreeNode* curr = q.front();
			numerator += curr->val;
			q.pop();
			if (curr->left != NULL)	q.push(curr->left);
			if (curr->right != NULL)	q.push(curr->right);
		}
		ans.push_back((double)numerator / (double)size);
	}
	return ans;
}

int main() {
	TreeNode* root = new TreeNode(12);
	root->left = new TreeNode(7);
	root->right = new TreeNode(6);
	root->left->left = new TreeNode(9);
	root->right->left = new TreeNode(11);
	root->right->right = new TreeNode(5);
	vector<double> ans = LevelAverages(root);
	for (auto v : ans) {
		cerr << v << " ";
	}
	cerr << endl;
}