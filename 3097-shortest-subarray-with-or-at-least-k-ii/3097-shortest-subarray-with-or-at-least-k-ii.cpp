class Solution {
    void updateBits(int num, vector<int>& bitFreq, int& subOr, bool isAdd) {
        for(int i=0;i<32;i++) {
            if(num & (1<<i)) {
                if(isAdd) {
                    if(bitFreq[i] == 0) {
                        subOr+=(1<<i);
                    }
                    bitFreq[i]++;
                } else {
                    bitFreq[i]--;
                    if(bitFreq[i] == 0) {
                        subOr-=(1<<i);
                    }
                }
            }
        }
    }
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(), subOr = 0, mnLen = n+1;
        vector<int> bitFreq(32,0);
        int s=0,e=0;
        while(e<n) {
            updateBits(nums[e], bitFreq, subOr, true);
            
            while(s<=e && subOr >= k) {
                mnLen = min(mnLen, e-s+1);
                updateBits(nums[s], bitFreq, subOr, false);
                s++;
            }
            
            e++;
        }
        return mnLen == n+1 ? -1 : mnLen;
    }
};