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
    int f(TreeNode* root, int &sum){
        if(root == NULL)return 0;

        int leftsum = max(0,f(root->left,sum));
        int rightsum = max(0,f(root->right, sum));

        sum = max(sum, root->val + leftsum + rightsum);
        return root->val + max(leftsum,rightsum);
    }

    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        f(root,sum);

        return sum;
    }
};