class Solution {
public:

    int f(int s,int e,int player,vector<int>& nums,vector<vector<vector<int>>>&dp)
    {
        if(s > e)
        return 0;

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
    bool stoneGame(vector<int>& piles) {
        int n= piles.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,-1)));

        int x =f(0,n-1,0,piles,dp);

        return x < 0 ? 0 : 1;
    }
};