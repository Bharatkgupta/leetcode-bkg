class LRUCache {
    int c;
    unordered_map<int,pair<int, list<int>::iterator>> cache;
    list<int> lruList;
public:
    LRUCache(int capacity) {
        c = capacity;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()) {
            return -1;
        }
        lruList.erase(cache[key].second);
        lruList.push_front(key);
        cache[key].second = lruList.begin();
        return cache[key].first;
    }
    
    void put(int key, int value) {
        if(cache.find(key) == cache.end() && lruList.size() == c) {
            int keyToRemove = lruList.back();
            lruList.pop_back();
            cache.erase(keyToRemove);
        }
        if(cache.find(key) != cache.end()) {
            lruList.erase(cache[key].second);
        }
        lruList.push_front(key);
        cache[key] = {value, lruList.begin()};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */