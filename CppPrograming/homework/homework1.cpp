#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << a + b << ' ' << a - b << ' ' << abs(a - b) << ' ' << a * b << ' ' << a / b << ' ' << a % b << ' ' << (a > b ? a : b) << ' ' << (a == b ? 1 : 0) << '\n';

    return 0;
}