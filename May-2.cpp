class Solution {
public:
    int numJewelsInStones(string J, string S) {
        map<char, int> mp;
        for(int i = 0; i < J.length(); i++)
            mp[J[i]]++;
        int ans = 0;
        for(int i = 0; i < S.length(); i++)
        {
            if(mp.find(S[i]) != mp.end())
                ans++;
        }
        return ans;
    }
};