class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int mx = 0, n = nums.size();
        for(const int& num : nums) {
            mx = max(mx,num);
        }
        vector<bool> isPrime(mx+1, true);
        isPrime[0] = isPrime[1] = false;
        for(int i=2; i*i < mx+1;i++) {
            if(isPrime[i]) {
                for(int j=i*i;j < mx+1;j=j+i) {
                    isPrime[j] = false;
                }
            }
        }
        
        for(int i=n-2;i>=0;i--) {
            if(nums[i] >= nums[i+1]) {
                bool flag = true;
                for(int j=2;j<nums[i];j++) {
                    if(isPrime[j] && nums[i+1] > nums[i]-j) {
                        flag = false;
                        nums[i] = nums[i]-j;
                        break;
                    }
                }
                if(flag) {
                    return false;
                }
            }
        }
        return true;
    }
};