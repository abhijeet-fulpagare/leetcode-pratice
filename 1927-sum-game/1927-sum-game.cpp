class Solution {
public:
    bool sumGame(string num) {
        
        int n = num.size();

        int s1 = 0 , s2 = 0;
        int q1 = 0 , q2 = 0;

        for(int i=0 ; i<n/2 ; i++)
        {
            if(num[i] != '?')
            s1 = s1 + (num[i] - '0');
            else
            q1++;
        }

        for(int i=n/2 ; i<n ; i++)
        {
            if(num[i] != '?')
            s2 = s2 + (num[i] - '0');
            else
            q2++;
        }

      

        return 2 * (s1 - s2) != 9 * (q2 - q1);

    }
};