class StockSpanner {
    vector<pair<int,int>> priceMem;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
        while(!priceMem.empty() && priceMem.back().first <= price) {
            span += priceMem.back().second;
            priceMem.pop_back();
        }
        priceMem.push_back({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */