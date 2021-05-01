#include <iostream>

using namespace std;

int main() {
    pair<int, int> axis[101];
    int n;

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> axis[i].first >> axis[i].second;

    axis[n] = axis[0];

    int answer1 = 0;
    int answer2 = 0;

    for(int i = 0; i < n; i++)
        answer1 += (axis[i].first + axis[i + 1].first) * (axis[i + 1].second - axis[i].second);
    
    answer2 = answer1 < 0 ? -1 : 1;

    if(answer1 < 0) answer1 = -answer1;

    cout << answer1 << ' ' << answer2 << endl;

    return 0;
}