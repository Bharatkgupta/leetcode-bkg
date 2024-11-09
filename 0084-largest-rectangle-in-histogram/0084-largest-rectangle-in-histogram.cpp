class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> monoAsc;
        int n = heights.size();
        vector<int> leftBound(n);
        for(int i=0;i<n;i++) {
            while(!monoAsc.empty() && heights[monoAsc.top()] >= heights[i]) monoAsc.pop();
            leftBound[i] = !monoAsc.empty() ? monoAsc.top() : -1;
            monoAsc.push(i);
        }
        while(!monoAsc.empty()) monoAsc.pop();
        vector<int> rightBound(n);
        for(int i=n-1;i>=0;i--) {
            while(!monoAsc.empty() && heights[monoAsc.top()] >= heights[i]) monoAsc.pop();
            rightBound[i] = !monoAsc.empty() ? monoAsc.top() : n;
            monoAsc.push(i);
        }
        int mxArea = 0;
        for(int i=0;i<n;i++) {
            mxArea = max(mxArea, (rightBound[i]-leftBound[i]-1)*heights[i]);
        }
        return mxArea;
    }
};