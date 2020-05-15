class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int n = A.size();
        if(n == 0)
            return 0;
        
        int flag = 0;
        int mx = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            if(A[i] >= 0)
            {
                flag = 1;
                break;
            }
            mx = max(mx, A[i]);
        }
        if(flag == 0)
            return mx;
        
        int maxsofar = 0;
        int maxhere = 0;
        for(int i = 0; i < n; i++)
        {
            maxhere += A[i];
            if(maxsofar < maxhere)
                maxsofar = maxhere;
            
            if(maxhere < 0)
                maxhere = 0;
        }
        
        int s1 = maxsofar;
        maxsofar = 0;
        maxhere = 0;
        int total = 0;
        for(int i = 0; i < n; i++)
        {
            total += A[i];
            A[i] = -A[i];
        }
        
        for(int i = 0; i < n; i++)
        {
            maxhere += A[i];
            if(maxsofar < maxhere)
                maxsofar = maxhere;
            
            if(maxhere < 0)
                maxhere = 0;
        }
        
        int s2 = total + maxsofar;
        return max(s1, s2);
    }
};