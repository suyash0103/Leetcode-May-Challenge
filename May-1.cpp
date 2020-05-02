// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int i = 1, j = n;
        int ans = -1;
        
        while(i < j)
        {
            // cout << i << " " << j << endl;
            int mid = i + (j - i) / 2;
            if(isBadVersion(mid) == false)
            {
                i = mid + 1;
            }
            else
            {
                // cout << "a";
                ans = mid;
                j = mid;
            }
        }
        return i;
    }
};