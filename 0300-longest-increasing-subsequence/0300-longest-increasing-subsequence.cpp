class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        for(const int& num : nums) {
            if(lis.empty() || (!lis.empty() && num > lis.back())) {
                lis.push_back(num);
            } else {
                int idx = lower_bound(lis.begin(), lis.end(), num) - lis.begin();
                lis[idx] = num;
            }
        }
        return lis.size();
    }
};

