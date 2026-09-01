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
    TreeNode* build(vector<int>& preorder, int prs, int pre, vector<int>& postorder, int pss, int pse, unordered_map<int,int> &mp){
        if(prs > pre || pss > pse)return nullptr;

        TreeNode* root = new TreeNode(preorder[prs]);
        if(prs == pre) return root;
        
        int left = mp[preorder[prs + 1]];   //index left in postorder
        int numsleft = left - pss + 1;

        root->left = build(preorder, prs + 1, prs + numsleft, postorder, pss, left,mp);
        root->right = build(preorder, prs + numsleft+1, pre,postorder, left+1,pse-1,mp);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        int m = postorder.size();
        unordered_map<int,int> mp;

        for(int i = 0; i < n; i++){
            mp[postorder[i]] = i;
        }

        return build(preorder, 0, n-1, postorder, 0, m-1, mp);
    }
};