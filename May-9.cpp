class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1)
            return true;
        
        int left = 1, right = num / 2;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(pow(mid, 2) == num)
                return true;
            if(pow(mid, 2) > num)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return false;
        
        // int k = 1;
        // while(true)
        // {
        //     if(pow(k, 2) == num)
        //         return true;
        //     if(pow(k, 2) > num)
        //         return false;
        //     if(pow(k, 2) < num)
        //         k++;
        // }
        // return false;
    }
};