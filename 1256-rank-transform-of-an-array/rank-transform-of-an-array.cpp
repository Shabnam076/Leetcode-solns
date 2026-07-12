class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n == 0) return {};

        vector<int> temp(n,0);

        unordered_map<int,int> f;
        for(int i = 0; i < n; i++){
            temp[i] = arr[i];
        }

        int cnt = 0; 
        sort(temp.begin(),temp.end());
        for(int i = 0; i < n; i++){
            if(f.find(temp[i]) == f.end() || i == 0){
                cnt++;
            }
            f[temp[i]] = cnt;
        }

        for(int i = 0; i < n; i++){
            temp[i] = f[arr[i]];
        }

        return temp;

        
    }
};