class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        if(a[0] == b[0])return a[1] > b[1];
        return a[0] < b[0];
    }

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 1)return 1;
        sort(intervals.begin(),intervals.end(),comp);

        vector<pair<int,int>> m;
        m.push_back({intervals[0][0],intervals[0][1]});

        for(int i = 1; i < n; i++){
            if(m.back().first <= intervals[i][0] && m.back().second >= intervals[i][1]) continue;
            else m.push_back({intervals[i][0],intervals[i][1]});
        }

        return m.size();
        
    }
};