class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.begin(), horizontalCut.end(), std::greater<>());
        sort(verticalCut.begin(), verticalCut.end(), std::greater<>());
        int itrH = 0, itrV = 0, cost = 0;
        while(itrH < m-1 && itrV < n-1) {
            if(horizontalCut[itrH] > verticalCut[itrV]) {
                cost += horizontalCut[itrH]*(itrV+1);
                itrH++;
            } else {
                cost += verticalCut[itrV]*(itrH+1);
                itrV++;
            }
        }
        while(itrH < m-1) {
            cost += horizontalCut[itrH]*(n);
            itrH++;
        }
        while(itrV < n-1) {
            cost += verticalCut[itrV]*(m);
            itrV++;
        }
        return cost;
    }
};