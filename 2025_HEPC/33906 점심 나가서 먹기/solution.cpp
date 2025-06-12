#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <set>
#define endl '\n'
#define space ' '
#define INF 2147483647
#define MAX 2501
using namespace std;
typedef long long ll;
const long long LLONGMAX = 1LL << 60;
//typedef __int128 ll;


int n, m;
int restaurant, cafe;
vector<vector<pair<int,int>>> grid;

vector<int> dijkstra(int start) {
    vector<int> weights(n+1, INF);
    weights[start] = 0;
    priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> pq;
    pq.push({0, start});
    // (weight, node)

    while (!pq.empty()) {
        auto [weight, node] = pq.top();
        pq.pop();
        if (weight > weights[node]) continue;
        for (auto &next : grid[node]) {
            int nweight = weight + next.first;
            int nnode   = next.second;
            if (nweight < weights[nnode]) {
                weights[nnode] = nweight;
                pq.push({nweight, nnode});
            }
        }
    }
    return weights;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    grid.resize(n+1);

    vector<ll> x(n+1), y(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> y[i];
    }

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        grid[a].push_back({c, b});
        grid[b].push_back({c, a});
    }

    auto dist1 = dijkstra(1);

    ll bestR = LLONGMAX;
    for (int i = 1; i <= n; ++i) {
        if (x[i] > 0 && dist1[i] < INF && x[i] < bestR) {
            bestR = x[i];
            restaurant = i;
        }
    }
    ll bestC = LLONGMAX;
    for (int i = 1; i <= n; ++i) {
        if (y[i] > 0 && dist1[i] < INF && y[i] < bestC) {
            bestC = y[i];
            cafe = i;
        }
    }

    auto distR = dijkstra(restaurant);

    ll result = 0;
    result += dist1[restaurant];
    result += distR[cafe];
    result += dist1[cafe];

    cout << result << endl;
    return 0;
}
