class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> query(n);
        int x = 0;
        for(int i=0;i<n;i++) {
            x ^= nums[i];
            int k = 0;
            for(int j=0;j<maximumBit;j++) {
                if(!(x & (1<<j))) {
                    k += (1<<j);
                }
            }
            query[n-i-1] = k;
        }
        return query;
    }
};