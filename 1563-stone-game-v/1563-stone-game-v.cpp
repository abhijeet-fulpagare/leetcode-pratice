class Solution {
public:

    int findv(int low, int high, vector<int>& pre,vector<vector<int>>& dp)
    {
        if(low >= high)
            return 0;

        if(dp[low][high] != -1)
            return dp[low][high];

        int ans = 0;

        for(int i = low; i < high; i++)
        {
            int s1 = pre[i + 1] - pre[low];
            int s2 = pre[high + 1] - pre[i + 1];

            if(s1 < s2)
            {
                ans = max(ans,s1 + findv(low, i, pre, dp));
            }
            else if(s1 > s2)
            {
                ans = max(ans,s2 + findv(i + 1, high, pre, dp));
            }
            else
            {
                ans = max(ans,s1 + max(findv(low, i, pre, dp),findv(i + 1, high, pre, dp)));
            }
        }

        return dp[low][high] = ans;
    }

    int stoneGameV(vector<int>& st) {
        int n = st.size();

        vector<int> pre(n + 1, 0);

        for(int i = 1; i <= n; i++)
            pre[i] = pre[i - 1] + st[i - 1];

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return findv(0, n - 1, pre, dp);
    }
};