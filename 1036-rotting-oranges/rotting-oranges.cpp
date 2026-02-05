class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty())
        return 0;
        int m = grid.size();
        int n = grid[0].size();
        int time = 0;
        int totalOranges = 0;
        int rottenCount = 0;
        queue<pair<int, int>> q;
        for(int i =0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]!=0){
                    totalOranges++;
                }
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        while(!q.empty()){
            int size = q.size();
            rottenCount += size;
            while (size--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i= 0; i<4; i++){
                    int newX = x+dx[i];
                    int newY = y+dy[i];
                    if(newX < 0 || newY < 0 || newX >= m || newY >=n || grid[newX][newY] != 1){
                        continue;

                    }
                    grid[newX][newY] =2;
                    q.push({newX, newY});
                }
            }
            if(!q.empty()){
                time++;
            }
        }
        return totalOranges == rottenCount ? time : -1;
    }
};