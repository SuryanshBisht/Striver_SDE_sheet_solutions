// https://leetcode.com/problems/online-stock-span/submissions/
class StockSpanner {
    stack<pair<int,int>> st;
public:
    StockSpanner() {
        while(st.size()) st.pop();
    }
    
    int next(int price) {
        int days = 1;
        while(st.size() && st.top().first <= price){
            days += st.top().second;
            st.pop();
        }
        st.push({price, days});
        return days;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);  
 */