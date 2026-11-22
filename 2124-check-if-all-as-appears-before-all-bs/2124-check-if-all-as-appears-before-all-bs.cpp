class Solution {
public:
    bool checkString(string s) {
        
        int ck = 0;
        bool ans = 1;
        int n = s.size();
        for(int i=0 ; i<n ; i++)
        {
            if(s[i] == 'b')
            {
                ck =1;
            }
            else if(s[i] == 'a' && ck)
            {
                ans = 0;
                break;
            }
        }
        return ans;
    }
};