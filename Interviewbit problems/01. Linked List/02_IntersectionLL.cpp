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

int lengthLL(ListNode* head) {
	if(head==NULL) {
		return 0;
	}
	return 1 + lengthLL(head->next);
}

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
	int l1 = lengthLL(headA);
	int l2 = lengthLL(headB);

	// traverse the extra length.. 
	ListNode* tempA = headA;
	ListNode* tempB = headB;
	// Because common-part has same-length

	if(l1 > l2) {
		int diff = l1-l2;
		while(diff--) {
			tempA = tempA->next;
		}
	}
	else {
		int diff = l2-l1;
		while(diff--) {
			tempB = tempB->next;
		}
	}

	// Now same-length remaining
	while(tempA != NULL) {
		if(tempA == tempB) {
			return tempA;
		}
		else {
			tempA = tempA->next;
			tempB = tempB->next;
		}
	}
	return tempA; // even if NULL
	// i.e. no intersection
}

int main() {
	ListNode* common = new ListNode();
	ListNode* headA = new ListNode();
	ListNode* headB = new ListNode();
	int na, rem_nb, idx_common; 
	// length of A,
	// remaining length of B, (uncommon)
	// common node-index
	cin >> na >> rem_nb >> idx_common;

	// take input LL-A
	ListNode* temp = headA;
	while(na--) {
		int ele;
		cin >> ele;
		ListNode* curr = new ListNode(ele);
		temp->next = curr;
		temp = temp->next;
		if(idx_common == 0) {
			common = curr;
		}
		idx_common--;
	}
	headA = headA->next;

	// take input LL-B
	temp = headB;
	while(rem_nb--) {
		int ele;
		cin >> ele;
		ListNode* curr = new ListNode(ele);
		temp->next = curr;
		temp = temp->next;
	}
	headB = headB->next;

	if(common != NULL) {
		temp->next = common;
	}

	ListNode* ans = getIntersectionNode(headA, headB);
	printLL(ans);
	return 0;
}