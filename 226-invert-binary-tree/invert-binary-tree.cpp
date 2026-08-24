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
    //Brute - O(n), O(n)
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();

            for(int i = 0; i < size; i++){
                TreeNode* p = q.front();
                q.pop();

                if(p->left)q.push(p->left);
                if(p->right)q.push(p->right);

                swap(p->left,p->right);
            }
        }

        return root;
    }


    /*
    //optimal - O(N), O(h)
    void invert(TreeNode* root){
        if(!root) return;

        swap(root->left,root->right);

        invert(root->left);
        invert(root->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
    */

};