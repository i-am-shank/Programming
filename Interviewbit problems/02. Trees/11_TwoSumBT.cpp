#include <iostream>
#include <queue>
#include <unordered_map>
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

int twoSum(TreeNode* root, int x, unordered_map<int,int>& nums) {
	if(root == NULL) {
		return 0;
	}
	// cout << root->val << "\n";
	if(nums.find(x - root->val) != nums.end()) {
		return 1;
	}
	else {
		nums[root->val] = 1;
		int lans = twoSum(root->left, x, nums);
		int rans = twoSum(root->right, x, nums);
		if(lans==1 || rans==1) {
			return 1;
		}
		else {
			return 0;
		}
	}
}

int t2Sum(TreeNode* root, int x) {
	if(root == NULL) {
		return 0;
	}
	unordered_map<int, int> nums;
	return twoSum(root, x, nums);
	return 0;
}

int main() {
	TreeNode* root = takeInput();
	int x;
	cin >> x;
	int ans = t2Sum(root, x);
	cout << ans << "\n";
	return 0;
}