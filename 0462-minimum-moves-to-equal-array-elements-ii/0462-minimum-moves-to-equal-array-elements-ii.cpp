class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());

        int ans = 0;

        int low = 0;
        int high = nums.size()-1;

        while(low <= high)
        {
            ans+=nums[high--] - nums[low++];
        }
        return ans;
    }
};