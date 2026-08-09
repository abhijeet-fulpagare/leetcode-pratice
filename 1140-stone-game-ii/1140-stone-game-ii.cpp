class Solution {
public:


    pair<int,int> findScore(int idx,int m,vector<int>& p,int turn,vector<vector<vector<pair<int,int>>>>&dp)
    {
        int n = p.size();
        if(idx >= n)
        {
            return {0,0};
        }

        if(dp[idx][m][turn].first != -1)
        {
            return dp[idx][m][turn];
        }

        int range = 2 * m;
        int other = 0;
        int ans = 0;

        int pickEle = 0;
        int pick = 0;
        if(turn == 0)
        {
            for(int i=idx ; i<n && i<idx+range ; i++)
            {
                pickEle+=p[i];
                pick++;

                pair<int,int> temp = findScore(i+1,max(pick,m),p,1,dp);

                int a = temp.first;
                int b = temp.second;

                if(a + pickEle > ans)
                {
                    ans = a + pickEle;
                    other = b;
                }
            }

            return dp[idx][m][turn] = {ans,other};
        }


        for(int i=idx ; i<n && i<idx+range ; i++)
        {
            pickEle+=p[i];
            pick++;

            pair<int,int> temp = findScore(i+1,max(pick,m),p,0,dp);

            int a = temp.first;
            int b = temp.second;

            if(b + pickEle > ans)
            {
                ans = b + pickEle;
                other = a;
            }

        }
        return dp[idx][m][turn] = {other,ans};


    }
    int stoneGameII(vector<int>& piles) 
    {
        int n = piles.size();
        vector<vector<vector<pair<int,int>>>>dp(n,vector<vector<pair<int,int>>>
        (2*n+1,vector<pair<int,int>>(2,{-1,-1})));
        pair<int,int> p = findScore(0,1,piles,0,dp);
        
        return p.first;
    }
};