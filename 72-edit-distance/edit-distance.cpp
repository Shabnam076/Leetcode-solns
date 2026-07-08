class Solution {
public:
    //2d optimised
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<int> prev(n+1,0),curr(n+1,0);

        for(int i = 0; i <= n; i++){   //0th row
            prev[i] = i;
        }

        for(int i = 1; i <= m; i++){
            curr[0] = i;              //imp

            for(int j = 1; j <= n; j++){
                if(word1[i-1] == word2[j-1]){
                    curr[j] = prev[j-1];    
                }
                else{
                    int replace = 1 + prev[j-1];
                    int del = 1 + prev[j];
                    int insert = 1 + curr[j-1];
                    curr[j] = min(replace,min(del,insert));
                }
            }
            prev = curr;
        }

        return prev[n];
    }
};