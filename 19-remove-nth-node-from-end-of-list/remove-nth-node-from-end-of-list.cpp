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
    //brute : two passes - O(2L), O(1)
    int length(ListNode* head){
        ListNode* cur = head;
        int cnt = 0;
        while(cur){
            cnt++;
            cur = cur->next;
        }
        return cnt;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = length(head);

        //remove head
        if(n == len)return head->next;

        int rem = len + 1 - n;

        ListNode* cur = head;
        int cnt = 1;

        //remove intermediate and tail 
        while(cur){
            if(cnt == rem-1){
                cur->next = cur->next->next;
                break;
            }
            cnt++;
            cur = cur->next;
        }

        return head;
        
    }
};