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

ListNode* sortBinaryLL(ListNode* head) {
	int zero = 0, one=0;
	ListNode* temp = head;
	while(temp != NULL) {
		if(temp->val == 0) {
			zero++;
		}
		else {
			one++;
		}
		temp = temp->next;
	}
	ListNode* head2 = new ListNode();
	temp = head2;
	while(zero--) {
		ListNode* curr = new ListNode(0);
		temp->next = curr;
		temp = temp->next;
	}
	while(one--) {
		ListNode* curr = new ListNode(1);
		temp->next = curr;
		temp = temp->next;
	}
	head2 = head2->next;
	head = head2;
	return head;
}

int main() {
	int n;
	cin >> n;
	ListNode* head = new ListNode();
	ListNode* temp = head;
	while(n--) {
		int ele;
		cin >> ele;
		ListNode* curr = new ListNode(ele);
		temp->next = curr;
		temp = temp->next;
	}
	head = head->next;
	ListNode* ans = sortBinaryLL(head);
	printLL(ans);
	return 0;
}