#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    int radius_cm = min(H, W) * 50;
    cout << radius_cm << endl;
    return 0;
}
