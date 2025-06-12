#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int n, m, k;
vector<vector<int>> grid;
vector<bool> out(5002, true);
vector<bool> visited;

int cnt = 0;

void bfs() {
    
    queue<int> q;
    q.push(1);
    visited[1] = true;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cnt++;
        
//        cout << node << endl;
        
        for (int next : grid[node]) {
            if (out[next] == false || visited[next] == true) continue;
            
            visited[next] = true;
            q.push(next);
        }
    }
    
    return;
}


int main() {
    
    cin >> n >> m >> k;
    grid.resize(5002);
    visited.resize(5002);
    
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        grid[a].push_back(b);
        grid[b].push_back(a);
    }
    
    for (int i = 0; i < k; ++i) {
        int a;
        cin >> a;
        out[a] = false;
    }
    
    bfs();
    
    cout << cnt - 1 << endl;
    
    return 0;
}
