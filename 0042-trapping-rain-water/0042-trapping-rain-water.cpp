class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> prevLargest;
        int trappedWater = 0, n = height.size();
        for(int i=0;i<n;i++) {
            int water = 0;
            if(!prevLargest.empty() && height[prevLargest.top()] < height[i]) {
                int lowest = height[prevLargest.top()];
                prevLargest.pop();
                while(!prevLargest.empty() && height[prevLargest.top()] <= height[i]) {
                    water += (height[prevLargest.top()]-lowest) * (i-prevLargest.top()-1);
                    cout<<prevLargest.top()<<" "<<i<<" "<<water<<endl;
                    lowest = height[prevLargest.top()];
                    prevLargest.pop();
                }
                if(!prevLargest.empty()) {
                    water += (height[i]-lowest) * (i-prevLargest.top()-1);
                }
            }
            prevLargest.push(i);
            trappedWater += water;
        }
        return trappedWater;
    }
};