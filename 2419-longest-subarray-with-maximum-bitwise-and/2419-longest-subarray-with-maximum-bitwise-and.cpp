class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mxSubarray = 1, currSubarray = 0, mxValue = nums[0];
        for(const int& num : nums) {
            if(mxValue == num) {
                currSubarray++;
                mxSubarray = max(mxSubarray, currSubarray);
            } else {
                if(num > mxValue) {
                    mxValue = num;
                    mxSubarray = 1;
                    currSubarray = 1;
                } else {
                    currSubarray = 0;
                }
            }
        }
        return mxSubarray;
    }
};

// [311155,311155,311155,311155,311155,311155,311155,311155,201191,311155]