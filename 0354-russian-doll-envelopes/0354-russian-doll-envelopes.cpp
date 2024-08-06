class Solution {
    static bool comp(vector<int>& a, vector<int>& b) {
        if(a[0] == b[0]) {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comp);
        int n = envelopes.size(), ans = 1;
        vector<int> lis;
        lis.push_back(envelopes[0][1]);
        for(int i=1;i<n;i++) {
            int index = lower_bound(lis.begin(), lis.end(), envelopes[i][1]) - lis.begin();
            if(index == lis.size()) {
                lis.push_back(envelopes[i][1]);
            } else {
                lis[index] = envelopes[i][1];
            }
        }
        return lis.size();
    }
};