class Solution {
public:
    //tabulation - O(n*m), O(m)
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        vector<int> cur(m+1,0), next(m+1,0);
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                int same = 0;
                if(text1[i] == text2[j]){     //both char same
                    same = 1 + next[j+1];
                }
                else{   //both char not same
                    same = max(cur[j+1], next[j]);
                }
                cur[j] = same;
            }
            next = cur;
        }
        return next[0];
    }
};