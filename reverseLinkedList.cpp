using namespace std;
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
		if(head == NULL) return NULL;
		 ListNode * l = head->next;
		 ListNode * temp = l;
		 head->next = NULL;
		 while(head->next != NULL){
		 	temp = temp->next;
		  l->next = head;
			head = temp;
		 }
		 return l;
    }
};
