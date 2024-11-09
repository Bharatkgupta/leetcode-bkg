class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> prevH;
        int water = 0, n = height.size();
        for(int i=0;i<n;i++) {
            while(!prevH.empty() && height[prevH.top()] <= height[i]) {
                int low = height[prevH.top()];
                prevH.pop();
                if(!prevH.empty()) {
                    water += (min(height[prevH.top()], height[i])-low)*(i-prevH.top()-1);
                }
                // cout<<water<<" ";
            }
            prevH.push(i);
        }
        return water;
    }
};