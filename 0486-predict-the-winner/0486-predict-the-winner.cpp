class Solution {
public:

    int f(int s,int e,int player,vector<int>& nums,vector<vector<vector<int>>>&dp)
    {

        if(dp[s][e][player] != -1)
        {
            return dp[s][e][player];
        }
        if(s == e)
        {
            if(player == 0)
            return nums[s];

            return -nums[s];
        }

        int pick = INT_MIN;
        if(player == 0)
        {
            pick = max(nums[s] + f(s+1,e,1,nums,dp) , nums[e] + f(s,e-1,1,nums,dp));
        }
        else{
            pick = min(-nums[s] + f(s+1,e,0,nums,dp) , -nums[e] + f(s,e-1,0,nums,dp));
        }
        

        return dp[s][e][player] = pick;
    }
    bool predictTheWinner(vector<int>& nums) 
    {
        int n= nums.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,0)));

        for(int i = 0; i < n; i++)
        {
            dp[i][i][0] = nums[i];
            dp[i][i][1] = -nums[i];
        }

        for(int s = n-2; s >= 0; s--)
        {
            for(int e = s+1; e < n; e++)
            {
                dp[s][e][0] = max(
                    nums[s] + dp[s+1][e][1],
                    nums[e] + dp[s][e-1][1]
                );

                dp[s][e][1] = min(
                    -nums[s] + dp[s+1][e][0],
                    -nums[e] + dp[s][e-1][0]
                );
            }
        }

        return dp[0][n-1][0] >= 0;

        
    }   
};