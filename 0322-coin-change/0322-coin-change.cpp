class Solution {
public:
    
    int f(int idx,vector<int>& coins, int amount,vector<vector<int>>&dp)
    {
        if(amount == 0)
        return 0;

        if(idx < 0)
        {
            return INT_MAX;
        }

        if(dp[idx][amount] != -1)
        {
            return dp[idx][amount];
        }

        int pick = INT_MAX;
        
        if(coins[idx] <= amount)
        {
            pick = min(f(idx,coins,amount-coins[idx],dp),f(idx-1,coins,amount-coins[idx],dp));

            if(pick != INT_MAX)
            pick++;
        }

        int nopick = f(idx-1,coins,amount,dp);


        return dp[idx][amount] = min(pick,nopick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();

        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int t= f(n-1,coins,amount,dp);

        return t == INT_MAX ? -1 : t;
    }
};