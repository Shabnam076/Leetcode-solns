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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> vals;

        for(int i = 0; i < lists.size(); i++){
            ListNode* cur = lists[i];
            while(cur){
                vals.push_back(cur->val);
                cur = cur->next;
            }
        }

        sort(vals.begin(),vals.end());

        ListNode* dummy = new ListNode();
        ListNode* head = dummy;
        for(int i = 0; i < vals.size(); i++){
            ListNode* cur = new ListNode(vals[i]);
            dummy->next = cur;
            dummy = cur;
        }

        return head->next;
        
    }
};