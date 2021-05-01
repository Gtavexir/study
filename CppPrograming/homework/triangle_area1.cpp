#include <iostream>

using namespace std;

int main() {
    pair<int, int> axis[3];
    for(int i = 0; i < 3; i++)
        cin >> axis[i].first >> axis[i].second;
    
    double area = .0;
    area = ((axis[1].first - axis[0].first) * (axis[2].second - axis[0].second) - (axis[2].first - axis[0].first) * (axis[1].second - axis[0].second)) * 0.5;

    int answer = 0;
    int answer2 = 0;
    if(area < 0) {
        answer = -1;
        answer2 = -area * 2;
    }
    else if(area > 0) {
        answer = 1;
        answer2 = area * 2;
    }
    cout << answer2 << ' ' << answer << endl;

    return 0;
}