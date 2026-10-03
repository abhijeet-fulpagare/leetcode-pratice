class Solution {
public:
    int f(string &s, int i, vector<int>& dp)
    {
        if(i < 0)
            return 0;

        if(dp[i] != -1)
            return dp[i];

        if(s[i] == '(')
            return dp[i] = 0;

        if(i >= 1 && s[i-1] == '(')
        {
            dp[i] = 2 + f(s, i-2, dp);
        }
        else
        {
           int prev = f(s, i-1, dp);

            int j = i - prev - 1;

            if(j >= 0 && s[j] == '(')
            {
                dp[i] = prev + 2 + f(s, j-1, dp);
            }
            else
            {
                dp[i] = 0;
            }
        }

        return dp[i];
    }

    int longestValidParentheses(string s)
    {
        int n = s.size();

        vector<int> dp(n, -1);

        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            ans = max(ans, f(s, i, dp));
        }

        return ans;
    }
};