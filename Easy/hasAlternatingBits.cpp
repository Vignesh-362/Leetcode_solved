class Solution {
public:
    bool hasAlternatingBits(int n) {
        int x,r;
        string s;
        while(n>0)
        {
           r=n%2;
           n/=2;
           s+=r+'0';
        }
        if(s.size()==1)
        return 1;
        for(int i=0;i<s.size()-1;i++)
        {
            if(s[i]==s[i+1])
            return 0;
        }
        return 1;
    }
};
