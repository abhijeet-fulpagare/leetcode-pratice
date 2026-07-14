class Solution {
public:

    int mod = 1e9+7;

    int f(int idx, int gcd1,int gcd2 ,vector<int>& nums,vector<vector<vector<int>>>&dp)
    {
        if(idx < 0 )
        {
            if(gcd1 == 0 && gcd2 == 0)
            return 0;


            if(gcd1 == gcd2)
            return 1;

            return 0;
        }

        if(dp[idx][gcd1][gcd2] != -1)
        return dp[idx][gcd1][gcd2];


        int pick1 = f(idx-1,__gcd(gcd1,nums[idx]),gcd2,nums,dp)%mod;
        int pick2= f(idx-1,gcd1,__gcd(nums[idx],gcd2),nums,dp)%mod;


        int nopick = f(idx-1,gcd1,gcd2,nums,dp)%mod;

        return dp[idx][gcd1][gcd2] = (((pick1+pick2)%mod) + nopick)%mod;
    }
    int subsequencePairCount(vector<int>& nums) 
    {
        int n= nums.size();

        vector<vector<vector<int>>>dp(n,vector<vector<int>>(201,vector<int>(201,-1)));

        return f(n-1,0,0,nums,dp);
        
        
    }
};