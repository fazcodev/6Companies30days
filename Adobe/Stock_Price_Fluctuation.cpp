#define ff first
#define ss second
class StockPrice {
public:
    map<int, int>mp, cnt;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(mp.find(timestamp) != mp.end()){
            cnt[mp[timestamp]]--;
            if(!cnt[mp[timestamp]])cnt.erase(mp[timestamp]);
        }
        mp[timestamp] = price;
        cnt[price]++;
    }
    
    int current() {
        return mp.rbegin()->ss;
    }
    
    int maximum() {
        return cnt.rbegin()->ff;
    }
    
    int minimum() {
        return cnt.begin()->ff;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
