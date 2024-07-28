class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int s=0, d=0, total=0;
        for(const int& num : nums) {
            if(num/10 == 0) {
                s += num;
            } else if(num/100 == 0) {
                d += num;
            }
            total += num;
        }
        return total < 2*s || total < 2*d;
    }
};