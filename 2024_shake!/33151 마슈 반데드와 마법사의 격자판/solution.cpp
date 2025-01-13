#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
#define endl '\n'
using namespace::std;

int n, k;
vector<vector<int>> map;
bool possible_flag = true;

bool is_jjaksu(int x) {
    if (x % 2 == 0) {
        return true;
    }
    else {
        return false;
    }
}

void make_map_one(int x) {
    if (is_jjaksu(x)) {
        for (int i = 0; i < n; ++i) {
            for (int j = i % 2; j < n; j += 2) {
                map[i][j] += 1;
                k--;
                
            }
        }
    }
    else {
        for (int i = 0; i < n; ++i) {
            for (int j = (i + 1) % 2; j < n; j += 2) {
                map[i][j] += 1;
                k--;
                
            }
        }
    }
    
    return;
}

void make_map_two(int x) {
    
    while (true) {
        if (is_jjaksu(x)) {
            for (int i = 0; i < n; ++i) {
                for (int j = i % 2; j < n; j += 2) {
                    if (k == 0) {
                        return;
                    }
                    map[i][j] += 2;
                    k -= 2;
                    
                }
            }
        }
        else {
            for (int i = 0; i < n; ++i) {
                for (int j = (i + 1) % 2; j < n; j += 2) {
                    if (k == 0) {
                        return;
                    }
                    map[i][j] += 2;
                    k -= 2;
                    
                }
            }
        }
        x++;
    }
    
    return;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> k;
    
    if ((n * n) / 2 > k) {
        cout << -1 << endl;
        return 0;
    }
    
    map.resize(n, vector<int>(n, 0));
    
    if (!is_jjaksu(n) && !is_jjaksu(k)) {
        make_map_one(0);
        make_map_two(1);
    }
    else if (!is_jjaksu(n) && is_jjaksu(k)) {
        make_map_one(1);
        make_map_two(0);
    }
    else if (is_jjaksu(n) && !is_jjaksu(k)) {
        cout << -1 << endl;
        return 0;
    }
    else if (is_jjaksu(n) && is_jjaksu(k)) {
        make_map_one(1);
        make_map_two(0);
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << map[i][j] << ' ';
        }
        cout << endl;
    }
    
    return 0;
}

//shake! E번

