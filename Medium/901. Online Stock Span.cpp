// https://leetcode.com/problems/online-stock-span/

class StockSpanner {
private:
    stack<pair<int, int>> s;
public:
    StockSpanner() {
    }
    
    int next(int price) {
        int ans = 1;
        while(!s.empty() and s.top().first <= price) {
            ans = ans + s.top().second;
            s.pop();
        }
        s.push(make_pair(price, ans));

        return ans;        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */