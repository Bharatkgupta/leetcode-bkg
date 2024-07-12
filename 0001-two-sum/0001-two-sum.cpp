class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> numsMap;
        for (int i=0;i<nums.size();i++) {
            if(numsMap.count(target-nums[i])) {
                return {numsMap[target-nums[i]], i};
            }
            numsMap[nums[i]] = i;
        }
        return {};
    }
};