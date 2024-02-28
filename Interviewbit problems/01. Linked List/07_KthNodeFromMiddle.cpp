#include <iostream>
using namespace std;

class ListNode{
public:
	int val;
	ListNode* next;

	// constructor
	ListNode(int x) {
		val = x;
		next = NULL;
	}
};

int findKth(ListNode* head, int k) {
	if(head==NULL) {
		return -1;
	}
	if(k == 0) {
		return head->val;
	}
	return findKth(head->next, k-1);
}

int kthNodeFromMid(ListNode* head, int k) {
	if(head==NULL) {
		return -1;
	}
	ListNode* slow=head, *fast = head;
	int len=1;
	while(fast!=NULL && fast->next!=NULL) {
		len++;
		fast = fast->next->next;
		slow = slow->next;
	}
	slow->next = NULL;

	// Now LL is only 1st half
	int ans = findKth(head, len-k-1);
	return ans;
}

int main() {
	int n, k;
	cin >> n >> k;
	ListNode* head = new ListNode(0);
	ListNode* temp = head;
	while(n--) {
		int ele;
		cin >> ele;
		ListNode* curr = new ListNode(ele);
		temp->next = curr;
		temp = temp->next;
	}
	head = head->next;
	int ans = kthNodeFromMid(head, k);
	cout << ans << "\n";
	return 0;
}