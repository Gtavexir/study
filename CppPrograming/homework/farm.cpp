#include <iostream>

using namespace std;

int main() {
    int a, b, n, w;
    cin >> a >> b >> n >> w;
    pair<int, int> answer;
    for(int i = 1; i < n; i++) {
        if(a * i + (n - i) * b == w) {
            if(answer.first == 0) {
                answer.first = i;
                answer.second = n - i;
            }
            else {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    if(answer.first == 0)
        cout << -1 << endl;
    else
        cout << answer.first << ' ' << answer.second << endl;

    return 0;
}