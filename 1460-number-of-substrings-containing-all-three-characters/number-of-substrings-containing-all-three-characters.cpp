class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int cnt = 0;

        int a = -1, b = -1, c = -1;
        for(int i = 0; i < n; i++){
            if(s[i] == 'a')a = i;
            else if(s[i] == 'b')b = i;
            else c = i;

            cnt += (min(a, min(b,c)) + 1);

        }
        return cnt;

        /*
        //better brute 
        int n = s.length();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            int hash[3] = {0};
            for(int j = i; j < n; j++){
                hash[s[j] - 'a'] = 1;
                if(hash[0] + hash[1] + hash[2] == 3){
                    cnt += (n-j);
                    break;
                }
            }

        }
        return cnt;
        */
        
    }
};