class Solution {
public:

    int robber(vector<int>& nums,int b0,int b1,int limit)
    {

        int n=nums.size();
        vector<int>dp(n,0);

        
        
        dp[b0]=nums[b0];

        dp[b1]=max(nums[b0],nums[b1]);

        for(int i=b1+1 ; i<=limit ; i++)
        {
           dp[i]=max( nums[i] + dp[i-2] , dp[i-1] ); 
        }

        return dp[limit];
    }

    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        if(n == 1)
        return nums[0];

        if(n == 2)
        return max(nums[0],nums[1]);

        return max(robber(nums,0,1,n-2),robber(nums,1,2,n-1));
        
    }
};