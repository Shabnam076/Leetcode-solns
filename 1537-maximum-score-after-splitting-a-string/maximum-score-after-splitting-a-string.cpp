class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        if(n == 0)return 0;
        if(n == 1)return s[0] == '0';

        vector<int> p0(n,0);   //prefix for no of zeroes
        vector<int> s1(n,0);   //suffix for no of 1s      
        
        int cnt0 = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '0')cnt0++;
            p0[i] = cnt0;
        }

        int cnt1 = 0;
        for(int j = n-1; j >= 0; j--){
            if(s[j] == '1')cnt1++;
            s1[j] = cnt1;
        }

        int maxScore = 0;
        for(int i = 0; i < n-1; i++){
            maxScore = max(maxScore, p0[i] + s1[i+1]);
        }
        
        return maxScore;
        
    }
};