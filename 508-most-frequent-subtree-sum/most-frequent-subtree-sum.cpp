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
    int find(TreeNode* root, unordered_map<int,int> &mp){
        if(!root) return 0;

        int left = find(root->left, mp);
        int right = find(root->right, mp);

        int sum = left + right + root->val;
        mp[sum]++;

        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> mp;
        find(root,mp);

        int maxi = INT_MIN;
        for(auto it : mp){
            maxi = max(maxi, it.second);
        }

        vector<int> ans;
        for(auto it: mp){
            if(it.second == maxi) ans.push_back(it.first);
        }

        return ans;
    }
};