#include <iostream>
using namespace std;

class ListNode{
public:
	int val;
	ListNode* next;

	// constructors
	ListNode() {
		val = 0;
		next = NULL;
	}

	ListNode(int x) {
		val = x;
		next = NULL;
	}
};

void printLL(ListNode* head) {
	if(head==NULL) {
		cout << "\n";
		return;
	}
	ListNode* temp = head;
	while(temp != NULL) {
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << "\n";
	return;
}

ListNode* reverseList(ListNode* head) {
	if(head==NULL || head->next==NULL) {
		return head;
	}
	// 1->2->3->4->NULL
	
	ListNode* sans = reverseList(head->next);
	// sans   ..   4->3->2->NULL

	head->next->next = head;
	head->next = NULL;
	return sans;
}

int main() {
	int n;
	cin >> n;
	ListNode * head = new ListNode();
	ListNode* temp = head;
	for(int i=0; i<n; i++) {
		int ele;
		cin >> ele;
		ListNode* curr = new ListNode(ele);
		temp->next = curr;
		temp = temp->next;
	}
	head = head->next;

	// head --> input linked-list head

	ListNode* ans = reverseList(head);
	printLL(ans);
	return 0;
}