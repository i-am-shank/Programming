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

ListNode* insertionSortList(ListNode* head) {
	if(head==NULL || head->next==NULL) {
		return head;
	}
	ListNode* head2 = new ListNode(0);
	ListNode* temp=head;
	bool noNode = true;
	while(temp!=NULL) {
		if(noNode == true) {
			// no node by default
			head2 = temp;
			noNode = false;
			temp = temp->next;
			head2->next = NULL; // disconnect
		}
		else {
			ListNode* temp2 = head2, *prev=head2;
			while(temp2!=NULL && temp2->val<temp->val) {
				prev = temp2;
				temp2 = temp2->next;
			}
			if(temp2 == head2) {
				// head is also bigger
				ListNode* curr = temp;
				temp = temp->next;
				curr->next = temp2;
				head2 = curr; // update head
			}
			else {
				prev->next = temp;
				prev = prev->next;
				temp = temp->next;
				prev->next = temp2;
			}
		}
	}
	if(noNode == true) {
		head2 = head2->next;
		noNode = false;
	}
	return head2;
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
	ListNode* ans = insertionSortList(head);
	printLL(ans);
	return 0;
}