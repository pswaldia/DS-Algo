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

void PrintTreeThroughNextPointer(TreeNode* root) {
	TreeNode* temp = root;
	while (temp != NULL) {
		cerr << temp->val << " ";
		temp = temp->next;
	}
	cerr << endl;
}

void ConnectAllLevelOrderSiblings(TreeNode* root) {
	queue<TreeNode*> q;
	q.push(root);
	TreeNode* prev = NULL;
	while (!q.empty()) {
		int numitemsinlevel = q.size();
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
	ConnectAllLevelOrderSiblings(root);
	PrintTreeThroughNextPointer(root);
}