class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
        int prev = threshold, n = height.size();
        vector<int> ans;
        for(int i=0;i<n;i++) {
            if(prev > threshold) {
                ans.push_back(i);
            }
            prev = height[i];
        }
        return ans;
    }
};