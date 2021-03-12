#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<vector<int>> map(n, vector<int> (n, 0));
    vector<int> answer;
    string input;
    for(int i = 0; i < n; i++) {
        cin >> input;
        for(int j = 0; j < n; j++) {
            map[i][j] = input[j] - '0';
        }
    }

    queue<pair<int, int>> que;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(map[i][j] == 0) continue;
            cnt = 0;
            que.push(make_pair(i, j));
            map[i][j] = 0;
            cnt++;
            while(!que.empty()) {
                int x = que.front().first;
                int y = que.front().second;
                que.pop();
                if(x - 1 > -1 && map[x - 1][y] == 1) {
                    map[x - 1][y] = 0;
                    que.push(make_pair(x - 1, y));
                    cnt++;
                }
                if(x + 1 < n && map[x +1][y] == 1) {
                    map[x + 1][y] = 0;
                    que.push(make_pair(x + 1, y));
                    cnt++;
                }
                if(y - 1 > -1 && map[x][y - 1] == 1) {
                    map[x][y - 1] = 0;
                    que.push(make_pair(x, y - 1));
                    cnt++;
                }
                if(y + 1 < n && map[x][y + 1] == 1) {
                    map[x][y + 1] = 0;
                    que.push(make_pair(x, y + 1));
                    cnt++;
                }
            }
            answer.push_back(cnt);
        }
    }
    sort(answer.begin(), answer.end());
    cout << answer.size() << '\n';
    for(int i = 0; i < answer.size(); i++)
        cout << answer[i] << '\n';
        
    return 0;
}