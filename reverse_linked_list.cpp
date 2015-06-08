#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next ==NULL)
			return head;
		ListNode* ptr1 = NULL;
		ListNode* ptr2 = head->next;
		while (ptr2!=NULL)
		{
			head->next = ptr1; 
			ptr1 = head;
			head = ptr2;
			ptr2 = ptr2->next;
		}
		head->next = ptr1;
		return head;
	}

	ListNode* reverseList(ListNode* head) {

	}
};