#include <iostream>
#include <queue>
using namespace std;

class TreeNode{
public:
	int val;
	TreeNode* left;
	TreeNode* right;

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

void printTree(TreeNode* root) {
	if(root == NULL) {
		return;
	}
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty()) {
		int s = q.size();
		for(int i=0; i<s; i++) {
			TreeNode* front = q.front();
			q.pop();
			cout << front->val << " ";
			if(front->left != NULL) {
				q.push(front->left);
			}
			if(front->right != NULL) {
				q.push(front->right);
			}
		}
		cout << "\n";
	}
	return;
}

void successor(TreeNode* root, int x, int& value, TreeNode*& ans) {
	if(root == NULL) {
		return;
	}
	if(root->val > x) {
		if(root->val < value) {
			value = root->val;
			ans = root;
			// cout << root->val << " " << value << " " << ans->val << "\n";
			// call for a lesser value
			successor(root->left, x, value, ans);
		}
		else {
			// call for a lesser value
			successor(root->left, x, value, ans);
		}
	}
	else {
		// call for a larger value
		successor(root->right, x, value, ans);
	}
	return;
}

TreeNode* getSuccessor(TreeNode* root, int x) {
	if(root == NULL) {
		return NULL;
	}
	int value = INT_MAX;
	TreeNode* ans = NULL;
	successor(root, x, value, ans);
	return ans;
}

int main() {
	TreeNode* root = takeInput();
	int x;
	cin >> x;
	TreeNode* ans = getSuccessor(root, x);
	if(ans == NULL) {
		cout << -1 << "\n";
	}
	else {
		cout << ans->val << "\n";
	}
	return 0;
}