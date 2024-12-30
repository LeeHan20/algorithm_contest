#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;

void test_case() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;
    
    vector<pair<int, int>> people(N);
    for (int i = 0; i < N; ++i) {
        cin >> people[i].first;  // 작업 유형 (1 또는 2)
    }
    for (int i = 0; i < N; ++i) {
        cin >> people[i].second; // 능률
    }
    
    // 해시맵을 이용하여 조건을 만족하는 구간을 카운팅
    unordered_map<int, unordered_map<long long, int>> prefix_map;
    prefix_map[0][0] = 1; // 초기 상태 (balance=0, efficiency_diff=0)
    
    int balance = 0;
    long long efficiency_sum1 = 0;
    long long efficiency_sum2 = 0;
    int result = 0;

    for (int i = 0; i < N; ++i) {
        if (people[i].first == 1) {
            balance++;
            efficiency_sum1 += people[i].second;
        } else {
            balance--;
            efficiency_sum2 += people[i].second;
        }
        
        long long efficiency_diff = efficiency_sum1 - efficiency_sum2;

        if (prefix_map.find(balance) != prefix_map.end()) {
            auto& inner_map = prefix_map[balance];
            for (auto& [prev_diff, count] : inner_map) {
                if (abs(efficiency_diff - prev_diff) <= K) {
                    result += count;
                    
                }
            }
        }

        // 현재 balance와 efficiency_diff를 prefix_map에 기록
        prefix_map[balance][efficiency_diff]++;
    }

    cout << result << "\n";
}



int main() {
    int test;
    cin >> test;
    for (int i = 0; i < test; ++i) {
        test_case();
    }
    return 0;
}
