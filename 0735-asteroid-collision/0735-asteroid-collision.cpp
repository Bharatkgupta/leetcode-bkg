class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> finalState;
        for(const int& asteroid : asteroids) {
            if(asteroid > 0) {
                finalState.push_back(asteroid);
            } else {
                while(!finalState.empty() && finalState.back() > 0 && finalState.back() < abs(asteroid)) {
                    finalState.pop_back();
                }
                if(!finalState.empty() && finalState.back() > 0) {
                    if(finalState.back() == abs(asteroid)) {
                        finalState.pop_back();
                    }
                    continue;
                } else {
                    finalState.push_back(asteroid);
                }
            }
        }
        return finalState;
    }
};