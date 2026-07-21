class Solution {
public:

    int cnt(string s)
    {
        int n=s.size();
        int ans=0;
        for(int i=0 ; i<n ; i++)
        {   
            if(s[i] == '1')
            ans++;

        }

        return ans;
    }
    int maxActiveSectionsAfterTrade(string s) {

        int n = s.size();

        int last = -1;  
        vector<pair<int,int>> v;

        for (int i = 0; i < n; i++) {

            if (last != -1) {

                if (s[last] == s[i])
                    continue;

                else if (s[last] == '1' && s[i] == '0') {
                    last = i;
                }

                else if (s[last] == '0' && s[i] == '1') {

                    while (i < n && s[i] == '1')
                        i++;

                    int temp = i;

                    while(temp+1 < n && s[temp+1] == '0')
                    temp++;

                    if (temp < n && s[temp] == '0') {
                        v.push_back({last, temp});
                    }
                    last = i;
                    
                }
            }

            if (last == -1) {
                last = i;
            }
        }

    
        int n1 = v.size();

       
        

        
        int cnt_zero=0;
        int st=-1;
        int en=-1;
        for(auto i:v)
        {
            int t=0;
            for(int j = i.first ; j<=i.second ; j++)
            {
                if(s[j] == '0')
                {
                    t++;
                }
            }

            if(t > cnt_zero)
            {
                cnt_zero=t;
                en=i.second;
                st =i.first;
            }
        }

        if(st != -1)
        {
            for(int i=st ; i<=en ; i++)
            {
                s[i]='1';
            }
        }
        

       return cnt(s);

        
        

        
    }
};