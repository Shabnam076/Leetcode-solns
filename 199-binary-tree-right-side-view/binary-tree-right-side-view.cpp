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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};

        map<int,int> mp; //row,value
        queue<pair<TreeNode*,int>> q; //value,row
        q.push({root,0});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* cur = p.first;
            int row = p.second;

            if(mp.find(row) == mp.end()) mp[row] = cur->val;

            if(cur->right)q.push({cur->right,row+1});
            if(cur->left)q.push({cur->left,row+1});
        }

        vector<int> ans;

        for(auto ele : mp){
            ans.push_back(ele.second);
        }

        return ans;
    }
};