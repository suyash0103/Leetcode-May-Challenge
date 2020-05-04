class Solution {
public:
    int findComplement(int num) {
        string numstr = "";
        
        if(num == 0)
            return 1;
        
        while(num > 0)
        {
            if(num % 2 == 0)
                numstr = "0" + numstr;
            else
                numstr = "1" + numstr;
            num = num / 2;
        }
        
        // cout << numstr << endl;
        
        int ans = 0;
        string newnum = "";
        for(int i = 0; i < numstr.length(); i++)
        {
            if(numstr[i] == '1')
                newnum += "0";
            else
                newnum += "1";
        }
        
        // cout << newnum;
        
        for(int i = newnum.length() - 1; i >= 0; i--)
            ans += ((newnum[i] - '0') * pow(2, newnum.length() - 1 - i));
        
        return ans;
    }
};