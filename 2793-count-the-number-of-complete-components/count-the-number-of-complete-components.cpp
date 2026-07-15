class Solution {
public:
    void dfs(int node,vector<vector<int>>& g,vector<int>& vis,int& nodes,int& degreeSum){
        vis[node] = 1;

        nodes++;
        degreeSum += g[node].size();

        for(auto child : g[node]){
            if(!vis[child]){
                dfs(child,g,vis,nodes,degreeSum);
            }
        }

    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> vis(n,0);
        int ans = 0;

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                int nodes = 0;
                int dsum = 0;
                dfs(i,g,vis,nodes,dsum);

                int edge = dsum/2;
                if(edge == (nodes * (nodes-1))/2) ans++;
            }
        }
        return ans;   
        
    }
};