class Solution {
public:
    int findSum(int i, int pick, vector<vector<int>>& mat, vector<vector<int>>& dp)
    {
        if (i == 0)
            return mat[0][pick];

        if (dp[i][pick] != INT_MAX)
            return dp[i][pick];

        int n = mat.size();
        int ans = INT_MAX;

        int st = max(0, pick - 1);
        int en = min(n - 1, pick + 1);

        for (int j = st; j <= en; j++)
        {
            ans = min(ans, findSum(i - 1, j, mat, dp) + mat[i][pick]);
        }

        return dp[i][pick] = ans;
    }

    int minFallingPathSum(vector<vector<int>>& mat)
    {
        int n = mat.size();

        int ans = INT_MAX;

        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        for (int j = 0; j < n; j++)
        {
            ans = min(ans, findSum(n - 1, j, mat, dp));
        }

        return ans;
    }
};