#include <iostream>

using namespace std;

int main() {
    int need_time[26] = {3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10};
    int answer = 0;
    string st;
    cin >> st;
    for(int i = 0; i < st.size(); i++)
        answer += need_time[st[i] - 'A'];
    cout << answer;
}