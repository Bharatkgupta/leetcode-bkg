class StockSpanner {
    stack<pair<int,int>> priceMem;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
        while(!priceMem.empty()) {
            if(priceMem.top().first <= price) {
                span += priceMem.top().second;
                priceMem.pop();
            } else {
                break;
            }
        }
        priceMem.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */