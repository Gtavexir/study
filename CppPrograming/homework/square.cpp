#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    pair<int, int> square[2], dot;
    for(int i = 0; i < 2; i++)
        cin >> square[i].first >> square[i].second;
    cin >> dot.first >> dot.second;
    int answer[2] = {0xfffffff, 0xfffffff};

    if(square[0].first <= dot.first && square[1].first >= dot.first && square[0].second <= dot.second && square[1].second >= dot.second) {
        cout << 0 << ' ' << 0 << endl;
        return 0;
    }
    for(int i = square[0].first; i <= square[1].first; i++) {
        answer[0] = min(answer[0], (int)pow(dot.first - i, 2) + (int)pow(dot.second - square[0].second, 2));
        answer[1] = min(answer[1], abs(dot.first - i) + abs(dot.second - square[0].second));
    }
    for(int i = square[0].second; i <= square[1].second; i++) {
        answer[0] = min(answer[0], (int)pow(dot.first - square[1].first, 2) + (int)pow(dot.second - i, 2));
        answer[1] = min(answer[1], abs(dot.first - square[1].first) + abs(dot.second - i));
    }
    for(int i = square[0].first; i <= square[1].first; i++) {
        answer[0] = min(answer[0], (int)pow(dot.first - i, 2) + (int)pow(dot.second - square[1].second, 2));
        answer[1] = min(answer[1], abs(dot.first - i) + abs(dot.second - square[1].second));
    }
    for(int i = square[0].second; i <= square[1].second; i++) {
        answer[0] = min(answer[0], (int)pow(dot.first - square[0].first, 2) + (int)pow(dot.second - i, 2));
        answer[1] = min(answer[1], abs(dot.first - square[0].first) + abs(dot.second - i));
    }
    cout << answer[0] << ' ' << answer[1] << endl;
    return 0;   
}