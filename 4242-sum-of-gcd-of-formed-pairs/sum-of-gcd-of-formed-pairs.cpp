class Solution {
public:
typedef long long int ll;
    ll gcd(ll a, ll b){
        while(a != 0 && b != 0){
            if(a > b)a = a % b;
            else b = b % a;
        }

        return a == 0 ? b : a;
    }

    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        ll maxi = nums[0];
        vector<ll> ans(n,0);
        for(int i = 0; i < n; i++){
            maxi = max(maxi, (ll)nums[i]);
            ll cur = gcd(maxi, (ll)nums[i]);

            ans[i] = cur;
        }

        sort(ans.begin(),ans.end());
        ll sum = 0;
        for(int i = 0, j = n-1-i; i < n/2; i++){
            ll cur = gcd(ans[i],ans[j]);
            sum += cur;
            j--;
        }

        return sum;  
    }
};