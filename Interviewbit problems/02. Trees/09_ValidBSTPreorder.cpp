#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

bool hasDuplicate(vector<int>& arr) {
	int n = arr.size();
	unordered_map<int,int> mp;
	for(int i=0; i<n; i++) {
		if(mp.find(arr[i]) == mp.end()) {
			mp[arr[i]] = 1;
		}
		else {
			return true;
		}
	}
	return false;
}

int isBSTPreorder(vector<int>& arr) {
	int n = arr.size();
	bool flag = hasDuplicate(arr);
	if(flag) {
		// has duplicate elements
		return 0;
	}
	stack<int> stk;
	int root = INT_MIN;
	for(int i=0; i<n; i++) {
		while(!stk.empty() && stk.top()<arr[i]) {
			root = stk.top();
			stk.pop();
		}
		if(root > arr[i]) {
			// Only possible if top while-loop not iterates
			// A smaller element in right of root
			return 0;
		}

		// Store the nodes in stack
		stk.push(arr[i]);
	}

	// If all elements didn't invalidate BST
	return true;
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	int ans = isBSTPreorder(arr);
	cout << ans << "\n";
	return 0;
}