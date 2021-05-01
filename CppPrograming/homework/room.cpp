#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, room[101][101], dirx[] = {-1, 1, 0, 0}, diry[] = {0, 0, -1, 1};
    vector<int> ans;
    queue<pair<int, int>> que;
    string st;
    cin >> m >> n;
    for(int i = 0; i < n; i++) {
        cin >> st;
        for(int j = 0; j < m; j++)
            room[i][j] = st[j] == '+' ? 1 : 0;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(room[i][j] == 1)
                continue;
            int cnt = 1;
            que.push(make_pair(i, j));
            room[i][j] = 1;
            while(!que.empty()) {
                int x = que.front().first;
                int y = que.front().second;
                que.pop();
                for(int k = 0; k < 4; k++) {
                    if(room[x + dirx[k]][y + diry[k]] == 0) {
                        room[x + dirx[k]][y + diry[k]] = 1;
                        que.push(make_pair(x + dirx[k], y + diry[k]));
                        cnt += 1;
                    }
                }
            }
            ans.push_back(cnt);
        }
    }

    sort(ans.begin(), ans.end(), greater<>());
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    return 0;
}