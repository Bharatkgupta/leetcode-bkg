class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size(), is = 0, it = 0;
        while(is<n && it<n) {
            while(is<n && start[is] == '_') is++;
            while(it<n && target[it] == '_') it++;
            
            if(start[is] != target[it]) {
                return false;
            }
            if(start[is] == 'L' && it>is) {
                return false;
            }
            if(start[is] == 'R' && is>it) {
                return false;
            }
            is++; it++;
        }
        while(is<n) {
            if(start[is] != '_') {
                return false;
            }
            is++;
        }
        while(it<n) {
            if(target[it] != '_') {
                return false;
            }
            it++;
        }
        return true;
    }
};