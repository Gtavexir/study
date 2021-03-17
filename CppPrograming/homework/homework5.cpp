#include <iostream>

using namespace std;

int main() {
    int k;
    cin >> k;
    for(int i = 0; i < k; i++) {
        if(i <= k / 2) {
            for(int j = 0; j < k; j++) {
                if(i + j < k / 2 || i + j > k / 2 + i * 2)
                    cout << '*';
                else 
                    cout << '+';
            }
            cout << '\n';
            continue;
        }
        for(int j = 0; j < k; j++) {
            if((j <= k / 2 && i - j > k / 2) || (j > k / 2 && i + j >= k + k / 2))
                cout << '*';
            else
                cout << '+';
        }
        cout << '\n';
    }

    return 0;
}