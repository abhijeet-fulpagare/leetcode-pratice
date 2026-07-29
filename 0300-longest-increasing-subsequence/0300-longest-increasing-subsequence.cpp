class Solution {
public:

    int f(int ind , int prev_ind,vector<int>& nums,vector<vector<int>>&dp)
    {
        int n = nums.size();

        if(ind > n)
        return   0;

        if(dp[ind][prev_ind] != -1)
        return dp[ind][prev_ind];

        int p1 = 0;
        if(prev_ind == 0 || nums[ind-1] > nums[prev_ind-1])
        {
            p1 = 1 + f(ind+1,ind,nums,dp);
        }

        int p2 = f(ind+1,prev_ind,nums,dp);

        return dp[ind][prev_ind] = max(p1,p2);
    }
    int lengthOfLIS(vector<int>& nums) 
    {
        int n= nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n,-1));
        return f(1,0,nums,dp);
        
    }
};