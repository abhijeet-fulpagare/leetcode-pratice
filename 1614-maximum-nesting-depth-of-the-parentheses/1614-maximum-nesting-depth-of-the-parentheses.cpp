class Solution {
public:
    int maxDepth(string s) {
        int ans=0;

        int n=s.size();
        int temp=0;

        for(int i=0 ; i<n ; i++)
        {
            if(s[i] == '(')
            temp++;
            else if( s[i] == ')')
            {
                ans=max(ans,temp);
                temp--;
            }
        }
        return max(ans,temp);
    }
};