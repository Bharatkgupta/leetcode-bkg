class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        for(int i=0;i<n;i++) {
            times[i].push_back(i);
        }
        sort(times.begin(), times.end());
        int lastchair = 0;
        priority_queue<int, vector<int>, greater<int>> sIdx;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> leavingTimes;
        for(const auto& time : times) {
            while(!leavingTimes.empty() && leavingTimes.top().first <= time[0]) {
                sIdx.push(leavingTimes.top().second);
                leavingTimes.pop();
            }
            if(sIdx.empty()) {
                leavingTimes.push({time[1],lastchair});
                if(time[2] == targetFriend) {
                    return lastchair; 
                }
                lastchair++;
            } else {
                leavingTimes.push({time[1],sIdx.top()});
                if(time[2] == targetFriend) {
                    return sIdx.top(); 
                }
                sIdx.pop();
            }
        }
        return 0;
    }
};