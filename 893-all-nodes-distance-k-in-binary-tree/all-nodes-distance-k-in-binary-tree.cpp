/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    //using dfs 
public:
    void f(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent){
        if(!root)return;

        if(root->left) parent[root->left] = root;
        if(root->right) parent[root->right] = root;

        f(root->left,parent);
        f(root->right,parent);
    }

    void distanceK(TreeNode* root,int k, unordered_map<TreeNode*,TreeNode*> &parent, vector<int> &ans,int cnt,unordered_set<TreeNode*> &visited){
        if(!root) return;
        if(visited.count(root))return;

        visited.insert(root);  //mark visited

        if(cnt == k){
            ans.push_back(root->val);
            return;
        }
        distanceK(root->left,k,parent,ans,cnt+1,visited);
        distanceK(root->right,k,parent,ans,cnt+1,visited);
        distanceK(parent[root],k,parent,ans,cnt+1,visited);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return {};
        unordered_map<TreeNode*, TreeNode*> parent;
        f(root,parent);

        vector<int> ans;
        unordered_set<TreeNode*> visited;
        distanceK(target,k,parent,ans,0,visited);
        return ans;
    }
};