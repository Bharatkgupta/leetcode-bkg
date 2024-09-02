class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        int n = chalk.size(), i = 0;
        for(;i<n;i++) {
            sum += chalk[i];
        }
        int remaining = k%sum;
        for(i = 0;i<n;i++) {
            remaining -= chalk[i];
            if(remaining < 0) {
                break;
            }
        }
        return i;
    }
};