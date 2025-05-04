#include <iostream>
#include <vector>

using namespace std;

int main()
{
    bool printed = false;
    int i, j, m = 4, n = 5;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n, 0));
    //vector<vector<int>> matrix = {{1,2,0,3,5},{0,0,0,0,0},{4,5,0,6,9},{7,8,0,9,1}};

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (matrix[i][j] != 0) {
                break;
            }
        }
        if (j == n) {
            for (j = 0; j < n; j++) {
                matrix[i][j] = -1;
            }
        }
    }

    for (j = 0; j < n; j++) {
        for (i = 0; i < m; i++) {
            if (matrix[i][j] != 0 && matrix[i][j] != -1) {
                break;
            }
        }
        if (i == m) {
            for (i = 0; i < m; i++) {
                matrix[i][j] = -1;
            }
        }
    }

    for (i = 0; i < m; i++) {
        printed = false;
        for (j = 0; j < n; j++) {
            if (matrix[i][j] == -1) {
                continue;
            }
            cout << matrix[i][j];
            if (j != n) {
                cout << " ";
            }
            printed = true;
        }
        printed ? cout << endl : cout << "";
    }

    return 0;
}