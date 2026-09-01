/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    //O(N), O(N)
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data = "";

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            for(int i= 0; i < size; i++){
                TreeNode* p = q.front();
                q.pop();

                if(p == nullptr) data += "#,";
                else data += (to_string(p->val) + ',');
                if(p != nullptr){
                    q.push(p->left);
                    q.push(p->right);
                }
            }
        }

        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() == 0)return NULL;
        stringstream s(data);
        string str;
        getline(s,str, ',');

        if(str == "#") return NULL;
        
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            getline(s,str, ',');
            if(str == "#") node->left = NULL;
            else{
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            getline(s,str, ',');
            if(str == "#"){
                node->right = NULL;
            }
            else{
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));