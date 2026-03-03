class Solution {
public:
    string reverseString(string s)
    {
        int i=0,j=s.size()-1;

        while(i<j)
        {
            char temp = s[i];
            s[i++] = s[j];
            s[j--] = temp;
        }

        return s;
    }
    string invert (string s)
    {
        string temp = "";
        for( auto & i : s) if(i== '0') temp +='1'; else temp += '0';
        return temp;
    }
    char findKthBit(int n, int k) {
        string s="0";
        
        while(--n)
            s = s + '1' + reverseString(invert(s));


        return s[k-1];
    }
};