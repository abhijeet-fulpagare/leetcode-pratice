class Solution {
public:
    int reverseDegree(string s) 
    {
        int n = s.size();
        int ans = 0;
        for(int i=0 ; i<n ; i++)
        {
            int k = s[i]-'a';

            int y = 26 - k;

            ans+= (y * (i+1));

        }

        return ans;
        
    }
};