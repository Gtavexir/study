#include <iostream>

using namespace std;

int main() {
    int matrix[101][101] = {0}, matrix1[101][101] = {0}, matrix2[101][101] = {0};
    int n, m, k;

    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> matrix1[i][j];
    
    for(int i = 0; i < m; i++)
        for(int j = 0; j < k; j++)
            cin >> matrix2[i][j];
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            for(int ii = 0; ii < m; ii++)
                matrix[i][j] += matrix1[i][ii] * matrix2[ii][j];
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}