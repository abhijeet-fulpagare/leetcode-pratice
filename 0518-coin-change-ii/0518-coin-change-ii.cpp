class Solution {
public:
    int f(int idx, int target, vector<int>& coins, int sum,
          vector<vector<int>>& dp) {

        if (idx == 0) {
            int rem = target - sum;
            return (rem % coins[0] == 0);
        }

        if (dp[idx][sum] != -1)
            return dp[idx][sum];

        int pick = 0;

        if (sum + coins[idx] <= target)
            pick = f(idx, target, coins, sum + coins[idx], dp);

        int notPick = f(idx - 1, target, coins, sum, dp);

        return dp[idx][sum] = pick + notPick;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        return f(n - 1, amount, coins, 0, dp);
    }
};