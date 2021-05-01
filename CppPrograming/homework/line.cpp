#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    pair<int, int> l[2][2];
    for(int i = 0; i < 2; i++)
        cin >> l[i][0].first >> l[i][0].second >> l[i][1].first >> l[i][1].second;

    int a1, a2, b, x, y1, y2;
    if(l[0][0].first == l[0][1].first) {
        x = l[0][0].first;
        y1 = min(l[0][0].second, l[0][1].second);
        y2 = max(l[0][0].second, l[0][1].second);
        b = l[1][0].second;
        a1 = min(l[1][0].first, l[1][1].first);
        a2 = max(l[1][0].first, l[1][1].first);
    }
    else {
        b = l[0][0].second;
        a1 = min(l[0][0].first, l[0][1].first);
        a2 = max(l[0][0].first, l[0][1].first);
        x = l[1][0].first;
        y1 = min(l[1][0].second, l[1][1].second);
        y2 = max(l[1][0].second, l[1][1].second);
    }

    if(b >= y1 && b <= y2 && (x == a1 || x == a2))
        cout << 2 << endl;
    else if(x >= a1 && x <= a2 && (b == y1 || b == y2))
        cout << 2 << endl;
    else if(b >= y1 && b <= y2 && x >= a1 && x <= a2)
        cout << 1 << endl;
    else
        cout << 0 << endl;

    return 0;
}