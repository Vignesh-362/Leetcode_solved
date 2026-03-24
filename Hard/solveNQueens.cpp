class Solution {
public:
    bool isvalid(vector<string> &queen, int r, int c)
{
    int row = r, col = c;

    // upper-left diagonal
    while(row >= 0 && col >= 0) {
        if(queen[row][col] == 'Q') return false;
        row--; col--;
    }

    row = r; col = c;

    // same column (upwards)
    while(row >= 0) {
        if(queen[row][col] == 'Q') return false;
        row--;
    }

    row = r; col = c;

    // upper-right diagonal
    while(row >= 0 && col < queen.size()) {
        if(queen[row][col] == 'Q') return false;
        row--; col++;
    }

    return true;
}
    void solve(vector<string> & queen,vector<vector<string>> & ans,int row,int n)
    {
        if(row == n) 
        {
            ans.push_back(queen);
            return;
        } 
             for(int j=0;j<n;j++)
             {
                if(isvalid(queen,row,j))
                {
                    queen[row][j] = 'Q';
                    solve(queen,ans,row + 1,n);
                    queen[row][j] = '.';
                }
             }
         
    }
    vector<vector<string>> solveNQueens(int n) {

        string s="";
        for(int i=0;i<n;i++) s+='.';
        vector<string>queen;
        vector<vector<string>>ans;
        for(int i=0;i<n;i++)queen.push_back(s);


        solve(queen,ans,0,n);
        return ans;
    }
};