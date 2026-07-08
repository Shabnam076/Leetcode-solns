class Solution {
public:
    //2d space optimization
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();

        vector<bool> prev(m+1,false),curr(m+1,false);

        prev[0] = 1;
        for(int j = 1; j <= m; j++){
            prev[j] = 0;
        }
    

        for(int i = 1; i <= n; i++){
            //calculating 0th element of curr everytime
            int flag = true;
            for(int k = 1; k <= i; k++){
                if(p[k-1] != '*'){
                    flag = false;
                    break;
                }
            }
            curr[0] = flag; 

            for(int j = 1; j <= m; j++){
                if(p[i-1] == s[j-1] || p[i-1] == '?') curr[j] = prev[j-1];  //matching

                else if(p[i-1] == '*'){
                    curr[j] = prev[j] || curr[j-1];  //* case
                }

                else curr[j] = false; //not matching

            }
            prev = curr;
        }

        return prev[m];  
    }

};