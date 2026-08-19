class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& r) 
    {
        int n1 = r.size();
        int m1 = r[0].size();
        map<int,vector<int>>mp;
        for(int i= 0; i<n1 ; i++)
        {
            mp[r[i][0]].push_back(r[i][1]);
        }

        int cnt = 0;

        
        for(auto i:mp)
        {
            auto lst = i.second;

            vector<int>temp(11,0);

            for(auto j:lst)
            {
                temp[j]= 1;
            }
            int flag = 3;
            for(int j = 2 ; j<=5 ; j++)
            {
                if(temp[j] == 0)
                {
                    temp[j] = 1;
                }
                else{
                    flag--;
                    break;
                }
            }

            for(int j = 4 ; j<=7 ; j++)
            {
                if(temp[j] == 0)
                {
                    temp[j] = 1;
                }
                else{
                    flag--;
                    break;
                }
            }


            for(int j = 6 ; j<=9 ; j++)
            {
                if(temp[j] == 0)
                {
                    temp[j] = 1;
                }
                else{
                    flag--;
                    break;
                }
            }

            cnt+=flag;

        }

        int no = n - mp.size();
        return cnt + no * 2;
    }
};