#include <iostream>
#include <queue>
using namespace std;

class TreeNode{
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	// constructor
	TreeNode(int x) {
		val = x;
		left = NULL;
		right = NULL;
	}
};

TreeNode* takeInput() {
	int rootData;
	cin >> rootData;
	if(rootData == -1) {
		return NULL;
	}
	TreeNode* root = new TreeNode(rootData);
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty()) {
		int s = q.size();
		for(int i=0; i<s; i++) {
			TreeNode* front = q.front();
			q.pop();
			int leftData, rightData;
			cin >> leftData >> rightData;
			if(leftData != -1) {
				TreeNode* leftChild = new TreeNode(leftData);
				front->left = leftChild;
				q.push(leftChild);
			}
			if(rightData != -1) {
				TreeNode* rightChild = new TreeNode(rightData);
				front->right = rightChild;
				q.push(rightChild);
			}
		}
	}
	return root;
}

int countNodes(TreeNode* root) {
	if(root == NULL) {
		return 0;
	}
	return 1 + countNodes(root->left) + countNodes(root->right);
}

int kthsmallest(TreeNode* root, int k) {
	int lcount = countNodes(root->left);
	if(lcount >= k) {
		return kthsmallest(root->left, k);
	}
	else {
		if(lcount == k-1) {
			return root->val;
		}
		else {
			return kthsmallest(root->right, k-(lcount+1));
		}
	}
}

int main() {
	TreeNode* root = takeInput();
	int k;
	cin >> k;
	int ans = kthsmallest(root, k);
	cout << ans << "\n";
	return 0;
}