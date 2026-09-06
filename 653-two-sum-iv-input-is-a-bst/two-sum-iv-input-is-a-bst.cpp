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
    void inorder(TreeNode* root, unordered_set<int> &st){
        if(!root) return;

        inorder(root->left,st);
        st.insert(root->val);
        inorder(root->right,st);
    }
     bool check(TreeNode* root, unordered_set<int>& st, int k) {
        if(!root) return false;

        int required = k - root->val;

        if(required != root->val && st.count(required))
            return true;

        return check(root->left, st, k) ||
               check(root->right, st, k);
    }

    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> st;
        inorder(root,st);
        return check(root,st,k);   
    }
};