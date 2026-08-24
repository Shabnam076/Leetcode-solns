/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //O(n) time, O(n) space.
    void reverseodd(TreeNode* root){
        if(!root) return;

        int cnt = 0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<TreeNode*> level;
            for(int i = 0; i < size; i++){
                TreeNode* p = q.front();
                q.pop();

                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);

                level.push_back(p);
            }

            if(cnt % 2 == 1){
                int l = 0, r = level.size()-1;

                while(l < r){
                    swap(level[l]->val, level[r]->val);
                    l++; r--;
                }
            }
            cnt++;
        }
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        reverseodd(root);
        return root;
    }
};