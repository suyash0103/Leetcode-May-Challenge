class Solution {
public:
    struct Compare {
        constexpr bool operator()(pair<char, int> const & a, pair<char, int> const & b) const noexcept
        { 
            return a.second < b.second; 
        }
    };
    
    string frequencySort(string s) {
        int l = s.length();
        priority_queue<pair<char, int>, vector<pair<char, int> >, Compare> pq;
        map<char, int> mp;
        for(int i = 0; i < l; i++)
            mp[s[i]]++;
        auto it = mp.begin();
        while(it != mp.end())
        {
            pair<char, int> p = {it->first, it->second};
            pq.push(p);
            it++;
        }

        string ans = "";
        while(!pq.empty())
        {
            pair<char, int> p = pq.top();
            pq.pop();
            for(int j = 0; j < p.second; j++)
                ans += p.first;
        }
        return ans;
    }
};