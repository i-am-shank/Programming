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

ListNode* partition(ListNode* head, int x) {
	if(head==NULL || head->next==NULL) {
		return head;
	}
	ListNode* head1 = new ListNode();
	ListNode* head2 = new ListNode();
	ListNode* temp1 = head1, *temp2 = head2, *temp = head;
	while(temp != NULL) {
		if(temp->val < x) {
			temp1->next = temp; // assign
			temp = temp->next; // iterate
			temp1 = temp1->next;
			temp1->next = NULL; // disconnect
		}
		else {
			temp2->next = temp; // assign
			temp = temp->next; // iterate
			temp2 = temp2->next;
			temp2->next = NULL; // disconnect
		}
	}
	head1 = head1->next;
	head2 = head2->next;
	if(head1 != NULL) { // end of 1st LL
		temp1->next = head2;
		return head1;
	}
	else {
		return head2;
	}
}

int main() {
	int n, x;
	cin >> n >> x;
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
	ListNode* ans = partition(head, x);
	printLL(ans);
	return 0;
}