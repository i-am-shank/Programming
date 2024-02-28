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

ListNode* reverseLL(ListNode* head) {
	if(head==NULL || head->next==NULL) {
		return head;
	}
	ListNode* sans = reverseLL(head->next);
	head->next->next = head;
	head->next = NULL;
	return sans;
}

ListNode* reverseAltK(ListNode* head, int k) {
	if(head==NULL || head->next==NULL) {
		return head;
	}
	ListNode* temp = head;
	for(int i=0; i<k-1; i++) {
		if(temp != NULL) {
			temp = temp->next;
		}
		else {
			break;
		}
	}
	if(temp == NULL) {
		// reverse whole rem. LL
		ListNode* ans = reverseLL(head);
		return ans;
	}
	else {
		ListNode* save1 = temp->next;
		temp->next = NULL;
		ListNode* head2 = reverseLL(head);

		// traversed un-reversed LL
		temp = save1;
		for(int i=0; i<k-1; i++) {
			if(temp != NULL) {
				temp = temp->next;
			}
		}
		if(temp == NULL) {
			// rem. LL is unreversed
			head->next = save1;
		}
		else {
			head->next = save1;
			ListNode* save2 = reverseAltK(temp->next, k);
			temp->next = save2;
		}
		return head2;
	}
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
	ListNode* ans = reverseAltK(head, k);
	printLL(ans);
	return 0;
}