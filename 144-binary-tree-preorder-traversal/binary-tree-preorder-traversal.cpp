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
    //Iterative
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)return ans;

        stack <TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode* Top = st.top();
            st.pop();
            if(Top->right) st.push(Top->right);
            if(Top->left) st.push(Top->left);
            ans.push_back(Top->val);
        }

        return ans;
    }
};