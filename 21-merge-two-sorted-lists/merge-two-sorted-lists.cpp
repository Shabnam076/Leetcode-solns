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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;

        if(!list1)return list2;
        if(!list2)return list1;

        while(list1 && list2){
            if(list1->val <= list2->val){
                ListNode* curr = new ListNode(list1->val);
                dummy->next = curr;
                dummy = curr;
                list1 = list1->next;
            }
            else{
                ListNode* curr = new ListNode(list2->val);
                dummy->next = curr;
                dummy = curr;
                list2 = list2->next;
            }
        }

        if(list1){
            dummy->next = list1;
        }
        else{
            dummy->next = list2;
        }

        return cur->next;
        
    }
};