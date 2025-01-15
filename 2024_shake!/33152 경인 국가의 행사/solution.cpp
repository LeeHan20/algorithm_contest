#include "iostream"
#include "vector"
#include "algorithm"
#define endl '\n'
using namespace::std;

typedef unsigned long long ll;
int n;
vector<int> series;

bool attempt_draw(int excluded_idx) {
    vector<pair<int, int>> cities;
    ll x_vote = 0, y_vote = 0;

    for (int i = 0; i < n; ++i) {
        if (i == excluded_idx) continue;
        cities.push_back({series[i], i});
    }
    sort(cities.begin(), cities.end());
    
    vector<int> x_citizens(n), y_citizens(n);
    int excluded_population = series[excluded_idx];
    int y_votes = excluded_population / 2;
    int x_votes = excluded_population - y_votes;
    y_vote += y_votes;
    x_vote += x_votes;
    y_citizens[excluded_idx] = y_votes;
    x_citizens[excluded_idx] = x_votes;

    int y_needed_wins = (n - 1) / 2 + 1;
    int y_wins = 0;
    for (int i = 0; i < (int)cities.size(); ++i) {
        int population = cities[i].first;
        int idx = cities[i].second;

        if (y_wins < y_needed_wins) {
            int y = population / 2 + 1;
            int x = population - y;
            y_vote += y;
            x_vote += x;
            y_citizens[idx] = y;
            x_citizens[idx] = x;
            y_wins++;
        } else {
            x_vote += population;
            x_citizens[idx] = population;
            y_citizens[idx] = 0;
        }
    }

    if (x_vote > y_vote) {
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i) {
            cout << x_citizens[i] << ' ';
        }
        cout << endl;
        for (int i = 0; i < n; ++i) {
            cout << y_citizens[i] << ' ';
        }
        cout << endl;
        return true;
    }

    return false;
}

void solve() {
    cin >> n;
    series.resize(n);

    ll x_vote = 0, y_vote = 0;
    vector<pair<int, int>> cities;

    for (int i = 0; i < n; ++i) {
        cin >> series[i];
        cities.push_back({series[i], i});
    }
    sort(cities.begin(), cities.end());

    vector<int> x_citizens(n), y_citizens(n);
    int y_needed_wins = n / 2 + 1;
    int y_wins = 0;

    for (int i = 0; i < n; ++i) {
        int population = cities[i].first;
        int idx = cities[i].second;

        if (y_wins < y_needed_wins) {
            int y = population / 2 + 1;
            int x = population - y;
            y_vote += y;
            x_vote += x;
            y_citizens[idx] = y;
            x_citizens[idx] = x;
            y_wins++;
        } else {
            x_vote += population;
            x_citizens[idx] = population;
            y_citizens[idx] = 0;
        }
    }

    if (x_vote > y_vote) {
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i) {
            cout << x_citizens[i] << ' ';
        }
        cout << endl;
        for (int i = 0; i < n; ++i) {
            cout << y_citizens[i] << ' ';
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (series[i] % 2 == 0 && attempt_draw(i)) {
            return;
        }
    }

    cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        solve();
    }

    return 0;
}
