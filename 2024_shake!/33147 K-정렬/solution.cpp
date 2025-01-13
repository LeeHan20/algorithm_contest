#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
#include "set"
#include "cmath"
#include "numeric"
#define endl '\n'
using namespace::std;

int n, k;
vector<int> series;



int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> k;
    series.resize(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> series[i];
    }
    
    int group = gcd(n, k);
    
    for (int i = 0; i < group; ++i) {
        int focus_idx = i;
        
        priority_queue<int> idx;
        priority_queue<int> value;
        
        while (true) {
            idx.push(focus_idx);
            value.push(series[focus_idx]);
            
            focus_idx = (focus_idx + k) % n;
            
            if (focus_idx == i) {
                break;
            }
        }
        
        while (!idx.empty()) {
            if (idx.top() != value.top()) {
                cout << "NO" << endl;
                return 0;
            }
            idx.pop();
            value.pop();
        }
        
    }
    
    cout << "YES" << endl;
    
    return 0;
}

