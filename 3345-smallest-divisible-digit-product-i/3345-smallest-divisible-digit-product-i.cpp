class Solution {
public:

    int getp(int n)
    {  
        int no = n ;

        int prod =1;

        while(no != 0)
        {
            int dig = no % 10;
            no = no/10;
            prod*=dig;
        }

        return prod;

    }
    int smallestNumber(int n, int t) 
    {
        
        int no = n;

        while( (getp(no) % t) != 0)
        {
            no++;
        }

        return no;
        
    }
};