class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int m=grid.size() ,n=grid[0].size();
        int onec=0;

        for(int i=0;i<m;i++)
         for(int j=0;j<n;j++)
           if(grid[i][j] == 1) onec++;
           else if(grid[i][j] == 2) q.push({i,j});

        int ans =0; 

        while(!q.empty())
        {
            int size = q.size();
            int dx[] = {1,-1,0,0};
            int dy[] = {0,0,1,-1};
            while(size--)
            {
                int x = q.front().first;
                int y= q.front().second;
                q.pop();

                for(int d=0;d<4;d++)
                {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny] ==1)
                    {
                        grid[nx][ny] = 2;
                        q.push({nx,ny});
                        onec--;
                    }
                }
            }
            ans++;  
        } 
        if(onec > 0 ) return -1;
        return ans>0 ? ans-1 :ans;  
    }
};