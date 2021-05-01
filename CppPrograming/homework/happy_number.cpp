#include <iostream>

using namespace std;

int main() {
    bool check[1000000] = {false};
    int n;
    cin >> n;
    while(1) {
        int t = n;
        n = 0;
        while(t != 0) {
            n += (t % 10) * (t % 10);
            t /= 10;
        }
        if(check[n] == true) {
            cout << "UNHAPPY" << endl;
            break;
        }
        check[n] = true;
        if(n == 1) {
            cout << "HAPPY" << endl;
            break;
        }
    }

    return 0;
}