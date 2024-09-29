class AllOne {
    unordered_map<string,int> freq;
    map<int, set<string>> count;
    int mxCount;
public:
    AllOne() {
        mxCount = 0;
    }
    
    void inc(string key) {
        if(freq.count(key)) {
            count[freq[key]].erase(key);
            if(count[freq[key]].empty()) {
                count.erase(freq[key]);
            }
            freq[key]++;
            count[freq[key]].insert(key);
        } else {
            freq[key] = 1;
            count[1].insert(key);
        }
        mxCount = max(mxCount, freq[key]);
    }
    
    void dec(string key) {
        count[freq[key]].erase(key);
        if(count[freq[key]].empty()) {
            count.erase(freq[key]);
            if(mxCount == freq[key]) {
                mxCount--;
            }
        }
        freq[key]--;
        if(freq[key] != 0) {
            count[freq[key]].insert(key);
        } else {
            freq.erase(key);
        }
    }
    
    string getMaxKey() {
        return mxCount == 0 ? "" : *(count[mxCount].begin());
    }
    
    string getMinKey() {
        return count.size() == 0 ? "" : *((*(count.begin())).second.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */