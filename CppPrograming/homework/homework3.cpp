#include <iostream>

using namespace std;

int main() {
    int k;
    cin >> k;
    for(int i = 0; i < k; i++) {
        if(i <= k / 2) {
            for(int j = 0; j < k; j++) {
                if(j < i || j >= k - i)
                    cout << '-';
                else {
                    if(i % 2 == 0)
                        cout << (j % 2 == 0 ? '*' : '+');
                    else
                        cout << (j % 2 == 1 ? '*' : '+');
                }
            }
            cout << '\n';
            continue;
        }
        for(int j = 0; j < k; j++) {
            if(j < k - i - 1 || j > i)
                cout << '-';
            else {
                if(i % 2 == 0)
                    cout << (j % 2 == 0 ? '*' : '+');
                else
                    cout << (j % 2 == 1 ? '*' : '+');
            }
        }
        cout << '\n';
    }

    return 0;
}