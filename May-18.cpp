class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(), s1.end());
        
        multiset<char> st;
        map<char, int> mp;
        
        for(int i = 0; i < s1.length(); i++)
            mp[s1[i]]++;
        
        int l = s1.length();
        int n = s2.length();
        
        for(int i = 0; i <= n - l; i++)
        {
            if(mp.find(s2[i]) != mp.end())
            {
                map<char, vector<int>> check;
                int k = 1;
                int flag = 0;
                while(i < n && k <= l)
                {
                    if(mp.find(s2[i]) != mp.end())
                    {
                        check[s2[i]].push_back(i);
                        if(check[s2[i]].size() > mp[s2[i]])
                        {
                            i = check[s2[i]][0];
                            flag = 1;
                            break;
                        }
                    }
                    else
                    { 
                        flag = 1;
                        break;
                    }
                    k++;
                    i++;
                }
                if(flag == 0)
                    return true;
                // i--;
            }
        }
        return false;
    }
};