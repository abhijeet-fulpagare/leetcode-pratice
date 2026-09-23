class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int total = 0;
        for(int num : nums)
            total += num;

        int target = total - x;


        if(target < 0)
            return -1;

        if(target == 0)
            return n;


        int l = 0;
        int sum = 0;
        int maxLen = -1;

        for(int r = 0; r < n; r++)
        {
            sum += nums[r];
            while(l <= r && sum > target)
            {
                sum -= nums[l];
                l++;
            }

            if(sum == target)
            {
                maxLen = max(maxLen, r - l + 1);
            }
        }

        if(maxLen == -1)
            return -1;

        return n - maxLen;
    }
};