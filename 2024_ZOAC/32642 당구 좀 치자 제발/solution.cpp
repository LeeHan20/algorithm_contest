#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <utility>
#include <random>
using namespace std;

typedef long long ll;

//vector<bool> is_visited;
//vector<pair<pair<int, int>, pair<int, int>>> teleport;
//int goal_x, goal_y;
//bool arrive_falg;
//
//int dx[] = {-1, 1, 0, 0};
//int dy[] = {0, 0, -1, 1};
//
//void dfs(vector<vector<int>> map, int x, int y, int m, int n, int power) {
//    if (arrive_falg) {
//        return;
//    }
////    cout << "power is now " << power << endl;
////    cout << "is working at " << x << " " << y << endl;
//    
//    if (x == goal_x && y == goal_y) {
//        arrive_falg = true;
//        return;
//    }
//
//    is_visited[m * n] = true;
//
//    for (int i = 0; i < 4; ++i) {
//        int newX = x + dx[i];
//        int newY = y + dy[i];
//        if (newX >= 1 && newX < n && newY >= 1 && newY < m) {
//            if (power >= map[newX][newY] && !is_visited[newX * newY]) {
//                dfs(map, newX, newY, m, n, power - map[newX][newY]);
//            }
//        }
//    }
//    
//    for (int i = 0; i < teleport.size(); ++i) {
//        if (teleport[i].first.first == x && teleport[i].first.second == y) {
//            if (!is_visited[teleport[i].second.first * teleport[i].second.second]) {
//                dfs(map, teleport[i].second.first, teleport[i].second.second, m, n, power);
//            }
//        }
//    }
//}
//
//void clear_visit(int n, int m) {
//    
//    is_visited.clear();
//    
//    for (int i = 0; i < n * m; ++i) {
//        is_visited.push_back(false);
//    }
//    
//    return;
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    
//    int n, m, k, t, q;
//    cin >> n >> m >> k >> t >> q;
//    
//    //map 설정
//    vector<vector<int>> map(n + 1);
//    for (int i = 1; i < n + 1; ++i) {
//        for (int j = 1; j < m + 1; ++j) {
//            int a;
//            cin >> a;
//            map[i].push_back(a);
//        }
//    }
//    
//    //텔레포트 설정
//    teleport.resize(k);
//    for (int i = 0; i < k; ++i) {
//        cin >> teleport[i].first.first >> teleport[i].first.second >> teleport[i].second.first >> teleport[i].second.second;
//    }
//    
//    //q만큼 시뮬레이션 시작
//    while (true) {
//        if (q == 0) {
//            break;
//        }
//        
//        arrive_falg = false;
//        clear_visit(n + 1, m + 1);
//        
//        int power;
//        cin >> power >> goal_x >> goal_y;
//        
//        dfs(map, 1, 1, m, n, power);
//        
//        if (arrive_falg) {
//            cout << 1 << "\n";
//        }
//        else {
//            cout << 0 << "\n";
//        }
//        
//        q--;
//    }
//    
//    return 0;
//}

int main() {
    
    int n;
    cin >> n;
    
    ll rageness = 0;
    ll cnt = 0;
    
    for (int i = 0; i < n; ++i) {
        int narssi;
        cin >> narssi;
        
        if (narssi) {
            rageness++;
        }
        else {
            rageness--;
        }
        
        cnt += rageness;
    }
    
    cout << cnt << endl;
    
    return 0;
}
