/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 #include<iostream>
 using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		if(list1 == NULL) return list2;
		if(list2 == NULL) return list1;
		if(list1->val <= list2->val){
			list1->next = mergeTwoLists(list1->next, list2);
			return list1;
		}
		else {
			list2->next = mergeTwoLists(list1, list2->next);
			return list2;
		}
	}
};

 int main() {
 ListNode *l = new ListNode(4);
 	for(int i = 3; i>0; i--){
		l = new ListNode(i,l);
		cout<<l->val<< " " <<l->next->val<<endl;
	}
	ListNode *l2 = new ListNode(6);
	for(int i = 5; i> 0; i--){
		l2 = new ListNode(i,l2);
	}
	Solution Sol;
	ListNode *l3 = Sol.mergeTwoLists(l, l2);
	for(int i = 0; i<10; i++){
		cout<<l3->val<<" ";
		l3 = l3->next;
	}
	return 0;
 }
