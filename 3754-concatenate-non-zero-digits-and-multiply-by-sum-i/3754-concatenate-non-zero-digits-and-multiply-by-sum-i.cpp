class Solution {
public:
    long long sumAndMultiply(int n) 
    {
        int no=n;
        long long ans=0;
        long long sum=0;

        vector<int>t;
        while(no != 0)
        {
            int dig=no%10;
            no=no/10;

            if(dig == 0)
            continue;

            t.push_back(dig);
            sum+=dig;


        }

        int n1=t.size();

        for(int i=n1-1 ; i>=0 ; i--)
        {
            ans=ans*10+t[i];

        }


        return ans*sum;
        
    }
};