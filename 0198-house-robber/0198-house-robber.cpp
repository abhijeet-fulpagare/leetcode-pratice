class Solution {
public:

    int f(vector<int>& nums,int n,vector<int>&dp)
    {
        if(n == 0)
        return nums[n];

        if(dp[n] != -1)
        return dp[n];

        int pick=nums[n];

        if(n -2 >= 0)
        {
            pick+=f(nums,n-2,dp);
        }

        int np=f(nums,n-1,dp);

        return dp[n]=max(pick,np);

    }
    int rob(vector<int>& nums) 
    {
        int n=nums.size();

        vector<int>dp(n,0);

        if(n == 1)
        return nums[0];
        
        dp[0]=nums[0];

        dp[1]=max(nums[0],nums[1]);

        for(int i=2 ; i<n ; i++)
        {
           dp[i]=max( nums[i] + dp[i-2] , dp[i-1] ); 
        }

        return dp[n-1];
        
    }
};