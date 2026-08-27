class Solution {
public:

    //Follow up 
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x == 0) return true;
        
        int rev = 0;
        int ori = x;

        while(x){
            int rem = x % 10;

            if(rev > INT_MAX / 10) return false;
            if(rev == INT_MAX/10 && rem > INT_MAX % 10)return false;

            rev = rev * 10 + rem;
            x /= 10;
        }

        return ori == rev;
    }

    /*
    // Time: O(N), Space: O(N)  , N -> no of digits in x.
    //can call it O(1) as well as at max 10 digits can be in INT_MAX.
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
    */
};