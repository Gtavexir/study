#include <iostream>

using namespace std;

int main() {
    int k, cnt = 1;
    cin >> k;
    for(int i = 0; i < k; i++) {
        for(int j = 0; j <= i; j++)
            cout << cnt++ << ' ';
        cout << '\n';
    }

    return 0;
}