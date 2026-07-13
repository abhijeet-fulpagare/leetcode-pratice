class Solution {
public:
    vector<int> sequentialDigits(int low, int high) 
    {
        vector<int>ans;

        int dig_cnt = 0;
        int no = low;

        while(no != 0)
        {
            int dig = no%10;
            dig_cnt++;
            no = no/10;
        }

        int st=1;
        int end =dig_cnt;

        while(1){

            int flag= 0;
            
            int number=0;
            for(int i=st ; i<=end ; i++)
            {
                number = number*10+i;
            }

            if((number >= low) && (number <= high))
            {
                ans.push_back(number);
            }
            else if((number > high) ||( dig_cnt >= 10 ))
            {
                flag=1;
                break;
            }

            st++;

            if(end == 9)
            {
                dig_cnt++;
                st=1;
                end=dig_cnt;
            }
            else{
                end++;
            }

            if(flag)
            break;
        }

        return ans;
        
    }
};