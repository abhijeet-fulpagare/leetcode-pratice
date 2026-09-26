class Solution {
public:
    string evaluate(string s, vector<vector<string>>& k) 
    {
        map<string,string>mp;

        for(auto i:k)
        {
            mp[i[0]] =i[1];
        }

        
        int n = s.size();

        string ans="";
        for(int i=0 ; i<n ; i++)
        {
            if(s[i] != '(')
            {
                ans+=s[i];
            }
            else{
                string temp;
                int st = i+1;
                temp+=s[st];

                while(st+1<n && s[st+1] != ')')
                {
                    st++;
                    temp+=s[st];
                }

                
                if(mp.count(temp))
                {
                    string l = mp[temp];
                    ans+=l;                    
                }
                else{
                    ans+='?';
                }

                i = st+1;
            }
        }
        return ans;
    }
};