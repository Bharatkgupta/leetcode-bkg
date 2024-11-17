class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        map<int,int> swip;
        for(const auto& query : queries) {
            swip[query[0]] += 1;
            swip[query[1]+1] += -1;
        }

        int n = nums.size(), canRemove = 0;
        auto itr = swip.begin();
        for(int i=0;i<n;i++) {
            if((*itr).first == i) {
                canRemove += (*itr).second;
                itr++;
            }

            if(nums[i] > canRemove) {
                return false;
            }
        }
        return true;
    }
};