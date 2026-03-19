class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int cnt=0;
        int m=grid.size(),n=grid[0].size();

        vector<vector<int>> x(m,vector<int>(n,0));
        vector<vector<int>> y(m,vector<int>(n,0));
        
        if(grid[0][0] == 'X')  x[0][0]++;
        else if(grid[0][0]== 'Y')  y[0][0]++;

        for(int j=1;j<n;j++)
        {
          if(grid[0][j] == 'X')  x[0][j]++;
          else if(grid[0][j]== 'Y')  y[0][j]++;
            
          x[0][j] += x[0][j-1];
          y[0][j] += y[0][j-1];
               
        }

        for(int j=1;j<m;j++)
        {
          if(grid[j][0] == 'X')  x[j][0]++;
          else if(grid[j][0]== 'Y')  y[j][0]++;
            
          x[j][0] += x[j-1][0];
          y[j][0] += y[j-1][0];
               
        }

        for(int j=1;j<n;j++)
            if(x[0][j] >0 && x[0][j] == y[0][j]) cnt++;

        for(int j=1;j<m;j++)
            if(x[j][0] >0 && x[j][0] == y[j][0]) cnt++;    

        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(grid[i][j] == 'X')  x[i][j]++;
                else if(grid[i][j]== 'Y')  y[i][j]++;
            
                  x[i][j] += x[i-1][j] + x[i][j-1] - x[i-1][j-1];
                  y[i][j] += y[i-1][j] + y[i][j-1] - y[i-1][j-1];
            }
        }

        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
                 if(x[i][j] >0 && x[i][j] == y[i][j]) cnt++;
                     
         return cnt;
    }
};