class Solution {
public:
    int longestBalanced(string s) {
       int freq[26] = {0};
       int max1 = 1;

       for(int i=0;i<s.size();i++)
       {
          
          for(int j=i;j<s.size();j++)
          {
             int temp = ++freq[s[j]-'a'];
             bool check = true;
             for(int k=0;k<26;k++)
             {
                 if(freq[k] != temp && freq[k] != 0) check = false;
             }

             if(check) max1 = max(max1,j-i+1);
          }
          for(int i=0;i<26;i++) freq[i]=0;       
       }
       return max1; 
    }
};