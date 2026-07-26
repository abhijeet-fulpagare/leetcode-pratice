class Solution {
public:
    int lcs(int n1,int n2,string word1, string word2,vector<vector<int>>&dp)
    {
        if(n1 == 0 || n2 == 0)
        {
            return 0;
        }

        if(dp[n1][n2] != -1)
        return dp[n1][n2];


        if(word1[n1-1] == word2[n2-1])
        {
            return dp[n1][n2] = 1+lcs(n1-1,n2-1,word1,word2,dp);
        }

        return dp[n1][n2] = max(lcs(n1-1,n2,word1,word2,dp),lcs(n1,n2-1,word1,word2,dp));


    }
    int minDistance(string word1, string word2) 
    {
        int n1=word1.size();
        int n2 = word2.size();

        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));

        int maximumlcs = lcs(n1,n2,word1,word2,dp);

        int replace =  min(n1,n2)-maximumlcs;

        int add=abs(n1-n2);


        return add+replace*2;
    }
};