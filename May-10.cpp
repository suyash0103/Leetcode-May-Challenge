class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        map<int, int> intrust;
        map<int, int> outtrust;
        
        if(N == 1)
            return 1;
        
        int n = trust.size();
        for(int i = 0; i < n; i++)
        {
            int person1 = trust[i][0];
            int person2 = trust[i][1];
            
            intrust[person2]++;
            outtrust[person1]++;
        }

        auto it = intrust.begin();
        while(it != intrust.end())
        {
            if(it->second == N - 1 && outtrust.find(it->first) == outtrust.end())
                return it->first;
            it++;
        }
        return -1;
    }
};