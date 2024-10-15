class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        long long ans = 0;
        while(k--) {
            double largest = pq.top();
            pq.pop();
            ans += largest;
            pq.push(ceil(largest/3));
        }
        return ans;
    }
};