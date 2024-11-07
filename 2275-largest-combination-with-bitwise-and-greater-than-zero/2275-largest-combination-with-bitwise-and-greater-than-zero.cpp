class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int cntMax = 1;
        for(int i=0;i<32;i++) {
            int cnt = 0;
            for(const int& candidate : candidates) {
                if(candidate & (1<<i)) {
                    cnt++;
                }
            }
            cntMax = max(cntMax, cnt);
        }
        return cntMax;
    }
};