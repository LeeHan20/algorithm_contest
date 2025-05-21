#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <stack>
#include "string"
#include "algorithm"
#include "cmath"
#include "unordered_map"
#include <string>
#include "unordered_set"
#include <set>
#define endl '\n'
#define space ' '
#define INF 2147483647
#define MAX 2501
using namespace std;
typedef long long ll;
//const long long INF = 1LL << 60;
//typedef __int128 ll;

int sero, garo;
vector<vector<int>> grid;
vector<vector<bool>> visited;
unordered_map<int, int> to_mask = {
    {0, 63}, {1, 7}, {2, 27}, {3, 15}, {4, 38}, {5, 45}, {6, 61}, {7, 7}, {8, 63}, {9, 47}
};
vector<vector<int>> transition = {
    {4, 5}, {1, 2}, {3}, {0}
};
vector<vector<int>> transition_togle = {
    {1, 2}, {5, 4}, {0}, {3}
};

bool is_on(unsigned int mask, unsigned int idx) {
    
    return (mask & (1u << idx)) != 0;
}

bool in_boundary(int y, int x) {
    
    return y >= 0 && y < sero && x >= 0 && x < garo;
}

void bfs() {
    int dy[4] = {0, 0, -1, 1};
    int dx[4] = {-1, 1, 0, 0};
    
    queue<pair<int, int>> q;
    
    q.push({0, 0});
    visited[0][0] = true;
    
    while (!q.empty()) {
        int y, x;
        tie(y, x) = q.front();
        q.pop();
        int mask = grid[y][x];
        
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (!in_boundary(ny, nx) || visited[ny][nx] == true) continue;
            int nmask = grid[ny][nx];
            
            for (int j = 0; j < (int)transition[i].size(); ++j) {
                int trans = transition[i][j];
                int togle = transition_togle[i][j];
                
//                cout << y << ' '  << x << " to " << ny << ' ' << nx << endl;
//                cout << trans << ' ' << mask << ' ' << togle << ' ' << nmask << endl;
                
                if (is_on(mask, trans) && is_on(nmask, togle)) {
                    q.push({ny, nx});
                    visited[ny][nx] = true;
                    break;
                }
            }
        }
    }
    
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> sero >> garo;
    grid.resize(sero, vector<int>(garo));
    visited.resize(sero, vector<bool>(garo));
    
    for (int i = 0; i < sero; ++i) {
        string line;
        cin >> line;
        
        for (int j = 0; j < garo; ++j) {
            grid[i][j] = to_mask[line[j] - '0'];
            
        }
    }
    
    bfs();
    
    for (int i = 0; i < sero; ++i) {
        for (int j = 0; j < garo; ++j) {
            if (visited[i][j] == true) continue;
            
            cout << "NO" << endl;
            return 0;
        }
    }
    
    cout << "YES" << endl;
    
    return 0;
}
