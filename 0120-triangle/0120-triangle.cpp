class Solution {
public:

    int findSum(vector<vector<int>>&t,int idx,int pick,int n,vector<vector<int>>&dp)
    {
        if(idx == n-1)
        {
            return t[idx][pick];
        }

        if(dp[idx][pick] != -1)
        return dp[idx][pick];

        int p1 = findSum(t,idx+1,pick,n,dp) ;
        int p2 = findSum(t,idx+1,pick+1,n,dp) ;

        return dp[idx][pick] = min(p1,p2)+t[idx][pick];

    }
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        
        int n=triangle.size();
        int m=triangle[n-1].size();
        vector<vector<int>>dp(n,vector<int>(m,0));

        for(int i=0 ; i<m ; i++)
        {
            dp[n-1][i] = triangle[n-1][i];
        }

        for(int i=n-2 ; i>=0 ; i--)
        {
            for(int j=0 ; j<=i ; j++)
            {
                dp[i][j] = min(dp[i+1][j] , dp[i+1][j+1]) + triangle[i][j];
            }
        }
        return dp[0][0];
        
    }
};