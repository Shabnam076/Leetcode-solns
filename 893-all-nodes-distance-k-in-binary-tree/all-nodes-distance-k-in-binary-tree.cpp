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
    //using bfs 
public:
    void f(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent){
        if(!root)return;

        if(root->left) parent[root->left] = root;
        if(root->right) parent[root->right] = root;

        f(root->left,parent);
        f(root->right,parent);
    }

    void distanceK(TreeNode* root,int k, unordered_map<TreeNode*,TreeNode*> &parent, vector<int> &ans){
        queue<TreeNode*> q;
        q.push(root);

        unordered_set<TreeNode*> visited;
        visited.insert(root);
        int cnt = 0;
        while(!q.empty()){
            if(cnt == k) break;
            int size = q.size();
            for(int i = 0; i < size; i++){

                TreeNode* p = q.front();
                q.pop();

                if(p->left && !visited.count(p->left) ){
                    q.push(p->left);
                    visited.insert(p->left);
                }
                if(p->right && !visited.count(p->right)){
                    q.push(p->right);
                    visited.insert(p->right);
                }
                if(parent[p] && !visited.count(parent[p])){
                    q.push(parent[p]);
                    visited.insert(parent[p]);
                }
            }
            cnt++;
        }

        while(!q.empty()){
            TreeNode* cur = q.front();
            ans.push_back(cur->val);
            q.pop();
        }
        
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return {};
        unordered_map<TreeNode*, TreeNode*> parent;
        f(root,parent);

        vector<int> ans;
        distanceK(target,k,parent,ans);
        return ans;
    }
};