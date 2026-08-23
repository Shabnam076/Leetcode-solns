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
    void reorderList(ListNode* head) {

        //finding middle
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        //reverse links after middle
        ListNode* prev = NULL;
        ListNode* curr = slow;

        while(curr){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        //Merge both linkedlists
        ListNode* first = head;
        ListNode* sec = prev;

        while(sec->next){
            ListNode* nxt1 = first->next;
            ListNode* nxt2 = sec->next;

            first->next = sec;
            sec->next = nxt1;

            first = nxt1;
            sec = nxt2;
        }
    }
};