class StockSpanner {
    // Stack stores {price, span} pairs in decreasing price order
    stack<pair<int,int>> st;

public:
    int next(int price) {
        int span = 1;

        // Pop all entries with price <= current price and absorb their spans
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        st.push({price, span});
        return span;
    }
};