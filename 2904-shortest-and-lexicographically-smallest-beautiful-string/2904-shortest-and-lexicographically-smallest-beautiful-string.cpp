struct cmp{
    bool operator()(const string & s1 , const string &s2)
    {
        if(s1.size() != s2.size())
            return s1.size() < s2.size();
            
        return s1 < s2;
    }
};

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) 
    {
        vector<string>t;

        int n = s.size();
        int l = 0;

        int os = 0;
        for(int i= 0 ; i<n ; i++)
        {
            if(s[i] == '1')
            {
                os++;
            }

            
            while(os == k && l<=i)
            {
                string temp = string(s.begin()+l,s.begin()+i+1);
                t.push_back(temp);
                if(s[l] == '1')
                {
                    os--;
                }
                l++;
            }
            

        }

        if(t.size() >= 1)
        sort(t.begin(),t.end(),cmp());
        else{
            return "";
        }

        return t[0];
        

    }
};