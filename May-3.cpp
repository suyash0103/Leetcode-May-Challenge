class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int l1 = ransomNote.length();
        int l2 = magazine.length();
        map<char, int> mp;
        for(int i = 0; i < l2; i++)
            mp[magazine[i]]++;
        
        for(int i = 0; i < l1; i++)
        {
            if(mp.find(ransomNote[i]) == mp.end())
                return false;
            mp[ransomNote[i]]--;
            if(mp[ransomNote[i]] == 0)
                mp.erase(ransomNote[i]);
        }
        return true;
    }
};