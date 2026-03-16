class Solution {
public:
   void helper(vector<vector<int>>& grid,int m,int n,int i,int j,priority_queue<int> & pq)
   {
       int k=1;
       while(i- k >=0 && i+k < m &&  j + k * 2 < n)
       {
           int row =j + k * 2;
           int sum =grid[i][j] + grid[i][row];
           for(int l = 1; l<k;l++ )
           {
               sum += grid[i + l][j+l];
               sum += grid[i - l][j+l];
               sum += grid[i + l][row - l];
               sum += grid[i - l][row - l];
           }
           sum += grid[i + k][j+k];
           sum += grid[i - k][j+k];
           pq.push(sum);
           k++;

       }
   }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        priority_queue<int>pq;
        
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                pq.push(grid[i][j]);
                helper(grid,m,n,i,j,pq);
            }
        }
        vector<int> ans;
        int cnt =1;
        if(pq.size()==1)
                {
                   ans.push_back(pq.top());
                   pq.pop();
                }   
        while(pq.size() && cnt <=3)
        {
            int temp = pq.top(); pq.pop();
            if(pq.size() && temp == pq.top()) 
            {
                if(pq.size()==1)
                {
                   ans.push_back(pq.top());
                   pq.pop();
                }   
                continue;
            }
            ans.push_back(temp);
            cnt++;
        }
        return ans;
    }
};