class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        vector<int> freq(k+1, 0);
        int n = nums.size();
        int s = 0, e = n-1;
        while(s<e) {
            freq[abs(nums[s]-nums[e])]++;
            s++;
            e--;
        }
        int mx = 0, mxFreq = 0, mxFreq2 = 0;
        for(int i=0;i<=k;i++) {
            if(mx < freq[i]) {
                mx = freq[i];
                mxFreq2 = mxFreq;
                mxFreq = i;
            } else if(mx == freq[i] && mxFreq > i) {
                mxFreq2 = mxFreq;
                mxFreq = i;
            }
        }
        s = 0, e = n-1;
        int ans1 = 0;
        while(s<e) {
            if(abs(nums[s]-nums[e]) == mxFreq) {
                s++;e--;
                continue;
            }
            if(k - nums[s] >= mxFreq || k-nums[e] >= mxFreq || nums[e] >= mxFreq || nums[s] >= mxFreq) {
                ans1++;
            } else {
                ans1 = ans1 + 2;
            }
            s++;
            e--;
        }
        s = 0, e = n-1;
        int ans2 = 0;
        while(s<e) {
            if(abs(nums[s]-nums[e]) == mxFreq2) {
                s++;e--;
                continue;
            }
            if(k - nums[s] >= mxFreq2 || k-nums[e] >= mxFreq2 || nums[e] >= mxFreq2 || nums[s] >= mxFreq2) {
                ans2++;
            } else {
                ans2 = ans2 + 2;
            }
            s++;
            e--;
        }
        return min(ans1,ans2);
    }
};