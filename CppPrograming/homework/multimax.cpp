#include <iostream>

using namespace std;

int main() {
    int n, card[10001] = {};
    int dy[2][10001] = {};
    pair<int, int> dy_0, dy_1;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> card[i];
        if(i == 0) {
            dy_0 = make_pair(card[i], card[i]);
            dy[0][i] = -0xfffffff;
            dy[1][i] = -0xfffffff;
            continue;
        }
        if(i == 1) {
            dy[0][i] = max(dy_0.first * card[i], dy_0.first * card[i]);
            dy_0.first = max(dy_0.first, card[i]);
            dy_0.second = min(dy_0.second, card[i]);
            dy_1 = make_pair(dy[0][i], dy[0][i]);
            dy[1][i] = -0xfffffff;
            continue;
        }
        dy[0][i] = max(dy_0.first * card[i], dy_0.second * card[i]);
        dy[0][i] = max(dy[0][i], dy[0][i - 1]);
        dy_0.first = max(dy_0.first, card[i]);
        dy_0.second = min(dy_0.second, card[i]);

        dy[1][i] = max(dy_1.first * card[i], dy_1.second * card[i]);
        dy[1][i] = max(dy[1][i], dy[1][i - 1]);
        dy_1.first = max(dy_1.first, dy[0][i]);
        dy_1.second = min(dy_1.second, min(dy_0.first * card[i], dy_0.second * card[i]));
    }

    cout << max(dy[1][n - 1], dy[0][n - 1]) << '\n';
    return 0;
}