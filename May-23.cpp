class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B){
        int n1 = A.size();
        int n2 = B.size();
        
        int i = 0, j = 0;
        vector<vector<int> > ans;
        while(i < n1 && j < n2)
        {
            if(A[i][1] >= B[j][0] && A[i][1] <= B[j][1])
            {
                int pos1 = max(A[i][0], B[j][0]);
                int pos2 = min(A[i][1], B[j][1]);
                vector<int> v;
                v.push_back(pos1);
                v.push_back(pos2);
                ans.push_back(v);
                i++;
            }
            else if(B[j][1] >= A[i][0] && B[j][1] <= A[i][1])
            {
                int pos1 = max(A[i][0], B[j][0]);
                int pos2 = min(A[i][1], B[j][1]);
                vector<int> v;
                v.push_back(pos1);
                v.push_back(pos2);
                ans.push_back(v);
                j++;
            }
            else if(A[i][1] < B[j][0])
                i++;
            else if(B[j][1] < A[i][0])
                j++;
        }
        return ans;
    }
};