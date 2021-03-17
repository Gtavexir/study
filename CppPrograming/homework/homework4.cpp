#include <iostream>

using namespace std;

int main() {
    int k;
    cin >> k;
    for(int i = 0; i < k; i++) {
        if(i == k / 2) {
            for(int j = 0; j < k; j++)
                cout << (j == k / 2 ? 'O' : '+');
            cout << '\n';
            continue;
        }
        for(int j = 0; j < k; j++) {
            if(j == k / 2)
                cout << 'I';
            else if(i + j == k - 1)
                cout << '*';
            else
                cout << '.';
        }
        cout << '\n';
    }

    return 0;
}