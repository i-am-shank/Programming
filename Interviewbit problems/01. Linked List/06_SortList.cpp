#include <iostream>
using namespace std;

class ListNode{
public:
	int val;
	ListNode* next;

	// constructors

	ListNode(int x) {
		val = x;
		next = NULL;
	}
};

void printLL(ListNode* head) {
	if(head == NULL) {
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

ListNode* mergeLL(ListNode* head1, ListNode* head2) {
	if(head1 == NULL) {
		return head2;
	}
	if(head2 == NULL) {
		return head1;
	}
	ListNode* ans = NULL;
	if(head1->val < head2->val) {
		ans = head1;
		ans->next = mergeLL(head1->next, head2);
	}
	else {
		ans = head2;
		ans->next = mergeLL(head1, head2->next);
	}
	return ans;
}

ListNode* sortList(ListNode* head) {
	if(head==NULL || head->next==NULL) {
		return head;
	}
	ListNode* slow = head, *fast=head->next;
	while(fast!=NULL && fast->next!=NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}

	ListNode* head2 = slow->next;
	slow->next = NULL; // disconnect
	head2 = sortList(head2);
	ListNode* head1 = sortList(head);

	// merge both sorted lists
	ListNode* ans = mergeLL(head1, head2);
	return ans;
}

int main() {
	int n;
	cin >> n;
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
	ListNode* ans = sortList(head);
	printLL(ans);
	return 0;
}