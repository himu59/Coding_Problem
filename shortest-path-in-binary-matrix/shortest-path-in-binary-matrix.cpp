class Solution {
public:
    int dx[8] = { -1, 0, 0, 1 ,1, -1,  1, -1};
    int dy[8] = { 0, -1, 1, 0 ,1, -1, -1,  1};
    bool isValid(int i,int j,int n,int m) {
        if(i<0 or j<0 or i>=n or j>=m) return 0;
        return 1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,int>> Q;
        Q.push({0,0});
        int n = grid.size();
        if(grid[0][0] == 1 or grid[n-1][n-1] == 1) return -1;
        if(n == 1) return 1;
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]) grid[i][j] = -1;
            }
        }
         
        while(!Q.empty()) {
            int curr_x = Q.front().first;
            int curr_y = Q.front().second;
            Q.pop();
            for(int i=0;i<8;i++) {
                int x = curr_x + dx[i];
                int y = curr_y + dy[i];
                if(isValid(x,y,n,n) and grid[x][y] == 0) {
                    grid[x][y] = grid[curr_x][curr_y] + 1;
                    Q.push({x,y});
                }
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cout<<grid[i][j]<<' ';
            }
            cout<<endl;
        }   
        if(grid[n-1][n-1] == 0) return -1;
        return grid[n-1][n-1]+1;
    }
};