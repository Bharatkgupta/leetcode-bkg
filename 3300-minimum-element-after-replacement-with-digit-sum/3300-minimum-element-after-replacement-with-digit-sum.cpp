class Solution {
public:
    int minElement(vector<int>& nums) {
        int mn = INT_MAX;
        for(const int& num : nums) {
            int n = num, sum = 0;
            while(n) {
                sum += n%10;
                n = n/10;
            }
            mn = min(mn, sum);
        }
        return mn;
    }
};