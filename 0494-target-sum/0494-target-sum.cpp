class Solution {
public:
    int f(int idx,vector<int>& nums, int target,int temp,vector<unordered_map<int, int>>&dp)
    {
        if(idx == 0)
        {
            int cnt =0 ;

            if(temp - nums[idx] == target)
            cnt++;

            if(temp + nums[idx] == target)
            cnt++;

            return cnt;
        }

        if(dp[idx].count(temp) >= 1)
        {
            return dp[idx][temp];
        }


        int p1 = f(idx-1,nums,target,temp-nums[idx],dp);
        int p2 = f(idx-1,nums,target,temp+nums[idx],dp);


        return dp[idx][temp]=p1+p2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<unordered_map<int, int>> dp(n);
        return f(n-1,nums,target,0,dp);
    }
};