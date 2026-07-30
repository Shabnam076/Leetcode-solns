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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        queue<pair<TreeNode*,long long>> q; //node,index
        q.push({root,0});
        int ans = 0;

        while(!q.empty()){
            int size = q.size();
            long long mini = q.front().second;   //mini for the current level
            long long first,last;         //to find width
            for(int i = 0; i < size; i++){
                auto p = q.front();
                q.pop();

                long long cur_idx = p.second - mini;  //modified index (0 based)
                TreeNode* node = p.first;

                if(i == 0)first = cur_idx;
                if(i == size-1)last = cur_idx;
                if(node->left)q.push({node->left, cur_idx*2 + 1}
                );
                if(node->right)q.push({node->right, cur_idx*2 + 2}
                );
            }
            ans = max(ans,(int)(last-first+1));
        }
        return ans;
    }
};