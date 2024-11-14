class Solution {
    bool distribute(int n, vector<int>& quantities, int mxQ) {
        int stores = 0;
        for(const int& quantity : quantities) {
            int remaining = quantity;
            while(remaining > 0) {
                stores++;
                if(stores > n) {
                    return false;
                }
                remaining -= mxQ;
            }
        }
        if(stores > n) {
            return false;
        }
        return true;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int s=0, e=0;
        for(const int& quantity : quantities) {
            e = max(e, quantity);
        }
        
        while(s<=e) {
            int m = s + (e-s)/2;
            
            if(distribute(n, quantities, m)) {
                e = m-1;
            } else {
                s = m+1;
            }
        }
        return s;
    }
};