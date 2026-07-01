class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        int cnt1=0,cnt2=0,cnt3=0;

        int n=s.size();

        int ans=0;
        int st=0;
        for(int i=0 ; i<n ; i++)
        {
            if(s[i] == 'a')
            cnt1++;
            else if(s[i] == 'b')
            cnt2++;
            else if(s[i] == 'c')
            cnt3++;

            while (cnt1 > 0 && cnt2 > 0 && cnt3 > 0) {

                ans += (s.size() - i);

                if (s[st] == 'a') cnt1--;
                else if (s[st] == 'b') cnt2--;
                else cnt3--;

                st++;
            }
        }

        return ans;

    }

};