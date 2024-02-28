#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

#define pp pair<int,int>
#define pp2 pair<TreeNode*, int>
#define mp make_pair
#define fi first
#define se second

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

// level-order traversal ---------
void traverse(TreeNode* root, int x, unordered_map<int,vector<int>>& values, int& minIdx, int& maxIdx) {
	if(root == NULL) {
		return;
	}
	queue<pp2> q;
	q.push(mp(root, x));
	while(!q.empty()) {
		int s = q.size();
		for(int i=0; i<s; i++) {
			pp2 front = q.front();
			q.pop();
			// cout << front.fi->val << " -> " << front.se << "\n";
			values[front.se].push_back(front.fi->val);
			minIdx = min(minIdx, front.se);
			maxIdx = max(maxIdx, front.se);
			if(front.fi->left != NULL) {
				q.push(mp(front.fi->left, front.se-1));
			}
			if(front.fi->right != NULL) {
				q.push(mp(front.fi->right, front.se+1));
			}
		}
	}
	return;
}

vector<vector<int>> verticalOrderTraversal(TreeNode* root) {
	// map<int,int> values;
	unordered_map<int,vector<int>> values;
	vector<vector<int>> ans;
	if(root == NULL) {
		return ans;
	}
	int minIdx=0, maxIdx=0;
	traverse(root, 0, values, minIdx, maxIdx);
	for(int i=minIdx; i<=maxIdx; i++) {
		ans.push_back(values[i]);
	}
	return ans;
}

int main() {
	TreeNode* root = takeInput();
	vector<vector<int>> ans = verticalOrderTraversal(root);
	for(int i=0; i<ans.size(); i++) {
		for(int j=0; j<ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}