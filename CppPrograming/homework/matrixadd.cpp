#include <iostream>
using namespace std;

int main() {
    int n, m;
    int matrix1[101][101], matrix2[101][101];
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> matrix1[i][j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> matrix2[i][j];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            matrix1[i][j] += matrix2[i][j];
            cout << matrix1[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}