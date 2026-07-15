class Solution {
public:

    int gcd(int a , int b)
    {
        if(a == 0)
        return b;

        if(b == 0)
        return a;

        if(a == b)
        return a;

        if(a>b)
        {
            return gcd(a-b,b);
        }

        return gcd(a,b-a);
    }
    int gcdOfOddEvenSums(int n) 
    {
        n=n*2;

        int cnt1=0,cnt2=0;
        for(int i=1 ; i<=n ; i++)
        {
            if(i % 2 == 0)
            {
                cnt1++;
            }
            else{
                cnt2++;
            }
        }
        return gcd(cnt1,cnt2);
    }
};