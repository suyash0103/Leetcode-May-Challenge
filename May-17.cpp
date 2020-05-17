class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        sort(p.begin(), p.end());
        vector<int> ans;

        int l = p.length();
        int n = s.length();
        if(l > n)
            return ans;
        
        multiset<char> st;
        for(int i = 0; i < l; i++)
            st.insert(p[i]);
        
        for(int i = 0; i <= n - l; i++)
        {
            if(st.find(s[i]) != st.end())
            {
                string sub = s.substr(i, l);
                sort(sub.begin(), sub.end());
                if(sub.compare(p) == 0)
                {
                    ans.push_back(i);
                    int flag = 0;
                    while(i + l < n && s[i] == s[i + l])
                    {
                        i++;
                        ans.push_back(i);
                        flag = 1;
                    }
                    
                    if(i + l < n && (st.find(s[i + l]) == st.end()))
                    {
                        i = i + l;
                    }
                    else if(i + l < n && (st.find(s[i + l]) != st.end()))
                    {
                        char ch = s[i + l];
                        while(i < n && s[i] != ch)
                        {
                            i++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};