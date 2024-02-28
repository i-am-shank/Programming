#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

#define pp pair<TreeNode*, long>
#define fi first
#define se second
#define mp make_pair
#define ll long

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

void levelOrder(TreeNode* root, ll& covered, ll& uncovered) {
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
			if(i==0 || i==s-1) {
				covered += front->val;
			}
			else {
				uncovered += front->val;
			}
			if(front->left != NULL) {
				q.push(front->left);
			}
			if(front->right != NULL) {
				q.push(front->right);
			}
		}
	}
	return;
}

ll coveredNodes(TreeNode* root) {
	ll covered = 0, uncovered = 0;
	levelOrder(root, covered, uncovered);
	return abs(covered-uncovered);
}

int main() {
	TreeNode* root = takeInput();
	ll ans = coveredNodes(root);
	cout << ans << "\n";
	return 0;
}