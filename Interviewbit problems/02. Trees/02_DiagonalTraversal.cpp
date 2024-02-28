#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

#define pp pair<TreeNode*, int>
#define fi first
#define se second
#define mp make_pair

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

void inorder(TreeNode* root, int x, unordered_map<int, vector<int>>& mp, int& minIdx, int& maxIdx) {
	if(root == NULL) {
		return;
	}
	inorder(root->left, x-1, mp, minIdx, maxIdx);
	mp[x].push_back(root->val);
	minIdx = min(minIdx, x);
	maxIdx = max(maxIdx, x);
	inorder(root->right, x, mp, minIdx, maxIdx);
	return;
}

vector<int> diagonalTraversal(TreeNode* root) {
	vector<int> ans;
	if(root == NULL) {
		return ans;
	}
	int minIdx=0, maxIdx=0;
	unordered_map<int, vector<int>> mp;
	inorder(root, 0, mp, minIdx, maxIdx);
	for(int i=maxIdx; i>=minIdx; i--) {
		vector<int> arr = mp[i];
		for(int j=0; j<arr.size(); j++) {
			ans.push_back(arr[j]);
		}
	}
	return ans;
}

int main() {
	TreeNode* root = takeInput();
	vector<int> ans = diagonalTraversal(root);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}