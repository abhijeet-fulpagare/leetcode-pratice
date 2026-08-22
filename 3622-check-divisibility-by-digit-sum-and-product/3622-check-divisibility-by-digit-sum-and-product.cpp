class Solution {
public:
    bool checkDivisibility(int n) 
    {
        int  no = n;
        int sum = 0;
        int prod = -1;
        while(no != 0)
        {
            int dig = no % 10;
            sum += dig;

            if(prod == -1)
            {
                prod = dig;
            }
            else{
                prod *= dig;
            }
            
            no = no / 10;
        }

        
        if(prod != -1)
        return (n % (sum+prod)) == 0;

        return n % sum == 0;
    }
};