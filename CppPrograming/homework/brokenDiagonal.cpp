#include <iostream>

using namespace std;

int main() {
    long long n, matrix[101][101] = {}, ans = -1;
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> matrix[i][j];
    for(int x = 0; x < n ; x++) {
        long long sum, i, j;
        sum = 0; i = 0; j = x;
        for(int y = 0; y < n; y++) {
            sum += matrix[i][j];
            i = i < n - 1 ? i + 1 : 0;
            j = j < n - 1 ? j + 1 : 0;
        }

        ans = max(ans, sum);


        sum = 0; i = n - 1; j = x;
        for(int y = 0; y < n; y++) {
            sum += matrix[i][j];
            i = i > 0 ? i - 1 : n - 1;
            j = j < n - 1 ? j + 1 : 0;
        }
        ans = max(ans, sum);
    }
    cout << ans << '\n';
    return 0;
}