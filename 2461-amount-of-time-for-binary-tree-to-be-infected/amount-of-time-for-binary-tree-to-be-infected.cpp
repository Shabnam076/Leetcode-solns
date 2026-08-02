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
    void traverse(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent,int start, TreeNode* &startNode){
        if(!root) return;

        if(root->left) parent[root->left] = root;
        if(root->right) parent[root->right] = root;

        if(root->val == start){
            startNode = root;
        }

        traverse(root->left,parent,start,startNode);
        traverse(root->right,parent,start,startNode);
        
    }

    int amountOfTime(TreeNode* root, int start) {
        if(root && (!root->left && !root->right)) return 0;
        
        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode* startNode = nullptr;
        traverse(root,parent,start,startNode);

        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        q.push(startNode);
        visited.insert(startNode);
        int minute = -1;

        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* cur = q.front();
                q.pop();

                if(cur->left && !visited.count(cur->left)){
                    visited.insert(cur->left);
                    q.push(cur->left);
                }
                if(cur->right && !visited.count(cur->right)){
                    visited.insert(cur->right);
                    q.push(cur->right);
                }
                if(parent.find(cur) != parent.end() && !visited.count(parent[cur])){
                    visited.insert(parent[cur]);
                    q.push(parent[cur]);
                }

            }
            minute++;
        }

        return minute; 
    }
};