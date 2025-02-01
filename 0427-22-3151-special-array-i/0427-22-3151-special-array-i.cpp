class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size(), p = nums[0]%2;
        for(int i=1;i<n;i++) {
            int np = nums[i]%2;
            if(p == np) {
                return false;
            }
            p = np;
        }
        return true;
    }
};