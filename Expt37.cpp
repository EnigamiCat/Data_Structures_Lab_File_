#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int rottenOranges(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int minutes = 0;
    
     
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    
    queue<pair<int, int>> rottenQueue;

  
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 2) {
                rottenQueue.push({i, j});
            }
        }
    }

     
    while (!rottenQueue.empty()) {
        int size = rottenQueue.size();
        bool changed = false;

        for (int i = 0; i < size; ++i) {
            int x = rottenQueue.front().first;
            int y = rottenQueue.front().second;
            rottenQueue.pop();

            for (int k = 0; k < 4; ++k) {
                int newX = x + dx[k];
                int newY = y + dy[k];

                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == 1) {
                    grid[newX][newY] = 2;
                    rottenQueue.push({newX, newY});
                    changed = true;
                }
            }
        }

        if (changed) {
            minutes++;
        }
    }

   
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 1) {
                return -1; 
            }
        }
    }

    return minutes;
}

int main() {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };
    
    int minutes = rottenOranges(grid);
    if (minutes == -1) {
        cout << "It is not possible to rot all oranges." << endl;
    } else {
        cout << "Minimum time to rot all oranges: " << minutes << " minutes." << endl;
    }
    
    return 0;
}
