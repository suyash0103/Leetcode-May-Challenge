class StockSpanner {
public:
    vector<int> vec;
    stack<int> st;
    vector<int> dp;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(st.size() == 0)
        {
            st.push(0);
            dp.push_back(1);
            vec.push_back(price);
            return 1;
        }
        
        else
        {
            int ans = 1;
            if(vec[st.top()] > price)
            {
                dp.push_back(1);
                vec.push_back(price);
                st.push(vec.size() - 1);
                return ans;
            }
            else
            {
                // dp.push_back(1);
                vec.push_back(price);
                while(!st.empty() && vec[st.top()] <= price)
                {
                    int index = st.top();
                    st.pop();
                    ans += dp[index];
                }
                dp.push_back(ans);
                st.push(vec.size() - 1);
                return ans;
            }
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */