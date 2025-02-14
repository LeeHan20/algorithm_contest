#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <string>
#define endl '\n'
#define inf 2147483647
using namespace std;
typedef long long ll;

int sero, garo, k, t, q;
// k는 순간이동 지점의 수, t는 텔레포트 가능 횟수, q는 쿼리
vector<vector<int>> field;
vector<vector<pair<int, int>>> tele;
// 텔포 지점을 저장하는 방식에서 두 가지를 고려해볼 수 있는데
// 하나는 위의 방법처럼 2차원 배열에 쌍을 저장하는 것이고
// 두 번째는 2차원 배열을 1차원으로 펴서 번호를 지정하는 것
// 메모리 초과가 날 일은 어차피 많아봐야 20000이라 없을 듯
vector<vector<vector<int>>> dist;

bool in_boundary(int y, int x) {
    return (y >= 0 && y < sero && x >= 0 && x < garo);
}

void dijkstra() {
    int dy[4] = {0, 0, -1, 1};
    int dx[4] = {-1, 1, 0, 0};
    
    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> pq;
    
    dist[0][0][t] = 0;
    pq.push({0, 0, 0, t});
    
    while (!pq.empty()) {
        int current_distance, y, x, remain;
        tie(current_distance, y, x, remain) = pq.top();
        pq.pop();
        
        if (current_distance != dist[y][x][remain]) continue;
        
        if (tele[y][x].first != -1 && remain > 0) {
            int ny = tele[y][x].first;
            int nx = tele[y][x].second;
            int ndistance = current_distance;
            
            // 만약 '텔레포트를 사용하지 않고' (즉, remain을 그대로 보존한 상태) 이 좌표로 도달한 비용보다
            // 텔레포트를 써서 도달하는 비용(ndistance)이 낮아야(즉, 더 유리할 때만) 텔레포트 사용.
            if (ndistance < dist[ny][nx][remain] && // 같은 좌표에 remain 그대로 도달한 비용과 비교
                ndistance < dist[ny][nx][remain - 1]) { // 그리고 텔레포트를 소모한 상태에서도 개선될 때
                
//                cout << "teleport! : " << y << x << ny << nx << ' ' << ndistance << endl;
                
                dist[ny][nx][remain - 1] = ndistance;
                pq.push({ndistance, ny, nx, remain - 1});
            }
        }
        
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (!in_boundary(ny, nx)) continue;
            int ndistance = current_distance + field[ny][nx];
            if (ndistance >= dist[ny][nx][remain]) continue;
            
            dist[ny][nx][remain] = ndistance;
            pq.push({ndistance, ny, nx, remain});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> sero >> garo >> k >> t >> q;
    
    field.resize(sero, vector<int>(garo));
    tele.resize(sero, vector<pair<int, int>>(garo, {-1, -1}));
    dist.resize(sero, vector<vector<int>>(garo, vector<int>(t + 1, inf)));
    
    for (int i = 0; i < sero; ++i) {
        for (int j = 0; j < garo; ++j) {
            cin >> field[i][j];
        }
    }
    
    for (int i = 0; i < k; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        // a, b to c, d
        
        tele[a - 1][b - 1] = {c - 1, d - 1};
        // 단방향 텔레포트임
        // 0-base index로 사용함
    }
    
    dijkstra();
    // 다익스트라가 실행되고 나면 dist 2차원 배열에 모든 노드까지의 최소 거리가 들어있음
    // 그걸 쿼리마다 상수 시간으로 확인만 해주면 됨
    
    vector<int> results;
    
    for (int i = 0; i < q; ++i) {
        int power, y, x;
        cin >> power >> y >> x;
        int best = inf;
        
        for (int remain = 0; remain <= t; remain++) {
            best = min(best, dist[y - 1][x - 1][remain]);
        }
        
        int result = (power >= best) ? 1 : 0;
        results.push_back(result);
    }
    
    for (int result : results) {
        cout << result << endl;
    }
    
//    cout << endl;
//    for (int i = 0; i < sero; ++i) {
//        for (int j = 0; j < garo; ++j) {
//            int best = inf;
//            
//            for (int remain = 0; remain <= t; remain++) {
//                best = min(best, dist[i][j][remain]);
//            }
//            cout << best << ' ';
//        }
//        cout << endl;
//    }
    
    return 0;
}

// prov 32646
