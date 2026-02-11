class Solution {
public:
    string convert(string s, int n) {
        vector<string>ans(s.size());
        int m=0;
        for(int i=0;i<s.size();i++)
        {
            if( ((i-m) % n )== n-1)
            {
                ans[(i-m) % n] += s[i];
                int k= n-2;
                while(i+1<s.size() && k >= 1)
                {
                    i++; m++;
                    ans[k--] += s[i];
                }
            }
            else
            ans[(i-m)% n] += s[i];

        }

        string res;

        for(int i=0;i<s.size();i++) res+= ans[i];
        return res;
    }
};