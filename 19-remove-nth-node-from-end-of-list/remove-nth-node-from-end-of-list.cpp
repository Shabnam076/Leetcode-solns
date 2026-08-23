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
    //Two Pointers - Single Pass, O(n), O(1)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* cur = dummy;
        while(n+1){    //for n+1 gap
            cur = cur->next;
            n--;
        }

        ListNode* prev = dummy;
        while(cur){             //when cur = end(nullptr), prev will be 1 node     
            cur = cur->next;      //behind nth node from back
            prev = prev->next;
        }

        prev->next = prev->next->next;

        return dummy->next;
    }
    
    /*
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
    */
};