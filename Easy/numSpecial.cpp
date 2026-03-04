class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
       int m= mat.size(),n=mat[0].size();
       vector<int> row(m,0) ,col(n,0);

       for(int i=0;i<m;i++)
         for(int j=0;j<n;j++) row[i] += mat[i][j];

        for(int j=0;j<n;j++)
          for(int i=0;i<m;i++)
            col[j] += mat[i][j];

        int c=0;

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
               if(mat[i][j] ==1 && row[i]==1 && col[j] ==1) c++;

        return c;       
           
    }
};