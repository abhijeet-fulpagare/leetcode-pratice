class Solution {
public:

    //all possiblities

    // void f(int num, int sum,int i,int curr,string &temp,string &ans,long long sq_val,long long &sq_ans)
    // {
    //     if (curr == sum && i == num)
    //     {
    //         if (sq_val > sq_ans || (sq_val == sq_ans && temp > ans))
    //         {
    //             ans = temp;
    //             sq_ans = sq_val;
    //         }
    //         return;
    //     }

    //     if(curr > sum || i >= num)
    //     {
    //         return;
    //     }
        
    //     for(int j=0 ; j<=9 ; j++)
    //     {
    //         if(j==0 && curr == 0)
    //         continue;

    //         if (curr + j > sum)
    //         continue;

    //         temp+='0'+j;
    //         f(num,sum,i+1,curr+j,temp,ans,(sq_val + (j * 1ll) * j),sq_ans);
    //         temp.pop_back();
    //     }

    //     return;
    // }
    string maxSumOfSquares(int num, int sum) 
    {
        /*string ans = "";
        string temp = "";
        long long sq_ans = -1;

        f(num, sum, 0, 0, temp, ans, 0LL, sq_ans);

        return ans;*/

        if (sum < 1 || sum > 9 * num)
            return "";

        string ans = "";

        for (int i = 0; i < num; i++) {
            int remaining = num - i - 1;

            for (int d = 9; d >= 0; d--) {
                if (sum - d >= 0 &&
                    sum - d <= remaining * 9) {
                    ans += char('0' + d);
                    sum -= d;
                    break;
                }
            }
        }

        return ans;



    }
};