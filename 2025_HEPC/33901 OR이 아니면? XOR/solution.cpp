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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    int K;
    cin >> N >> M >> K;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int MAXV = 1 << 17;
    vector<int> freq(MAXV, 0);

    ll answer = 0;
    for (int j = 0; j < N; ++j) {
        int need = A[j] ^ K;
        if (need < MAXV) {
            answer += freq[need];
        }
        freq[A[j]]++;
        if (j >= M) {
            freq[A[j - M]]--;
        }
    }

    cout << answer << endl;
    return 0;
}
