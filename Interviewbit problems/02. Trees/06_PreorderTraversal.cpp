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

void preorder(TreeNode* root, vector<int>& ans) {
	if(root == NULL) {
		return;
	}
	ans.push_back(root->val);
	preorder(root->left, ans);
	preorder(root->right, ans);
	return;
}

vector<int> preorderTraversal(TreeNode* root) {
	vector<int> ans;
	preorder(root, ans);
	return ans;
}

int main() {
	TreeNode* root = takeInput();
	vector<int> ans = preorderTraversal(root);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}