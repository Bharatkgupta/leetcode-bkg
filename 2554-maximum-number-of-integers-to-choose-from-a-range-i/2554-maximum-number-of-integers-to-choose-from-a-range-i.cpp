class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        sort(banned.begin(), banned.end());
        int b = 0, cnt = 0;
        for(int i=1;i<=n;i++) {
            if(b<banned.size() && i == banned[b]) {
                b++;
                while(b<banned.size() && banned[b] == banned[b-1]) b++;
            } else {
                maxSum-=i;
                if(maxSum >= 0) {
                    cnt++;
                } else {
                    return cnt;
                }
            }
        }
        return cnt;
    }
};