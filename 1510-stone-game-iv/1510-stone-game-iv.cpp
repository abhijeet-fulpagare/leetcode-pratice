class Solution {
public:

    bool finds(int n,vector<int>&squares,int turn,vector<vector<int>>&dp)
    {
        if(n <= 0)
        {
            if(turn == 1)
            return 1;

            return 0;
        }

        if(dp[n][turn] != -1)
        return dp[n][turn];
        
        if(turn == 0)
        {
            bool ans =0;
            for(auto i:squares)
            {
                bool t =0;

                if(n-i >= 0)
                    t = finds(n-i,squares,1,dp);

                ans = max(ans , t);
            }

            return dp[n][turn] =ans;
        }
        else{

            bool ans =1;
            for(auto i:squares)
            {
                bool t =1;

                if(n-i >= 0)
                    t = finds(n-i,squares,0,dp);

                ans = min(ans , t);
            }

            return dp[n][turn] = ans;
        }

        return 0;
    }
    bool winnerSquareGame(int n) {
        
        vector<vector<int>>dp(n+1,vector<int>(2,0));

        vector<int>squares;

        for(int i=1 ;i*i <=n ;i++)
        {
            squares.push_back(i*i);
        }

        //return finds(n,squares,0,dp);


        dp[0][0]  = 0;
        dp[0][1] = 1;

        for(int i=1 ; i<=n ; i++)
        {
            for(int turn = 1 ; turn>=0 ; turn--)
            {
                if(turn == 0)
                {
                    bool ans =0;
                    for(auto j:squares)
                    {
                        bool t =0;

                        if(i-j >= 0)
                            t = dp[i-j][1];

                        ans = max(ans , t);
                    }

                    dp[i][turn] =ans;
                }
                else{

                    bool ans =1;
                    for(auto j:squares)
                    {
                        bool t =1;

                        if(i-j >= 0)
                            t = dp[i-j][0];

                        ans = min(ans , t);
                    }

                    dp[i][turn] = ans;
                }
            }
        }

        return dp[n][0];
    }
};