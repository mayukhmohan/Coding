#include <iostream>
#include <vector>

using namespace std;

static bool isValidStep(int i, int j, int R, int C, vector<vector<bool>> visited, vector<vector<char>> maze)
{
    if (i >= 0 && j >= 0 && i < R && j < C) {
        if (!visited[i][j] && (maze[i][j] == '1' || maze[i][j] == '@')) {
            return true;
        }
    }

    return false;
}

static bool DFS(vector<vector<char>> maze, vector<vector<bool>> &visited, pair<int, int> index, 
                pair<int, int> dest, int count, int &result)
{
    int i = index.first, j = index.second, R = maze.size(), C = maze[0].size();
    int n_dir = 4;
    vector<int> row_dir = {-1, 1, 0, 0};
    vector<int> col_dir = {0, 0, -1, 1};
    visited[i][j] = true;
    count++;

    if (i == dest.first && j == dest.second) {
        result = count;
        return true;
    }

    for (int index = 0; index < n_dir; index++) {
        if (isValidStep(i+row_dir[index], j+col_dir[index], R, C, visited, maze)) {
            if (DFS(maze, visited, make_pair(i+row_dir[index], j+col_dir[index]), dest, count, result)) {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    pair<int, int> src, dest;
    int i, j, r = 3, c = 3;
    cin >> r >> c;

    vector<vector<char>> maze(r, vector<char>(c, '0'));
    //vector<vector<char>> maze = {{'@', '1', '1'},{'0', '0', '1'},{'#', '1', '1'}};
    //src = make_pair(2,0);
    //dest = make_pair(0,0);

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == '#') {
                src = make_pair(i,j);
            } else if (maze[i][j] == '@') {
                dest = make_pair(i,j);
            }
        }
    }
    int result = -1, count = -1;
    vector<vector<bool>> visited(r, vector<bool>(c, false));
    (void)DFS(maze, visited, src, dest, count, result);
    cout << result << endl;
}