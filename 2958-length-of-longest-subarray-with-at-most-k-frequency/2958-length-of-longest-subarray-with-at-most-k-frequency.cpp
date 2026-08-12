class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) 
    {
        int wsize = 0;
        int n = nums.size();
        int left = 0;


        unordered_map<int,int>mp;
        for(int right = 0 ; right < n ; right++)
        {
            mp[nums[right]]++;

            while(mp[nums[right]] > k)
            {
               mp[nums[left]]--;
               left++;
            }

            wsize = max(wsize,right-left+1);
        }

        return wsize;
    }
};