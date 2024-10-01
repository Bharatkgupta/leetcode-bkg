class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> r(k, 0);
        for(const int& num : arr) {
            int temp = num%k;
            if(temp < 0) {
                temp = k+temp;
            }
            if(temp > 0 && r[k-temp] > 0) {
                r[k-temp]--;
            } else {
                r[temp]++;
            }
        }
        for(int i=1;i<k;i++) {
            if(r[i] != 0) {
                return false;
            }
        }
        if(r[0]%2 != 0) {
            return false;
        }
        return true;
    }
};