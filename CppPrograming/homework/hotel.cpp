#include <iostream>

using namespace std;

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    if(n % h != 0)
        cout << 100 * (n % h) + (n / h) + 1 << endl;
    else
        cout << 100 * h  + (n / h) << endl;
    return 0;
}