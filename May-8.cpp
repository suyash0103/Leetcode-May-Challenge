class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        double num, den;
        if(n <= 2)
            return true;
        
        num = coordinates[1][1] - coordinates[0][1];
        den = coordinates[1][0] - coordinates[0][0];
        
        if(den == 0)
        {
            int newden;
            for(int i = 1; i < n - 1; i++)
            {
                newden = coordinates[i + 1][0] - coordinates[i][0];
                if(newden != 0)
                    return false;
            }
            return true;
        }
        else
        {
            double slope = num / den;
            double newnum;
            double newden;
            double newslope;
            for(int i = 1; i < n - 1; i++)
            {
                newnum = coordinates[i + 1][1] - coordinates[i][1];
                newden = coordinates[i + 1][0] - coordinates[i][0];
                if(newden == 0)
                    return false;
                newslope = newnum / newden;
                if(slope != newslope)
                    return false;
            }
            return true;
        }
    }
};