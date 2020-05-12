class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = n - 1;
        while(start < end)
        {
            int mid = start + (end - start) / 2;
            if(mid % 2 == 0)
            {
                if(nums[mid] == nums[mid + 1])
                    start = mid + 2;
                else
                    end = mid;
            }
            else
            {
                if(nums[mid] == nums[mid - 1])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return nums[start];
    }
};