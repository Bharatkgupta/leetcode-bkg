class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> window;
        int n = nums.size();
        vector<int> mxSlide;
        for(int i=0;i<n;i++) {
            while(!window.empty() && nums[window.back()] < nums[i]) window.pop_back();
            window.push_back(i);
            if(i>=k-1) {
                while(!window.empty() && window.front() < i-k+1) window.pop_front();
                mxSlide.push_back(nums[window.front()]);
            }
        }
        return mxSlide;
    }
};