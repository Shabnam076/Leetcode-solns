class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x == 0) return true;
        
        string rev = to_string(x);
        int l = 0, r = rev.length()-1;

        while(l <= r){
            if(rev[l] != rev[r]) return false;
            l++; r--;
        }

        return true;
    }
};