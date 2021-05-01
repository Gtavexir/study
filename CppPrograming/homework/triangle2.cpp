#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    pair<int, int> axis[3];
    int arr[3] = {0};
    int cnt = 0;
    for(int i = 0; i < 3; i++)
        cin >> axis[i].first >> axis[i].second;


    pair<float, float> slope;
    if(axis[1].first == axis[0].first && axis[1].first == axis[2].first) {
        cout << 0 << endl;
        return 0;
    }
    if(axis[1].first != axis[0].first && axis[1].first != axis[2].first && axis[0].first != axis[2].first) {
        slope = make_pair((float)(axis[1].second - axis[0].second) / (float)(axis[1].first - axis[0].first), (float)(axis[2].second - axis[0].second) / (float)(axis[2].first - axis[0].first));
        if(slope.first == slope.second) {
            cout << 0 << endl;
            return 0;
        }
    }

    for(int i = 0; i < 3; i++)
        for(int j = i + 1; j < 3; j++)
            arr[cnt++] = (axis[i].first - axis[j].first) * (axis[i].first - axis[j].first) + (axis[i].second - axis[j].second) * (axis[i].second - axis[j].second);
    sort(arr, arr + 3);

    if(arr[2] == arr[0] + arr[1])
        cout << 1 << endl;
    else if(arr[2] > arr[0] + arr[1])
        cout << 2 << endl;
    else if(arr[2] < arr[0] + arr[1])
        cout << 3 << endl;

    return 0;
}