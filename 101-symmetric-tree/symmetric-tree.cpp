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
    //preorder traversal
    bool same(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL)return true;
        if(!p || !q)return false;
        if(p->val!= q->val)return false;
        
        bool left = same(p->left,q->right);
        if(left == 0)return false;

        bool right = same(p->right, q->left);
        if(right == 0)return false;

        return true;
    }
    bool isSymmetric(TreeNode* root) {
        return same(root->left, root->right);
    }
};