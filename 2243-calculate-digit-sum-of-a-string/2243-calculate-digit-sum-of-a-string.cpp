class Solution {
public:
    string digitSum(string s, int k) 
    {
        string temp = s;

        while(temp.size() > k)
        {
            int n = temp.size();
            int no = 0;
            string s1;
            for(int i=0 ; i<n ; i++)
            {
                no+=temp[i]-'0';
                if(((i+1) % k) == 0)
                {
                    s1 += to_string(no);
                    no = 0;
                }
            }

            if((n % k) != 0)
            {
                s1 += to_string(no);
                no = 0;
            }

            temp = s1;
        }
        
        return temp;
    }
};