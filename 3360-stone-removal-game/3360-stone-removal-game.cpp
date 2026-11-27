class Solution {
public:
    bool canAliceWin(int n) 
    {
        for(int i=10 ; i>=1 ; i--)
        {
            if(n-i < 0)
            {
                return (i%2 != 0);
            }

            n = n - i;
        }
        return 0;
    }
};