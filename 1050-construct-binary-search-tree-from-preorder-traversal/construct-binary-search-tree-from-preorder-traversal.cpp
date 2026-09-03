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
    TreeNode* build(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie, unordered_map<int,int>& mp){
        if(ps > pe || is > ie) return NULL;

        TreeNode* root = new TreeNode(preorder[ps]);
        int inroot = mp[preorder[ps]];
        int numsleft = inroot - is;

        root->left = build(preorder, ps+1, ps+ numsleft, inorder,is, inroot-1, mp);
        root->right = build(preorder, ps+ numsleft + 1, pe, inorder, inroot+1, ie, mp);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(),inorder.end());

        unordered_map<int,int> mp;
        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }

        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1,mp);    
    }
};