class Solution {
public:

    bool f(int target , int idx,vector<int>& nums,vector<vector<int>>&dp)
    {

        if(target < 0)
        return false;

        if(target == 0)
            return true;

        if(idx < 0)
            return false;

        if(dp[idx][target] != -1)
            return dp[idx][target];


        bool left = f(target - nums[idx],idx-1,nums,dp);
        bool right =f(target , idx-1, nums,dp);

        return dp[idx][target] = (left | right);



    }
    
    bool canPartition(vector<int>& nums) {
        
        int n =nums.size();
        int sum =0;
        for(int i=0 ; i<n ; i++)
        {
            sum+=nums[i];
        }


        if(sum % 2 != 0)
        {
            return 0;
        }

        int target= sum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));

        return f(target,n-1,nums,dp);

    }
};